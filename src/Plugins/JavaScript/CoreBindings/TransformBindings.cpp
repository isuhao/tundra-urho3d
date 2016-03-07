// For conditions of distribution and use, see copyright notice in LICENSE
// This file has been autogenerated with BindingsGenerator

#include "StableHeaders.h"
#include "CoreTypes.h"
#include "JavaScriptInstance.h"
#include "LoggingFunctions.h"
#include "Math/Transform.h"

#ifdef _MSC_VER
#pragma warning(disable: 4800)
#endif



using namespace Tundra;
using namespace std;

namespace JSBindings
{

extern const char* float3_ID;
extern const char* float3x3_ID;
extern const char* float3x4_ID;
extern const char* float4x4_ID;
extern const char* Quat_ID;

duk_ret_t float3_Finalizer(duk_context* ctx);
duk_ret_t float3x3_Finalizer(duk_context* ctx);
duk_ret_t float3x4_Finalizer(duk_context* ctx);
duk_ret_t float4x4_Finalizer(duk_context* ctx);
duk_ret_t Quat_Finalizer(duk_context* ctx);

const char* Transform_ID = "Transform";

duk_ret_t Transform_Finalizer(duk_context* ctx)
{
    Transform* obj = GetValueObject<Transform>(ctx, 0, Transform_ID);
    if (obj)
    {
        delete obj;
        SetValueObject(ctx, 0, 0, Transform_ID);
    }
    return 0;
}

static duk_ret_t Transform_Set_pos(duk_context* ctx)
{
    Transform* thisObj = GetThisValueObject<Transform>(ctx, Transform_ID);
    float3* pos = GetValueObject<float3>(ctx, 0, float3_ID);
    if (pos) thisObj->pos = *pos;
    return 0;
}

static duk_ret_t Transform_Get_pos(duk_context* ctx)
{
    Transform* thisObj = GetThisValueObject<Transform>(ctx, Transform_ID);
    PushValueObject<float3>(ctx, &thisObj->pos, float3_ID, nullptr, true);
    return 1;
}

static duk_ret_t Transform_Set_rot(duk_context* ctx)
{
    Transform* thisObj = GetThisValueObject<Transform>(ctx, Transform_ID);
    float3* rot = GetValueObject<float3>(ctx, 0, float3_ID);
    if (rot) thisObj->rot = *rot;
    return 0;
}

static duk_ret_t Transform_Get_rot(duk_context* ctx)
{
    Transform* thisObj = GetThisValueObject<Transform>(ctx, Transform_ID);
    PushValueObject<float3>(ctx, &thisObj->rot, float3_ID, nullptr, true);
    return 1;
}

static duk_ret_t Transform_Set_scale(duk_context* ctx)
{
    Transform* thisObj = GetThisValueObject<Transform>(ctx, Transform_ID);
    float3* scale = GetValueObject<float3>(ctx, 0, float3_ID);
    if (scale) thisObj->scale = *scale;
    return 0;
}

static duk_ret_t Transform_Get_scale(duk_context* ctx)
{
    Transform* thisObj = GetThisValueObject<Transform>(ctx, Transform_ID);
    PushValueObject<float3>(ctx, &thisObj->scale, float3_ID, nullptr, true);
    return 1;
}

static duk_ret_t Transform_Ctor(duk_context* ctx)
{
    Transform* newObj = new Transform();
    PushConstructorResult<Transform>(ctx, newObj, Transform_ID, Transform_Finalizer);
    return 0;
}

static duk_ret_t Transform_Ctor_float3_float3_float3(duk_context* ctx)
{
    float3* pos_ = GetCheckedValueObject<float3>(ctx, 0, float3_ID);
    float3* rot_ = GetCheckedValueObject<float3>(ctx, 1, float3_ID);
    float3* scale_ = GetCheckedValueObject<float3>(ctx, 2, float3_ID);
    Transform* newObj = new Transform(*pos_, *rot_, *scale_);
    PushConstructorResult<Transform>(ctx, newObj, Transform_ID, Transform_Finalizer);
    return 0;
}

static duk_ret_t Transform_Ctor_float3x3(duk_context* ctx)
{
    float3x3* m = GetCheckedValueObject<float3x3>(ctx, 0, float3x3_ID);
    Transform* newObj = new Transform(*m);
    PushConstructorResult<Transform>(ctx, newObj, Transform_ID, Transform_Finalizer);
    return 0;
}

static duk_ret_t Transform_Ctor_float3x4(duk_context* ctx)
{
    float3x4* m = GetCheckedValueObject<float3x4>(ctx, 0, float3x4_ID);
    Transform* newObj = new Transform(*m);
    PushConstructorResult<Transform>(ctx, newObj, Transform_ID, Transform_Finalizer);
    return 0;
}

static duk_ret_t Transform_Ctor_float4x4(duk_context* ctx)
{
    float4x4* m = GetCheckedValueObject<float4x4>(ctx, 0, float4x4_ID);
    Transform* newObj = new Transform(*m);
    PushConstructorResult<Transform>(ctx, newObj, Transform_ID, Transform_Finalizer);
    return 0;
}

static duk_ret_t Transform_SetPos_float3(duk_context* ctx)
{
    Transform* thisObj = GetThisValueObject<Transform>(ctx, Transform_ID);
    float3* v = GetCheckedValueObject<float3>(ctx, 0, float3_ID);
    thisObj->SetPos(*v);
    return 0;
}

static duk_ret_t Transform_SetPos_float_float_float(duk_context* ctx)
{
    Transform* thisObj = GetThisValueObject<Transform>(ctx, Transform_ID);
    float x = (float)duk_require_number(ctx, 0);
    float y = (float)duk_require_number(ctx, 1);
    float z = (float)duk_require_number(ctx, 2);
    thisObj->SetPos(x, y, z);
    return 0;
}

static duk_ret_t Transform_SetRotation_float_float_float(duk_context* ctx)
{
    Transform* thisObj = GetThisValueObject<Transform>(ctx, Transform_ID);
    float x = (float)duk_require_number(ctx, 0);
    float y = (float)duk_require_number(ctx, 1);
    float z = (float)duk_require_number(ctx, 2);
    thisObj->SetRotation(x, y, z);
    return 0;
}

static duk_ret_t Transform_SetScale_float_float_float(duk_context* ctx)
{
    Transform* thisObj = GetThisValueObject<Transform>(ctx, Transform_ID);
    float x = (float)duk_require_number(ctx, 0);
    float y = (float)duk_require_number(ctx, 1);
    float z = (float)duk_require_number(ctx, 2);
    thisObj->SetScale(x, y, z);
    return 0;
}

static duk_ret_t Transform_SetScale_float3(duk_context* ctx)
{
    Transform* thisObj = GetThisValueObject<Transform>(ctx, Transform_ID);
    float3* s = GetCheckedValueObject<float3>(ctx, 0, float3_ID);
    thisObj->SetScale(*s);
    return 0;
}

static duk_ret_t Transform_ToFloat3x4(duk_context* ctx)
{
    Transform* thisObj = GetThisValueObject<Transform>(ctx, Transform_ID);
    float3x4 ret = thisObj->ToFloat3x4();
    PushValueObjectCopy<float3x4>(ctx, ret, float3x4_ID, float3x4_Finalizer);
    return 1;
}

static duk_ret_t Transform_ToFloat4x4(duk_context* ctx)
{
    Transform* thisObj = GetThisValueObject<Transform>(ctx, Transform_ID);
    float4x4 ret = thisObj->ToFloat4x4();
    PushValueObjectCopy<float4x4>(ctx, ret, float4x4_ID, float4x4_Finalizer);
    return 1;
}

static duk_ret_t Transform_FromFloat3x4_float3x4(duk_context* ctx)
{
    Transform* thisObj = GetThisValueObject<Transform>(ctx, Transform_ID);
    float3x4* m = GetCheckedValueObject<float3x4>(ctx, 0, float3x4_ID);
    thisObj->FromFloat3x4(*m);
    return 0;
}

static duk_ret_t Transform_FromFloat4x4_float4x4(duk_context* ctx)
{
    Transform* thisObj = GetThisValueObject<Transform>(ctx, Transform_ID);
    float4x4* m = GetCheckedValueObject<float4x4>(ctx, 0, float4x4_ID);
    thisObj->FromFloat4x4(*m);
    return 0;
}

static duk_ret_t Transform_SetRotationAndScale_float3x3(duk_context* ctx)
{
    Transform* thisObj = GetThisValueObject<Transform>(ctx, Transform_ID);
    float3x3* mat = GetCheckedValueObject<float3x3>(ctx, 0, float3x3_ID);
    thisObj->SetRotationAndScale(*mat);
    return 0;
}

static duk_ret_t Transform_SetOrientation_float3x3(duk_context* ctx)
{
    Transform* thisObj = GetThisValueObject<Transform>(ctx, Transform_ID);
    float3x3* mat = GetCheckedValueObject<float3x3>(ctx, 0, float3x3_ID);
    thisObj->SetOrientation(*mat);
    return 0;
}

static duk_ret_t Transform_SetOrientation_Quat(duk_context* ctx)
{
    Transform* thisObj = GetThisValueObject<Transform>(ctx, Transform_ID);
    Quat* q = GetCheckedValueObject<Quat>(ctx, 0, Quat_ID);
    thisObj->SetOrientation(*q);
    return 0;
}

static duk_ret_t Transform_Orientation3x3(duk_context* ctx)
{
    Transform* thisObj = GetThisValueObject<Transform>(ctx, Transform_ID);
    float3x3 ret = thisObj->Orientation3x3();
    PushValueObjectCopy<float3x3>(ctx, ret, float3x3_ID, float3x3_Finalizer);
    return 1;
}

static duk_ret_t Transform_Orientation(duk_context* ctx)
{
    Transform* thisObj = GetThisValueObject<Transform>(ctx, Transform_ID);
    Quat ret = thisObj->Orientation();
    PushValueObjectCopy<Quat>(ctx, ret, Quat_ID, Quat_Finalizer);
    return 1;
}

static duk_ret_t Transform_Mul_Transform(duk_context* ctx)
{
    Transform* thisObj = GetThisValueObject<Transform>(ctx, Transform_ID);
    Transform* rhs = GetCheckedValueObject<Transform>(ctx, 0, Transform_ID);
    Transform ret = thisObj->Mul(*rhs);
    PushValueObjectCopy<Transform>(ctx, ret, Transform_ID, Transform_Finalizer);
    return 1;
}

static duk_ret_t Transform_ToString(duk_context* ctx)
{
    Transform* thisObj = GetThisValueObject<Transform>(ctx, Transform_ID);
    String ret = thisObj->ToString();
    duk_push_string(ctx, ret.CString());
    return 1;
}

static duk_ret_t Transform_SerializeToString(duk_context* ctx)
{
    Transform* thisObj = GetThisValueObject<Transform>(ctx, Transform_ID);
    String ret = thisObj->SerializeToString();
    duk_push_string(ctx, ret.CString());
    return 1;
}

static duk_ret_t Transform_Ctor_Selector(duk_context* ctx)
{
    int numArgs = duk_get_top(ctx);
    if (numArgs == 3 && GetValueObject<float3>(ctx, 0, float3_ID) && GetValueObject<float3>(ctx, 1, float3_ID) && GetValueObject<float3>(ctx, 2, float3_ID))
        return Transform_Ctor_float3_float3_float3(ctx);
    if (numArgs == 1 && GetValueObject<float3x4>(ctx, 0, float3x4_ID))
        return Transform_Ctor_float3x4(ctx);
    if (numArgs == 1 && GetValueObject<float4x4>(ctx, 0, float4x4_ID))
        return Transform_Ctor_float4x4(ctx);
    if (numArgs == 1 && GetValueObject<float3x3>(ctx, 0, float3x3_ID))
        return Transform_Ctor_float3x3(ctx);
    if (numArgs == 0)
        return Transform_Ctor(ctx);
    duk_error(ctx, DUK_ERR_ERROR, "Could not select function overload");
}

static duk_ret_t Transform_SetPos_Selector(duk_context* ctx)
{
    int numArgs = duk_get_top(ctx);
    if (numArgs == 3 && duk_is_number(ctx, 0) && duk_is_number(ctx, 1) && duk_is_number(ctx, 2))
        return Transform_SetPos_float_float_float(ctx);
    if (numArgs == 1 && GetValueObject<float3>(ctx, 0, float3_ID))
        return Transform_SetPos_float3(ctx);
    duk_error(ctx, DUK_ERR_ERROR, "Could not select function overload");
}

static duk_ret_t Transform_SetScale_Selector(duk_context* ctx)
{
    int numArgs = duk_get_top(ctx);
    if (numArgs == 3 && duk_is_number(ctx, 0) && duk_is_number(ctx, 1) && duk_is_number(ctx, 2))
        return Transform_SetScale_float_float_float(ctx);
    if (numArgs == 1 && GetValueObject<float3>(ctx, 0, float3_ID))
        return Transform_SetScale_float3(ctx);
    duk_error(ctx, DUK_ERR_ERROR, "Could not select function overload");
}

static duk_ret_t Transform_SetOrientation_Selector(duk_context* ctx)
{
    int numArgs = duk_get_top(ctx);
    if (numArgs == 1 && GetValueObject<Quat>(ctx, 0, Quat_ID))
        return Transform_SetOrientation_Quat(ctx);
    if (numArgs == 1 && GetValueObject<float3x3>(ctx, 0, float3x3_ID))
        return Transform_SetOrientation_float3x3(ctx);
    duk_error(ctx, DUK_ERR_ERROR, "Could not select function overload");
}

static duk_ret_t Transform_FromString_Static_String(duk_context* ctx)
{
    String str = duk_require_string(ctx, 0);
    Transform ret = Transform::FromString(str);
    PushValueObjectCopy<Transform>(ctx, ret, Transform_ID, Transform_Finalizer);
    return 1;
}

static const duk_function_list_entry Transform_Functions[] = {
    {"SetPos", Transform_SetPos_Selector, DUK_VARARGS}
    ,{"SetRotation", Transform_SetRotation_float_float_float, 3}
    ,{"SetScale", Transform_SetScale_Selector, DUK_VARARGS}
    ,{"ToFloat3x4", Transform_ToFloat3x4, 0}
    ,{"ToFloat4x4", Transform_ToFloat4x4, 0}
    ,{"FromFloat3x4", Transform_FromFloat3x4_float3x4, 1}
    ,{"FromFloat4x4", Transform_FromFloat4x4_float4x4, 1}
    ,{"SetRotationAndScale", Transform_SetRotationAndScale_float3x3, 1}
    ,{"SetOrientation", Transform_SetOrientation_Selector, DUK_VARARGS}
    ,{"Orientation3x3", Transform_Orientation3x3, 0}
    ,{"Orientation", Transform_Orientation, 0}
    ,{"Mul", Transform_Mul_Transform, 1}
    ,{"ToString", Transform_ToString, 0}
    ,{"SerializeToString", Transform_SerializeToString, 0}
    ,{nullptr, nullptr, 0}
};

static const duk_function_list_entry Transform_StaticFunctions[] = {
    {"FromString", Transform_FromString_Static_String, 1}
    ,{nullptr, nullptr, 0}
};

void Expose_Transform(duk_context* ctx)
{
    duk_push_c_function(ctx, Transform_Ctor_Selector, DUK_VARARGS);
    duk_put_function_list(ctx, -1, Transform_StaticFunctions);
    duk_push_object(ctx);
    duk_put_function_list(ctx, -1, Transform_Functions);
    DefineProperty(ctx, "pos", Transform_Get_pos, Transform_Set_pos);
    DefineProperty(ctx, "rot", Transform_Get_rot, Transform_Set_rot);
    DefineProperty(ctx, "scale", Transform_Get_scale, Transform_Set_scale);
    duk_put_prop_string(ctx, -2, "prototype");
    duk_put_global_string(ctx, Transform_ID);
}

}