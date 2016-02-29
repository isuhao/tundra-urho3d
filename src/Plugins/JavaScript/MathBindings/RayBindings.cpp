// For conditions of distribution and use, see copyright notice in LICENSE
// This file has been autogenerated with BindingsGenerator

#include "StableHeaders.h"
#include "CoreTypes.h"
#include "JavaScriptInstance.h"
#include "LoggingFunctions.h"
#include "Geometry/Ray.h"

#ifdef _MSC_VER
#pragma warning(disable: 4800)
#endif

#include "Math/float3.h"
#include "Geometry/Line.h"
#include "Geometry/LineSegment.h"
#include "Math/float3x3.h"
#include "Math/float3x4.h"
#include "Math/float4x4.h"
#include "Math/Quat.h"
#include "Geometry/Sphere.h"
#include "Geometry/Capsule.h"
#include "Geometry/Triangle.h"
#include "Geometry/Plane.h"
#include "Geometry/AABB.h"
#include "Geometry/OBB.h"
#include "Geometry/Frustum.h"
#include "Geometry/Circle.h"

using namespace std;

namespace JSBindings
{

extern const char* float3_ID;
extern const char* Line_ID;
extern const char* LineSegment_ID;
extern const char* float3x3_ID;
extern const char* float3x4_ID;
extern const char* float4x4_ID;
extern const char* Quat_ID;
extern const char* Sphere_ID;
extern const char* Capsule_ID;
extern const char* Triangle_ID;
extern const char* Plane_ID;
extern const char* AABB_ID;
extern const char* OBB_ID;
extern const char* Frustum_ID;
extern const char* Circle_ID;

duk_ret_t float3_Finalizer(duk_context* ctx);
duk_ret_t Line_Finalizer(duk_context* ctx);
duk_ret_t LineSegment_Finalizer(duk_context* ctx);
duk_ret_t float3x3_Finalizer(duk_context* ctx);
duk_ret_t float3x4_Finalizer(duk_context* ctx);
duk_ret_t float4x4_Finalizer(duk_context* ctx);
duk_ret_t Quat_Finalizer(duk_context* ctx);
duk_ret_t Sphere_Finalizer(duk_context* ctx);
duk_ret_t Capsule_Finalizer(duk_context* ctx);
duk_ret_t Triangle_Finalizer(duk_context* ctx);
duk_ret_t Plane_Finalizer(duk_context* ctx);
duk_ret_t AABB_Finalizer(duk_context* ctx);
duk_ret_t OBB_Finalizer(duk_context* ctx);
duk_ret_t Frustum_Finalizer(duk_context* ctx);
duk_ret_t Circle_Finalizer(duk_context* ctx);

const char* Ray_ID = "Ray";

duk_ret_t Ray_Finalizer(duk_context* ctx)
{
    Ray* obj = GetValueObject<Ray>(ctx, 0, Ray_ID);
    if (obj)
    {
        delete obj;
        SetValueObject(ctx, 0, 0, Ray_ID);
    }
    return 0;
}

static duk_ret_t Ray_Ctor(duk_context* ctx)
{
    Ray* newObj = new Ray();
    PushConstructorResult<Ray>(ctx, newObj, Ray_ID, Ray_Finalizer);
    return 0;
}

static duk_ret_t Ray_Ctor_float3_float3(duk_context* ctx)
{
    float3* pos = GetCheckedValueObject<float3>(ctx, 0, float3_ID);
    float3* dir = GetCheckedValueObject<float3>(ctx, 1, float3_ID);
    Ray* newObj = new Ray(*pos, *dir);
    PushConstructorResult<Ray>(ctx, newObj, Ray_ID, Ray_Finalizer);
    return 0;
}

static duk_ret_t Ray_Ctor_Line(duk_context* ctx)
{
    Line* line = GetCheckedValueObject<Line>(ctx, 0, Line_ID);
    Ray* newObj = new Ray(*line);
    PushConstructorResult<Ray>(ctx, newObj, Ray_ID, Ray_Finalizer);
    return 0;
}

static duk_ret_t Ray_Ctor_LineSegment(duk_context* ctx)
{
    LineSegment* lineSegment = GetCheckedValueObject<LineSegment>(ctx, 0, LineSegment_ID);
    Ray* newObj = new Ray(*lineSegment);
    PushConstructorResult<Ray>(ctx, newObj, Ray_ID, Ray_Finalizer);
    return 0;
}

static duk_ret_t Ray_IsFinite(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    bool ret = thisObj->IsFinite();
    duk_push_boolean(ctx, ret);
    return 1;
}

static duk_ret_t Ray_GetPoint_float(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    float distance = (float)duk_require_number(ctx, 0);
    float3 ret = thisObj->GetPoint(distance);
    PushValueObjectCopy<float3>(ctx, ret, float3_ID, float3_Finalizer);
    return 1;
}

static duk_ret_t Ray_Translate_float3(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    float3* offset = GetCheckedValueObject<float3>(ctx, 0, float3_ID);
    thisObj->Translate(*offset);
    return 0;
}

static duk_ret_t Ray_Transform_float3x3(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    float3x3* transform = GetCheckedValueObject<float3x3>(ctx, 0, float3x3_ID);
    thisObj->Transform(*transform);
    return 0;
}

static duk_ret_t Ray_Transform_float3x4(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    float3x4* transform = GetCheckedValueObject<float3x4>(ctx, 0, float3x4_ID);
    thisObj->Transform(*transform);
    return 0;
}

static duk_ret_t Ray_Transform_float4x4(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    float4x4* transform = GetCheckedValueObject<float4x4>(ctx, 0, float4x4_ID);
    thisObj->Transform(*transform);
    return 0;
}

static duk_ret_t Ray_Transform_Quat(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    Quat* transform = GetCheckedValueObject<Quat>(ctx, 0, Quat_ID);
    thisObj->Transform(*transform);
    return 0;
}

static duk_ret_t Ray_Contains_float3_float(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    float3* point = GetCheckedValueObject<float3>(ctx, 0, float3_ID);
    float distanceThreshold = (float)duk_require_number(ctx, 1);
    bool ret = thisObj->Contains(*point, distanceThreshold);
    duk_push_boolean(ctx, ret);
    return 1;
}

static duk_ret_t Ray_Contains_LineSegment_float(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    LineSegment* lineSegment = GetCheckedValueObject<LineSegment>(ctx, 0, LineSegment_ID);
    float distanceThreshold = (float)duk_require_number(ctx, 1);
    bool ret = thisObj->Contains(*lineSegment, distanceThreshold);
    duk_push_boolean(ctx, ret);
    return 1;
}

static duk_ret_t Ray_Equals_Ray_float(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    Ray* otherRay = GetCheckedValueObject<Ray>(ctx, 0, Ray_ID);
    float epsilon = (float)duk_require_number(ctx, 1);
    bool ret = thisObj->Equals(*otherRay, epsilon);
    duk_push_boolean(ctx, ret);
    return 1;
}

static duk_ret_t Ray_BitEquals_Ray(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    Ray* other = GetCheckedValueObject<Ray>(ctx, 0, Ray_ID);
    bool ret = thisObj->BitEquals(*other);
    duk_push_boolean(ctx, ret);
    return 1;
}

static duk_ret_t Ray_Distance_float3(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    float3* point = GetCheckedValueObject<float3>(ctx, 0, float3_ID);
    float ret = thisObj->Distance(*point);
    duk_push_number(ctx, ret);
    return 1;
}

static duk_ret_t Ray_Distance_float3_float(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    float3* point = GetCheckedValueObject<float3>(ctx, 0, float3_ID);
    float d = (float)duk_require_number(ctx, 1);
    float ret = thisObj->Distance(*point, d);
    duk_push_number(ctx, ret);
    return 1;
}

static duk_ret_t Ray_Distance_Ray(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    Ray* other = GetCheckedValueObject<Ray>(ctx, 0, Ray_ID);
    float ret = thisObj->Distance(*other);
    duk_push_number(ctx, ret);
    return 1;
}

static duk_ret_t Ray_Distance_Ray_float(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    Ray* other = GetCheckedValueObject<Ray>(ctx, 0, Ray_ID);
    float d = (float)duk_require_number(ctx, 1);
    float ret = thisObj->Distance(*other, d);
    duk_push_number(ctx, ret);
    return 1;
}

static duk_ret_t Ray_Distance_Ray_float_float(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    Ray* other = GetCheckedValueObject<Ray>(ctx, 0, Ray_ID);
    float d = (float)duk_require_number(ctx, 1);
    float d2 = (float)duk_require_number(ctx, 2);
    float ret = thisObj->Distance(*other, d, d2);
    duk_push_number(ctx, ret);
    return 1;
}

static duk_ret_t Ray_Distance_Line(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    Line* other = GetCheckedValueObject<Line>(ctx, 0, Line_ID);
    float ret = thisObj->Distance(*other);
    duk_push_number(ctx, ret);
    return 1;
}

static duk_ret_t Ray_Distance_Line_float(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    Line* other = GetCheckedValueObject<Line>(ctx, 0, Line_ID);
    float d = (float)duk_require_number(ctx, 1);
    float ret = thisObj->Distance(*other, d);
    duk_push_number(ctx, ret);
    return 1;
}

static duk_ret_t Ray_Distance_Line_float_float(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    Line* other = GetCheckedValueObject<Line>(ctx, 0, Line_ID);
    float d = (float)duk_require_number(ctx, 1);
    float d2 = (float)duk_require_number(ctx, 2);
    float ret = thisObj->Distance(*other, d, d2);
    duk_push_number(ctx, ret);
    return 1;
}

static duk_ret_t Ray_Distance_LineSegment(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    LineSegment* other = GetCheckedValueObject<LineSegment>(ctx, 0, LineSegment_ID);
    float ret = thisObj->Distance(*other);
    duk_push_number(ctx, ret);
    return 1;
}

static duk_ret_t Ray_Distance_LineSegment_float(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    LineSegment* other = GetCheckedValueObject<LineSegment>(ctx, 0, LineSegment_ID);
    float d = (float)duk_require_number(ctx, 1);
    float ret = thisObj->Distance(*other, d);
    duk_push_number(ctx, ret);
    return 1;
}

static duk_ret_t Ray_Distance_LineSegment_float_float(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    LineSegment* other = GetCheckedValueObject<LineSegment>(ctx, 0, LineSegment_ID);
    float d = (float)duk_require_number(ctx, 1);
    float d2 = (float)duk_require_number(ctx, 2);
    float ret = thisObj->Distance(*other, d, d2);
    duk_push_number(ctx, ret);
    return 1;
}

static duk_ret_t Ray_Distance_Sphere(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    Sphere* sphere = GetCheckedValueObject<Sphere>(ctx, 0, Sphere_ID);
    float ret = thisObj->Distance(*sphere);
    duk_push_number(ctx, ret);
    return 1;
}

static duk_ret_t Ray_Distance_Capsule(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    Capsule* capsule = GetCheckedValueObject<Capsule>(ctx, 0, Capsule_ID);
    float ret = thisObj->Distance(*capsule);
    duk_push_number(ctx, ret);
    return 1;
}

static duk_ret_t Ray_ClosestPoint_float3(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    float3* targetPoint = GetCheckedValueObject<float3>(ctx, 0, float3_ID);
    float3 ret = thisObj->ClosestPoint(*targetPoint);
    PushValueObjectCopy<float3>(ctx, ret, float3_ID, float3_Finalizer);
    return 1;
}

static duk_ret_t Ray_ClosestPoint_float3_float(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    float3* targetPoint = GetCheckedValueObject<float3>(ctx, 0, float3_ID);
    float d = (float)duk_require_number(ctx, 1);
    float3 ret = thisObj->ClosestPoint(*targetPoint, d);
    PushValueObjectCopy<float3>(ctx, ret, float3_ID, float3_Finalizer);
    return 1;
}

static duk_ret_t Ray_ClosestPoint_Ray(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    Ray* other = GetCheckedValueObject<Ray>(ctx, 0, Ray_ID);
    float3 ret = thisObj->ClosestPoint(*other);
    PushValueObjectCopy<float3>(ctx, ret, float3_ID, float3_Finalizer);
    return 1;
}

static duk_ret_t Ray_ClosestPoint_Ray_float(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    Ray* other = GetCheckedValueObject<Ray>(ctx, 0, Ray_ID);
    float d = (float)duk_require_number(ctx, 1);
    float3 ret = thisObj->ClosestPoint(*other, d);
    PushValueObjectCopy<float3>(ctx, ret, float3_ID, float3_Finalizer);
    return 1;
}

static duk_ret_t Ray_ClosestPoint_Ray_float_float(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    Ray* other = GetCheckedValueObject<Ray>(ctx, 0, Ray_ID);
    float d = (float)duk_require_number(ctx, 1);
    float d2 = (float)duk_require_number(ctx, 2);
    float3 ret = thisObj->ClosestPoint(*other, d, d2);
    PushValueObjectCopy<float3>(ctx, ret, float3_ID, float3_Finalizer);
    return 1;
}

static duk_ret_t Ray_ClosestPoint_Line(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    Line* other = GetCheckedValueObject<Line>(ctx, 0, Line_ID);
    float3 ret = thisObj->ClosestPoint(*other);
    PushValueObjectCopy<float3>(ctx, ret, float3_ID, float3_Finalizer);
    return 1;
}

static duk_ret_t Ray_ClosestPoint_Line_float(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    Line* other = GetCheckedValueObject<Line>(ctx, 0, Line_ID);
    float d = (float)duk_require_number(ctx, 1);
    float3 ret = thisObj->ClosestPoint(*other, d);
    PushValueObjectCopy<float3>(ctx, ret, float3_ID, float3_Finalizer);
    return 1;
}

static duk_ret_t Ray_ClosestPoint_Line_float_float(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    Line* other = GetCheckedValueObject<Line>(ctx, 0, Line_ID);
    float d = (float)duk_require_number(ctx, 1);
    float d2 = (float)duk_require_number(ctx, 2);
    float3 ret = thisObj->ClosestPoint(*other, d, d2);
    PushValueObjectCopy<float3>(ctx, ret, float3_ID, float3_Finalizer);
    return 1;
}

static duk_ret_t Ray_ClosestPoint_LineSegment(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    LineSegment* other = GetCheckedValueObject<LineSegment>(ctx, 0, LineSegment_ID);
    float3 ret = thisObj->ClosestPoint(*other);
    PushValueObjectCopy<float3>(ctx, ret, float3_ID, float3_Finalizer);
    return 1;
}

static duk_ret_t Ray_ClosestPoint_LineSegment_float(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    LineSegment* other = GetCheckedValueObject<LineSegment>(ctx, 0, LineSegment_ID);
    float d = (float)duk_require_number(ctx, 1);
    float3 ret = thisObj->ClosestPoint(*other, d);
    PushValueObjectCopy<float3>(ctx, ret, float3_ID, float3_Finalizer);
    return 1;
}

static duk_ret_t Ray_ClosestPoint_LineSegment_float_float(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    LineSegment* other = GetCheckedValueObject<LineSegment>(ctx, 0, LineSegment_ID);
    float d = (float)duk_require_number(ctx, 1);
    float d2 = (float)duk_require_number(ctx, 2);
    float3 ret = thisObj->ClosestPoint(*other, d, d2);
    PushValueObjectCopy<float3>(ctx, ret, float3_ID, float3_Finalizer);
    return 1;
}

static duk_ret_t Ray_Intersects_Triangle(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    Triangle* triangle = GetCheckedValueObject<Triangle>(ctx, 0, Triangle_ID);
    bool ret = thisObj->Intersects(*triangle);
    duk_push_boolean(ctx, ret);
    return 1;
}

static duk_ret_t Ray_Intersects_Plane(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    Plane* plane = GetCheckedValueObject<Plane>(ctx, 0, Plane_ID);
    bool ret = thisObj->Intersects(*plane);
    duk_push_boolean(ctx, ret);
    return 1;
}

static duk_ret_t Ray_Intersects_Sphere(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    Sphere* s = GetCheckedValueObject<Sphere>(ctx, 0, Sphere_ID);
    bool ret = thisObj->Intersects(*s);
    duk_push_boolean(ctx, ret);
    return 1;
}

static duk_ret_t Ray_Intersects_AABB_float_float(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    AABB* aabb = GetCheckedValueObject<AABB>(ctx, 0, AABB_ID);
    float dNear = (float)duk_require_number(ctx, 1);
    float dFar = (float)duk_require_number(ctx, 2);
    bool ret = thisObj->Intersects(*aabb, dNear, dFar);
    duk_push_boolean(ctx, ret);
    return 1;
}

static duk_ret_t Ray_Intersects_AABB(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    AABB* aabb = GetCheckedValueObject<AABB>(ctx, 0, AABB_ID);
    bool ret = thisObj->Intersects(*aabb);
    duk_push_boolean(ctx, ret);
    return 1;
}

static duk_ret_t Ray_Intersects_OBB_float_float(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    OBB* obb = GetCheckedValueObject<OBB>(ctx, 0, OBB_ID);
    float dNear = (float)duk_require_number(ctx, 1);
    float dFar = (float)duk_require_number(ctx, 2);
    bool ret = thisObj->Intersects(*obb, dNear, dFar);
    duk_push_boolean(ctx, ret);
    return 1;
}

static duk_ret_t Ray_Intersects_OBB(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    OBB* obb = GetCheckedValueObject<OBB>(ctx, 0, OBB_ID);
    bool ret = thisObj->Intersects(*obb);
    duk_push_boolean(ctx, ret);
    return 1;
}

static duk_ret_t Ray_Intersects_Capsule(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    Capsule* capsule = GetCheckedValueObject<Capsule>(ctx, 0, Capsule_ID);
    bool ret = thisObj->Intersects(*capsule);
    duk_push_boolean(ctx, ret);
    return 1;
}

static duk_ret_t Ray_Intersects_Frustum(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    Frustum* frustum = GetCheckedValueObject<Frustum>(ctx, 0, Frustum_ID);
    bool ret = thisObj->Intersects(*frustum);
    duk_push_boolean(ctx, ret);
    return 1;
}

static duk_ret_t Ray_IntersectsDisc_Circle(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    Circle* disc = GetCheckedValueObject<Circle>(ctx, 0, Circle_ID);
    bool ret = thisObj->IntersectsDisc(*disc);
    duk_push_boolean(ctx, ret);
    return 1;
}

static duk_ret_t Ray_ToLine(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    Line ret = thisObj->ToLine();
    PushValueObjectCopy<Line>(ctx, ret, Line_ID, Line_Finalizer);
    return 1;
}

static duk_ret_t Ray_ToLineSegment_float(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    float d = (float)duk_require_number(ctx, 0);
    LineSegment ret = thisObj->ToLineSegment(d);
    PushValueObjectCopy<LineSegment>(ctx, ret, LineSegment_ID, LineSegment_Finalizer);
    return 1;
}

static duk_ret_t Ray_ProjectToAxis_float3_float_float(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    float3* direction = GetCheckedValueObject<float3>(ctx, 0, float3_ID);
    float outMin = (float)duk_require_number(ctx, 1);
    float outMax = (float)duk_require_number(ctx, 2);
    thisObj->ProjectToAxis(*direction, outMin, outMax);
    return 0;
}

static duk_ret_t Ray_ToLineSegment_float_float(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    float dStart = (float)duk_require_number(ctx, 0);
    float dEnd = (float)duk_require_number(ctx, 1);
    LineSegment ret = thisObj->ToLineSegment(dStart, dEnd);
    PushValueObjectCopy<LineSegment>(ctx, ret, LineSegment_ID, LineSegment_Finalizer);
    return 1;
}

static duk_ret_t Ray_ToString(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    string ret = thisObj->ToString();
    duk_push_string(ctx, ret.c_str());
    return 1;
}

static duk_ret_t Ray_SerializeToString(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    string ret = thisObj->SerializeToString();
    duk_push_string(ctx, ret.c_str());
    return 1;
}

static duk_ret_t Ray_SerializeToCodeString(duk_context* ctx)
{
    Ray* thisObj = GetThisValueObject<Ray>(ctx, Ray_ID);
    string ret = thisObj->SerializeToCodeString();
    duk_push_string(ctx, ret.c_str());
    return 1;
}

static duk_ret_t Ray_Ctor_Selector(duk_context* ctx)
{
    int numArgs = duk_get_top(ctx);
    if (numArgs == 0)
        return Ray_Ctor(ctx);
    if (numArgs == 2 && GetValueObject<float3>(ctx, 0, float3_ID) && GetValueObject<float3>(ctx, 1, float3_ID))
        return Ray_Ctor_float3_float3(ctx);
    if (numArgs == 1 && GetValueObject<Line>(ctx, 0, Line_ID))
        return Ray_Ctor_Line(ctx);
    if (numArgs == 1 && GetValueObject<LineSegment>(ctx, 0, LineSegment_ID))
        return Ray_Ctor_LineSegment(ctx);
    duk_error(ctx, DUK_ERR_ERROR, "Could not select function overload");
}

static duk_ret_t Ray_Transform_Selector(duk_context* ctx)
{
    int numArgs = duk_get_top(ctx);
    if (numArgs == 1 && GetValueObject<float3x3>(ctx, 0, float3x3_ID))
        return Ray_Transform_float3x3(ctx);
    if (numArgs == 1 && GetValueObject<float3x4>(ctx, 0, float3x4_ID))
        return Ray_Transform_float3x4(ctx);
    if (numArgs == 1 && GetValueObject<float4x4>(ctx, 0, float4x4_ID))
        return Ray_Transform_float4x4(ctx);
    if (numArgs == 1 && GetValueObject<Quat>(ctx, 0, Quat_ID))
        return Ray_Transform_Quat(ctx);
    duk_error(ctx, DUK_ERR_ERROR, "Could not select function overload");
}

static duk_ret_t Ray_Contains_Selector(duk_context* ctx)
{
    int numArgs = duk_get_top(ctx);
    if (numArgs == 2 && GetValueObject<float3>(ctx, 0, float3_ID) && duk_is_number(ctx, 1))
        return Ray_Contains_float3_float(ctx);
    if (numArgs == 2 && GetValueObject<LineSegment>(ctx, 0, LineSegment_ID) && duk_is_number(ctx, 1))
        return Ray_Contains_LineSegment_float(ctx);
    duk_error(ctx, DUK_ERR_ERROR, "Could not select function overload");
}

static duk_ret_t Ray_Distance_Selector(duk_context* ctx)
{
    int numArgs = duk_get_top(ctx);
    if (numArgs == 1 && GetValueObject<float3>(ctx, 0, float3_ID))
        return Ray_Distance_float3(ctx);
    if (numArgs == 2 && GetValueObject<float3>(ctx, 0, float3_ID) && duk_is_number(ctx, 1))
        return Ray_Distance_float3_float(ctx);
    if (numArgs == 1 && GetValueObject<Ray>(ctx, 0, Ray_ID))
        return Ray_Distance_Ray(ctx);
    if (numArgs == 2 && GetValueObject<Ray>(ctx, 0, Ray_ID) && duk_is_number(ctx, 1))
        return Ray_Distance_Ray_float(ctx);
    if (numArgs == 3 && GetValueObject<Ray>(ctx, 0, Ray_ID) && duk_is_number(ctx, 1) && duk_is_number(ctx, 2))
        return Ray_Distance_Ray_float_float(ctx);
    if (numArgs == 1 && GetValueObject<Line>(ctx, 0, Line_ID))
        return Ray_Distance_Line(ctx);
    if (numArgs == 2 && GetValueObject<Line>(ctx, 0, Line_ID) && duk_is_number(ctx, 1))
        return Ray_Distance_Line_float(ctx);
    if (numArgs == 3 && GetValueObject<Line>(ctx, 0, Line_ID) && duk_is_number(ctx, 1) && duk_is_number(ctx, 2))
        return Ray_Distance_Line_float_float(ctx);
    if (numArgs == 1 && GetValueObject<LineSegment>(ctx, 0, LineSegment_ID))
        return Ray_Distance_LineSegment(ctx);
    if (numArgs == 2 && GetValueObject<LineSegment>(ctx, 0, LineSegment_ID) && duk_is_number(ctx, 1))
        return Ray_Distance_LineSegment_float(ctx);
    if (numArgs == 3 && GetValueObject<LineSegment>(ctx, 0, LineSegment_ID) && duk_is_number(ctx, 1) && duk_is_number(ctx, 2))
        return Ray_Distance_LineSegment_float_float(ctx);
    if (numArgs == 1 && GetValueObject<Sphere>(ctx, 0, Sphere_ID))
        return Ray_Distance_Sphere(ctx);
    if (numArgs == 1 && GetValueObject<Capsule>(ctx, 0, Capsule_ID))
        return Ray_Distance_Capsule(ctx);
    duk_error(ctx, DUK_ERR_ERROR, "Could not select function overload");
}

static duk_ret_t Ray_ClosestPoint_Selector(duk_context* ctx)
{
    int numArgs = duk_get_top(ctx);
    if (numArgs == 1 && GetValueObject<float3>(ctx, 0, float3_ID))
        return Ray_ClosestPoint_float3(ctx);
    if (numArgs == 2 && GetValueObject<float3>(ctx, 0, float3_ID) && duk_is_number(ctx, 1))
        return Ray_ClosestPoint_float3_float(ctx);
    if (numArgs == 1 && GetValueObject<Ray>(ctx, 0, Ray_ID))
        return Ray_ClosestPoint_Ray(ctx);
    if (numArgs == 2 && GetValueObject<Ray>(ctx, 0, Ray_ID) && duk_is_number(ctx, 1))
        return Ray_ClosestPoint_Ray_float(ctx);
    if (numArgs == 3 && GetValueObject<Ray>(ctx, 0, Ray_ID) && duk_is_number(ctx, 1) && duk_is_number(ctx, 2))
        return Ray_ClosestPoint_Ray_float_float(ctx);
    if (numArgs == 1 && GetValueObject<Line>(ctx, 0, Line_ID))
        return Ray_ClosestPoint_Line(ctx);
    if (numArgs == 2 && GetValueObject<Line>(ctx, 0, Line_ID) && duk_is_number(ctx, 1))
        return Ray_ClosestPoint_Line_float(ctx);
    if (numArgs == 3 && GetValueObject<Line>(ctx, 0, Line_ID) && duk_is_number(ctx, 1) && duk_is_number(ctx, 2))
        return Ray_ClosestPoint_Line_float_float(ctx);
    if (numArgs == 1 && GetValueObject<LineSegment>(ctx, 0, LineSegment_ID))
        return Ray_ClosestPoint_LineSegment(ctx);
    if (numArgs == 2 && GetValueObject<LineSegment>(ctx, 0, LineSegment_ID) && duk_is_number(ctx, 1))
        return Ray_ClosestPoint_LineSegment_float(ctx);
    if (numArgs == 3 && GetValueObject<LineSegment>(ctx, 0, LineSegment_ID) && duk_is_number(ctx, 1) && duk_is_number(ctx, 2))
        return Ray_ClosestPoint_LineSegment_float_float(ctx);
    duk_error(ctx, DUK_ERR_ERROR, "Could not select function overload");
}

static duk_ret_t Ray_Intersects_Selector(duk_context* ctx)
{
    int numArgs = duk_get_top(ctx);
    if (numArgs == 1 && GetValueObject<Triangle>(ctx, 0, Triangle_ID))
        return Ray_Intersects_Triangle(ctx);
    if (numArgs == 1 && GetValueObject<Plane>(ctx, 0, Plane_ID))
        return Ray_Intersects_Plane(ctx);
    if (numArgs == 1 && GetValueObject<Sphere>(ctx, 0, Sphere_ID))
        return Ray_Intersects_Sphere(ctx);
    if (numArgs == 3 && GetValueObject<AABB>(ctx, 0, AABB_ID) && duk_is_number(ctx, 1) && duk_is_number(ctx, 2))
        return Ray_Intersects_AABB_float_float(ctx);
    if (numArgs == 1 && GetValueObject<AABB>(ctx, 0, AABB_ID))
        return Ray_Intersects_AABB(ctx);
    if (numArgs == 3 && GetValueObject<OBB>(ctx, 0, OBB_ID) && duk_is_number(ctx, 1) && duk_is_number(ctx, 2))
        return Ray_Intersects_OBB_float_float(ctx);
    if (numArgs == 1 && GetValueObject<OBB>(ctx, 0, OBB_ID))
        return Ray_Intersects_OBB(ctx);
    if (numArgs == 1 && GetValueObject<Capsule>(ctx, 0, Capsule_ID))
        return Ray_Intersects_Capsule(ctx);
    if (numArgs == 1 && GetValueObject<Frustum>(ctx, 0, Frustum_ID))
        return Ray_Intersects_Frustum(ctx);
    duk_error(ctx, DUK_ERR_ERROR, "Could not select function overload");
}

static duk_ret_t Ray_ToLineSegment_Selector(duk_context* ctx)
{
    int numArgs = duk_get_top(ctx);
    if (numArgs == 1 && duk_is_number(ctx, 0))
        return Ray_ToLineSegment_float(ctx);
    if (numArgs == 2 && duk_is_number(ctx, 0) && duk_is_number(ctx, 1))
        return Ray_ToLineSegment_float_float(ctx);
    duk_error(ctx, DUK_ERR_ERROR, "Could not select function overload");
}

static duk_ret_t Ray_FromString_Static_string(duk_context* ctx)
{
    string str(duk_require_string(ctx, 0));
    Ray ret = Ray::FromString(str);
    PushValueObjectCopy<Ray>(ctx, ret, Ray_ID, Ray_Finalizer);
    return 1;
}

static const duk_function_list_entry Ray_Functions[] = {
    {"IsFinite", Ray_IsFinite, 0}
    ,{"GetPoint", Ray_GetPoint_float, 1}
    ,{"Translate", Ray_Translate_float3, 1}
    ,{"Transform", Ray_Transform_Selector, DUK_VARARGS}
    ,{"Contains", Ray_Contains_Selector, DUK_VARARGS}
    ,{"Equals", Ray_Equals_Ray_float, 2}
    ,{"BitEquals", Ray_BitEquals_Ray, 1}
    ,{"Distance", Ray_Distance_Selector, DUK_VARARGS}
    ,{"ClosestPoint", Ray_ClosestPoint_Selector, DUK_VARARGS}
    ,{"Intersects", Ray_Intersects_Selector, DUK_VARARGS}
    ,{"IntersectsDisc", Ray_IntersectsDisc_Circle, 1}
    ,{"ToLine", Ray_ToLine, 0}
    ,{"ToLineSegment", Ray_ToLineSegment_Selector, DUK_VARARGS}
    ,{"ProjectToAxis", Ray_ProjectToAxis_float3_float_float, 3}
    ,{"ToString", Ray_ToString, 0}
    ,{"SerializeToString", Ray_SerializeToString, 0}
    ,{"SerializeToCodeString", Ray_SerializeToCodeString, 0}
    ,{nullptr, nullptr, 0}
};

static const duk_function_list_entry Ray_StaticFunctions[] = {
    {"FromString", Ray_FromString_Static_string, 1}
    ,{nullptr, nullptr, 0}
};

void Expose_Ray(duk_context* ctx)
{
    duk_push_c_function(ctx, Ray_Ctor_Selector, DUK_VARARGS);
    duk_put_function_list(ctx, -1, Ray_StaticFunctions);
    duk_push_object(ctx);
    duk_put_function_list(ctx, -1, Ray_Functions);
    duk_put_prop_string(ctx, -2, "prototype");
    duk_put_global_string(ctx, Ray_ID);
}

}
