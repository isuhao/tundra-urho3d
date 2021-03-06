// For conditions of distribution and use, see copyright notice in LICENSE

#include "StableHeaders.h"
#include "ParticleSystem.h"
#include "GraphicsWorld.h"
#include "AttributeMetadata.h"
#include "Placeable.h"
#include "UrhoRenderer.h"
#include "Scene/Scene.h"
#include "LoggingFunctions.h"
#include "IParticleAsset.h"

#include <Urho3D/Scene/Node.h>
#include <Urho3D/Scene/Scene.h>
#include <Urho3D/Graphics/ParticleEmitter.h>
#include <Urho3D/Graphics/ParticleEffect.h>
#include <Urho3D/Graphics/GraphicsDefs.h>
#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/Graphics/Material.h>
#include <Urho3D/Graphics/Technique.h>

namespace Tundra
{

ParticleSystem::ParticleSystem(Urho3D::Context* context, Scene* scene) :
    IComponent(context, scene),
    INIT_ATTRIBUTE_VALUE(particleRef, "Particle Ref", AssetReference("", "OgreParticle")),
    INIT_ATTRIBUTE_VALUE(castShadows, "Cast shadows", false),
    INIT_ATTRIBUTE_VALUE(enabled, "Enabled", true),
    INIT_ATTRIBUTE_VALUE(renderingDistance, "Rendering distance", 0.0f)
{
    if (scene)
        world_ = scene->Subsystem<GraphicsWorld>();

    static AttributeMetadata drawDistanceData("", "0", "10000");
    renderingDistance.SetMetadata(&drawDistanceData);

    ParentEntitySet.Connect(this, &ParticleSystem::UpdateSignals);
}

ParticleSystem::~ParticleSystem()
{
    if (world_.Expired())
    {
        if (particleEmitters_.Size() > 0)
            LogError("ParticleSystem: World has expired, skipping uninitialization!");
        return;
    }

    DetachParticleSystem();

    if (particleEmitters_.Size() > 0)
    {
        adjustmentNode_->Remove();
        adjustmentNode_.Reset();
    }
}

void ParticleSystem::UpdateSignals()
{
    if (!ViewEnabled())
        return;

    Entity* parent = ParentEntity();
    if (!parent)
        return;

    particleRefListener_ = new AssetRefListener();

    parent->ComponentAdded.Connect(this, &ParticleSystem::OnComponentStructureChanged);
    parent->ComponentRemoved.Connect(this, &ParticleSystem::OnComponentStructureChanged);

    if (parent->ParentScene())
        world_ = parent->ParentScene()->Subsystem<GraphicsWorld>();

    if (world_ && !adjustmentNode_)
    {
        Urho3D::Scene* urhoScene = world_->UrhoScene();
        adjustmentNode_ = urhoScene->CreateChild("AdjustmentNode");
        
        // Make the entity & component links for identifying raycasts
        ///\todo Is this needed for particle effects?
        adjustmentNode_->SetVar(GraphicsWorld::entityLink, Variant(WeakPtr<RefCounted>(parent)));
        adjustmentNode_->SetVar(GraphicsWorld::componentLink, Variant(WeakPtr<RefCounted>(this)));

        // Connect ref listeners
        particleRefListener_->Loaded.Connect(this, &ParticleSystem::OnParticleAssetLoaded);
    }

    // Make sure we attach to the Placeable if exists.
    AttachParticleSystem();
}

void ParticleSystem::OnComponentStructureChanged(IComponent*, AttributeChange::Type)
{
    // No-op if attached to the same placeable already
    if (placeable_ == parentEntity->Component<Placeable>())
        return;

    AttachParticleSystem(); // Try to attach if placeable is present, otherwise detach
}

void ParticleSystem::AttributesChanged()
{
    if (!ViewEnabled() || !adjustmentNode_)
        return;

    if (particleRef.ValueChanged() && particleRefListener_)
        particleRefListener_->HandleAssetRefChange(&particleRef);
    if (castShadows.ValueChanged())
        foreach (Urho3D::ParticleEmitter* emitter, particleEmitters_)
            emitter->SetCastShadows(castShadows.Get());
    if (enabled.ValueChanged())
        foreach (Urho3D::ParticleEmitter* emitter, particleEmitters_)
            emitter->SetEnabled(enabled.Get());
    if (renderingDistance.ValueChanged())
        foreach (Urho3D::ParticleEmitter* emitter, particleEmitters_)
            emitter->SetDrawDistance(renderingDistance.Get());
}

void ParticleSystem::OnParticleAssetLoaded(AssetPtr asset)
{
    IParticleAsset *particleAsset = dynamic_cast<IParticleAsset*>(asset.Get());

    foreach (SharedPtr<Urho3D::ParticleEffect> effect, particleAsset->particleEffects_)
    {
        ///\todo Particles are now facing away from camera (or culled wrong side), so need to force fix culling.
        ///\todo Proper fix for this situation
        if (!effect->GetMaterial())
        {
            LogWarning("Material of particle effect was null, skipping");
            continue;
        }

        effect->GetMaterial()->SetCullMode(Urho3D::CULL_NONE);

        StringHash alphaPass = StringHash("alpha");
        ///\todo Need to force use of vertex color technique for colored particles. Remove once OgreMaterialProcessor can handle this.
        if (effect->GetColorFrames().Size() > 0 && effect->GetMaterial()->GetTechnique(0) &&
            effect->GetMaterial()->GetTechnique(0)->GetPass(alphaPass))
        {
            if (effect->GetMaterial()->GetTechnique(0)->GetPass(alphaPass)->GetBlendMode() == Urho3D::BLEND_ADD)
                effect->GetMaterial()->SetTechnique(0, GetSubsystem<Urho3D::ResourceCache>()->GetResource<Urho3D::Technique>("Techniques/DiffVColAdd.xml"));
            else
                effect->GetMaterial()->SetTechnique(0, GetSubsystem<Urho3D::ResourceCache>()->GetResource<Urho3D::Technique>("Techniques/DiffVColUnlitAlpha.xml"));
        }

        Urho3D::ParticleEmitter* particleEmitter = adjustmentNode_->CreateComponent<Urho3D::ParticleEmitter>();
        particleEmitter->SetEnabled(false);
        particleEmitter->SetEffect(effect);
        particleEmitters_.Push(particleEmitter);

        AttachParticleSystem();
    }
}

void ParticleSystem::AttachParticleSystem()
{
    if (!adjustmentNode_ || world_.Expired())
        return;

    // Detach first, in case the original placeable no longer exists
    DetachParticleSystem();

    Entity *entity = ParentEntity();
    if (!entity)
        return;
    placeable_ = entity->Component<Placeable>();
    if (!placeable_)
        return;

    Urho3D::Node* placeableNode = placeable_->UrhoSceneNode();
    if (!placeableNode)
    {
        LogError("Can not attach ParticleSystem: placeable does not have an Urho3D scene node");
        return;
    }
  
    adjustmentNode_->SetParent(placeableNode);
    adjustmentNode_->SetPosition(Urho3D::Vector3(0, 0, 0));

    foreach (Urho3D::ParticleEmitter* emitter, particleEmitters_)
        emitter->SetEnabled(enabled.Get());
}

void ParticleSystem::DetachParticleSystem()
{
     if (!adjustmentNode_ || world_.Expired())
        return;

    if (placeable_)
    {
        Urho3D::Scene* urhoScene = world_->UrhoScene();
        // When removed from the placeable, attach to scene root to avoid being removed from scene
        adjustmentNode_->SetParent(urhoScene);
        placeable_.Reset();

        foreach (Urho3D::ParticleEmitter* emitter, particleEmitters_)
            emitter->SetEnabled(false); // We should not render while detached
    }
}

void ParticleSystem::SoftStopParticleSystem()
{
    LogError("ParticleSystem::SoftStopParticleSystem: not implemented");
}

}
