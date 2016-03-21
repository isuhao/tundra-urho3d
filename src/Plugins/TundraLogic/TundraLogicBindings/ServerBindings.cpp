// For conditions of distribution and use, see copyright notice in LICENSE
// This file has been autogenerated with BindingsGenerator

#include "StableHeaders.h"
#include "CoreTypes.h"
#include "JavaScriptInstance.h"
#include "LoggingFunctions.h"
#include "Server.h"

#ifdef _MSC_VER
#pragma warning(disable: 4800)
#endif

#include "UserConnection.h"


using namespace Tundra;
using namespace std;

namespace JSBindings
{



static const char* Server_ID = "Server";

const char* SignalWrapper_Server_UserAboutToConnect_ID = "SignalWrapper_Server_UserAboutToConnect";

class SignalWrapper_Server_UserAboutToConnect
{
public:
    SignalWrapper_Server_UserAboutToConnect(Object* owner, Signal2< u32, UserConnection * >* signal) :
        owner_(owner),
        signal_(signal)
    {
    }

    WeakPtr<Object> owner_;
    Signal2< u32, UserConnection * >* signal_;
};

class SignalReceiver_Server_UserAboutToConnect : public SignalReceiver
{
public:
    void OnSignal(u32 param0, UserConnection * param1)
    {
        duk_context* ctx = ctx_;
        duk_push_global_object(ctx);
        duk_get_prop_string(ctx, -1, "_OnSignal");
        duk_remove(ctx, -2);
        duk_push_number(ctx, (size_t)key_);
        duk_push_array(ctx);
        duk_push_number(ctx, param0);
        duk_put_prop_index(ctx, -2, 0);
        PushWeakObject(ctx, param1);
        duk_put_prop_index(ctx, -2, 1);
        bool success = duk_pcall(ctx, 2) == 0;
        if (!success) LogError("[JavaScript] OnSignal: " + String(duk_safe_to_string(ctx, -1)));
        duk_pop(ctx);
    }
};

static duk_ret_t SignalWrapper_Server_UserAboutToConnect_Finalizer(duk_context* ctx)
{
    FinalizeValueObject<SignalWrapper_Server_UserAboutToConnect>(ctx, SignalWrapper_Server_UserAboutToConnect_ID);
    return 0;
}

static duk_ret_t SignalWrapper_Server_UserAboutToConnect_Connect(duk_context* ctx)
{
    SignalWrapper_Server_UserAboutToConnect* wrapper = GetThisValueObject<SignalWrapper_Server_UserAboutToConnect>(ctx, SignalWrapper_Server_UserAboutToConnect_ID);
    if (!wrapper->owner_) return 0;
    HashMap<void*, SharedPtr<SignalReceiver> >& signalReceivers = JavaScriptInstance::InstanceFromContext(ctx)->SignalReceivers();
    if (signalReceivers.Find(wrapper->signal_) == signalReceivers.End())
    {
        SignalReceiver_Server_UserAboutToConnect* receiver = new SignalReceiver_Server_UserAboutToConnect();
        receiver->ctx_ = ctx;
        receiver->key_ = wrapper->signal_;
        wrapper->signal_->Connect(receiver, &SignalReceiver_Server_UserAboutToConnect::OnSignal);
        signalReceivers[wrapper->signal_] = receiver;
    }
    CallConnectSignal(ctx, wrapper->signal_);
    return 0;
}

static duk_ret_t SignalWrapper_Server_UserAboutToConnect_Disconnect(duk_context* ctx)
{
    SignalWrapper_Server_UserAboutToConnect* wrapper = GetThisValueObject<SignalWrapper_Server_UserAboutToConnect>(ctx, SignalWrapper_Server_UserAboutToConnect_ID);
    if (!wrapper->owner_) return 0;
    CallDisconnectSignal(ctx, wrapper->signal_);
    return 0;
}

static duk_ret_t SignalWrapper_Server_UserAboutToConnect_Emit(duk_context* ctx)
{
    SignalWrapper_Server_UserAboutToConnect* wrapper = GetThisValueObject<SignalWrapper_Server_UserAboutToConnect>(ctx, SignalWrapper_Server_UserAboutToConnect_ID);
    if (!wrapper->owner_) return 0;
    u32 param0 = (u32)duk_require_number(ctx, 0);
    UserConnection* param1 = GetWeakObject<UserConnection>(ctx, 1);
    wrapper->signal_->Emit(param0, param1);
    return 0;
}

static duk_ret_t Server_Get_UserAboutToConnect(duk_context* ctx)
{
    Server* thisObj = GetThisWeakObject<Server>(ctx);
    SignalWrapper_Server_UserAboutToConnect* wrapper = new SignalWrapper_Server_UserAboutToConnect(thisObj, &thisObj->UserAboutToConnect);
    PushValueObject(ctx, wrapper, SignalWrapper_Server_UserAboutToConnect_ID, SignalWrapper_Server_UserAboutToConnect_Finalizer, false);
    duk_push_c_function(ctx, SignalWrapper_Server_UserAboutToConnect_Connect, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "Connect");
    duk_push_c_function(ctx, SignalWrapper_Server_UserAboutToConnect_Connect, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "connect");
    duk_push_c_function(ctx, SignalWrapper_Server_UserAboutToConnect_Disconnect, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "Disconnect");
    duk_push_c_function(ctx, SignalWrapper_Server_UserAboutToConnect_Disconnect, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "disconnect");
    duk_push_c_function(ctx, SignalWrapper_Server_UserAboutToConnect_Emit, 2);
    duk_put_prop_string(ctx, -2, "Emit");
    return 1;
}

const char* SignalWrapper_Server_UserDisconnected_ID = "SignalWrapper_Server_UserDisconnected";

class SignalWrapper_Server_UserDisconnected
{
public:
    SignalWrapper_Server_UserDisconnected(Object* owner, Signal2< u32, UserConnection * >* signal) :
        owner_(owner),
        signal_(signal)
    {
    }

    WeakPtr<Object> owner_;
    Signal2< u32, UserConnection * >* signal_;
};

class SignalReceiver_Server_UserDisconnected : public SignalReceiver
{
public:
    void OnSignal(u32 param0, UserConnection * param1)
    {
        duk_context* ctx = ctx_;
        duk_push_global_object(ctx);
        duk_get_prop_string(ctx, -1, "_OnSignal");
        duk_remove(ctx, -2);
        duk_push_number(ctx, (size_t)key_);
        duk_push_array(ctx);
        duk_push_number(ctx, param0);
        duk_put_prop_index(ctx, -2, 0);
        PushWeakObject(ctx, param1);
        duk_put_prop_index(ctx, -2, 1);
        bool success = duk_pcall(ctx, 2) == 0;
        if (!success) LogError("[JavaScript] OnSignal: " + String(duk_safe_to_string(ctx, -1)));
        duk_pop(ctx);
    }
};

static duk_ret_t SignalWrapper_Server_UserDisconnected_Finalizer(duk_context* ctx)
{
    FinalizeValueObject<SignalWrapper_Server_UserDisconnected>(ctx, SignalWrapper_Server_UserDisconnected_ID);
    return 0;
}

static duk_ret_t SignalWrapper_Server_UserDisconnected_Connect(duk_context* ctx)
{
    SignalWrapper_Server_UserDisconnected* wrapper = GetThisValueObject<SignalWrapper_Server_UserDisconnected>(ctx, SignalWrapper_Server_UserDisconnected_ID);
    if (!wrapper->owner_) return 0;
    HashMap<void*, SharedPtr<SignalReceiver> >& signalReceivers = JavaScriptInstance::InstanceFromContext(ctx)->SignalReceivers();
    if (signalReceivers.Find(wrapper->signal_) == signalReceivers.End())
    {
        SignalReceiver_Server_UserDisconnected* receiver = new SignalReceiver_Server_UserDisconnected();
        receiver->ctx_ = ctx;
        receiver->key_ = wrapper->signal_;
        wrapper->signal_->Connect(receiver, &SignalReceiver_Server_UserDisconnected::OnSignal);
        signalReceivers[wrapper->signal_] = receiver;
    }
    CallConnectSignal(ctx, wrapper->signal_);
    return 0;
}

static duk_ret_t SignalWrapper_Server_UserDisconnected_Disconnect(duk_context* ctx)
{
    SignalWrapper_Server_UserDisconnected* wrapper = GetThisValueObject<SignalWrapper_Server_UserDisconnected>(ctx, SignalWrapper_Server_UserDisconnected_ID);
    if (!wrapper->owner_) return 0;
    CallDisconnectSignal(ctx, wrapper->signal_);
    return 0;
}

static duk_ret_t SignalWrapper_Server_UserDisconnected_Emit(duk_context* ctx)
{
    SignalWrapper_Server_UserDisconnected* wrapper = GetThisValueObject<SignalWrapper_Server_UserDisconnected>(ctx, SignalWrapper_Server_UserDisconnected_ID);
    if (!wrapper->owner_) return 0;
    u32 param0 = (u32)duk_require_number(ctx, 0);
    UserConnection* param1 = GetWeakObject<UserConnection>(ctx, 1);
    wrapper->signal_->Emit(param0, param1);
    return 0;
}

static duk_ret_t Server_Get_UserDisconnected(duk_context* ctx)
{
    Server* thisObj = GetThisWeakObject<Server>(ctx);
    SignalWrapper_Server_UserDisconnected* wrapper = new SignalWrapper_Server_UserDisconnected(thisObj, &thisObj->UserDisconnected);
    PushValueObject(ctx, wrapper, SignalWrapper_Server_UserDisconnected_ID, SignalWrapper_Server_UserDisconnected_Finalizer, false);
    duk_push_c_function(ctx, SignalWrapper_Server_UserDisconnected_Connect, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "Connect");
    duk_push_c_function(ctx, SignalWrapper_Server_UserDisconnected_Connect, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "connect");
    duk_push_c_function(ctx, SignalWrapper_Server_UserDisconnected_Disconnect, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "Disconnect");
    duk_push_c_function(ctx, SignalWrapper_Server_UserDisconnected_Disconnect, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "disconnect");
    duk_push_c_function(ctx, SignalWrapper_Server_UserDisconnected_Emit, 2);
    duk_put_prop_string(ctx, -2, "Emit");
    return 1;
}

const char* SignalWrapper_Server_ServerStarted_ID = "SignalWrapper_Server_ServerStarted";

class SignalWrapper_Server_ServerStarted
{
public:
    SignalWrapper_Server_ServerStarted(Object* owner, Signal0< void >* signal) :
        owner_(owner),
        signal_(signal)
    {
    }

    WeakPtr<Object> owner_;
    Signal0< void >* signal_;
};

class SignalReceiver_Server_ServerStarted : public SignalReceiver
{
public:
    void OnSignal()
    {
        duk_context* ctx = ctx_;
        duk_push_global_object(ctx);
        duk_get_prop_string(ctx, -1, "_OnSignal");
        duk_remove(ctx, -2);
        duk_push_number(ctx, (size_t)key_);
        duk_push_array(ctx);
        bool success = duk_pcall(ctx, 2) == 0;
        if (!success) LogError("[JavaScript] OnSignal: " + String(duk_safe_to_string(ctx, -1)));
        duk_pop(ctx);
    }
};

static duk_ret_t SignalWrapper_Server_ServerStarted_Finalizer(duk_context* ctx)
{
    FinalizeValueObject<SignalWrapper_Server_ServerStarted>(ctx, SignalWrapper_Server_ServerStarted_ID);
    return 0;
}

static duk_ret_t SignalWrapper_Server_ServerStarted_Connect(duk_context* ctx)
{
    SignalWrapper_Server_ServerStarted* wrapper = GetThisValueObject<SignalWrapper_Server_ServerStarted>(ctx, SignalWrapper_Server_ServerStarted_ID);
    if (!wrapper->owner_) return 0;
    HashMap<void*, SharedPtr<SignalReceiver> >& signalReceivers = JavaScriptInstance::InstanceFromContext(ctx)->SignalReceivers();
    if (signalReceivers.Find(wrapper->signal_) == signalReceivers.End())
    {
        SignalReceiver_Server_ServerStarted* receiver = new SignalReceiver_Server_ServerStarted();
        receiver->ctx_ = ctx;
        receiver->key_ = wrapper->signal_;
        wrapper->signal_->Connect(receiver, &SignalReceiver_Server_ServerStarted::OnSignal);
        signalReceivers[wrapper->signal_] = receiver;
    }
    CallConnectSignal(ctx, wrapper->signal_);
    return 0;
}

static duk_ret_t SignalWrapper_Server_ServerStarted_Disconnect(duk_context* ctx)
{
    SignalWrapper_Server_ServerStarted* wrapper = GetThisValueObject<SignalWrapper_Server_ServerStarted>(ctx, SignalWrapper_Server_ServerStarted_ID);
    if (!wrapper->owner_) return 0;
    CallDisconnectSignal(ctx, wrapper->signal_);
    return 0;
}

static duk_ret_t SignalWrapper_Server_ServerStarted_Emit(duk_context* ctx)
{
    SignalWrapper_Server_ServerStarted* wrapper = GetThisValueObject<SignalWrapper_Server_ServerStarted>(ctx, SignalWrapper_Server_ServerStarted_ID);
    if (!wrapper->owner_) return 0;
    wrapper->signal_->Emit();
    return 0;
}

static duk_ret_t Server_Get_ServerStarted(duk_context* ctx)
{
    Server* thisObj = GetThisWeakObject<Server>(ctx);
    SignalWrapper_Server_ServerStarted* wrapper = new SignalWrapper_Server_ServerStarted(thisObj, &thisObj->ServerStarted);
    PushValueObject(ctx, wrapper, SignalWrapper_Server_ServerStarted_ID, SignalWrapper_Server_ServerStarted_Finalizer, false);
    duk_push_c_function(ctx, SignalWrapper_Server_ServerStarted_Connect, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "Connect");
    duk_push_c_function(ctx, SignalWrapper_Server_ServerStarted_Connect, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "connect");
    duk_push_c_function(ctx, SignalWrapper_Server_ServerStarted_Disconnect, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "Disconnect");
    duk_push_c_function(ctx, SignalWrapper_Server_ServerStarted_Disconnect, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "disconnect");
    duk_push_c_function(ctx, SignalWrapper_Server_ServerStarted_Emit, 0);
    duk_put_prop_string(ctx, -2, "Emit");
    return 1;
}

const char* SignalWrapper_Server_ServerStopped_ID = "SignalWrapper_Server_ServerStopped";

class SignalWrapper_Server_ServerStopped
{
public:
    SignalWrapper_Server_ServerStopped(Object* owner, Signal0< void >* signal) :
        owner_(owner),
        signal_(signal)
    {
    }

    WeakPtr<Object> owner_;
    Signal0< void >* signal_;
};

class SignalReceiver_Server_ServerStopped : public SignalReceiver
{
public:
    void OnSignal()
    {
        duk_context* ctx = ctx_;
        duk_push_global_object(ctx);
        duk_get_prop_string(ctx, -1, "_OnSignal");
        duk_remove(ctx, -2);
        duk_push_number(ctx, (size_t)key_);
        duk_push_array(ctx);
        bool success = duk_pcall(ctx, 2) == 0;
        if (!success) LogError("[JavaScript] OnSignal: " + String(duk_safe_to_string(ctx, -1)));
        duk_pop(ctx);
    }
};

static duk_ret_t SignalWrapper_Server_ServerStopped_Finalizer(duk_context* ctx)
{
    FinalizeValueObject<SignalWrapper_Server_ServerStopped>(ctx, SignalWrapper_Server_ServerStopped_ID);
    return 0;
}

static duk_ret_t SignalWrapper_Server_ServerStopped_Connect(duk_context* ctx)
{
    SignalWrapper_Server_ServerStopped* wrapper = GetThisValueObject<SignalWrapper_Server_ServerStopped>(ctx, SignalWrapper_Server_ServerStopped_ID);
    if (!wrapper->owner_) return 0;
    HashMap<void*, SharedPtr<SignalReceiver> >& signalReceivers = JavaScriptInstance::InstanceFromContext(ctx)->SignalReceivers();
    if (signalReceivers.Find(wrapper->signal_) == signalReceivers.End())
    {
        SignalReceiver_Server_ServerStopped* receiver = new SignalReceiver_Server_ServerStopped();
        receiver->ctx_ = ctx;
        receiver->key_ = wrapper->signal_;
        wrapper->signal_->Connect(receiver, &SignalReceiver_Server_ServerStopped::OnSignal);
        signalReceivers[wrapper->signal_] = receiver;
    }
    CallConnectSignal(ctx, wrapper->signal_);
    return 0;
}

static duk_ret_t SignalWrapper_Server_ServerStopped_Disconnect(duk_context* ctx)
{
    SignalWrapper_Server_ServerStopped* wrapper = GetThisValueObject<SignalWrapper_Server_ServerStopped>(ctx, SignalWrapper_Server_ServerStopped_ID);
    if (!wrapper->owner_) return 0;
    CallDisconnectSignal(ctx, wrapper->signal_);
    return 0;
}

static duk_ret_t SignalWrapper_Server_ServerStopped_Emit(duk_context* ctx)
{
    SignalWrapper_Server_ServerStopped* wrapper = GetThisValueObject<SignalWrapper_Server_ServerStopped>(ctx, SignalWrapper_Server_ServerStopped_ID);
    if (!wrapper->owner_) return 0;
    wrapper->signal_->Emit();
    return 0;
}

static duk_ret_t Server_Get_ServerStopped(duk_context* ctx)
{
    Server* thisObj = GetThisWeakObject<Server>(ctx);
    SignalWrapper_Server_ServerStopped* wrapper = new SignalWrapper_Server_ServerStopped(thisObj, &thisObj->ServerStopped);
    PushValueObject(ctx, wrapper, SignalWrapper_Server_ServerStopped_ID, SignalWrapper_Server_ServerStopped_Finalizer, false);
    duk_push_c_function(ctx, SignalWrapper_Server_ServerStopped_Connect, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "Connect");
    duk_push_c_function(ctx, SignalWrapper_Server_ServerStopped_Connect, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "connect");
    duk_push_c_function(ctx, SignalWrapper_Server_ServerStopped_Disconnect, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "Disconnect");
    duk_push_c_function(ctx, SignalWrapper_Server_ServerStopped_Disconnect, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "disconnect");
    duk_push_c_function(ctx, SignalWrapper_Server_ServerStopped_Emit, 0);
    duk_put_prop_string(ctx, -2, "Emit");
    return 1;
}

static duk_ret_t Server_UserConnections(duk_context* ctx)
{
    Server* thisObj = GetThisWeakObject<Server>(ctx);
    UserConnectionList & ret = thisObj->UserConnections();
    PushWeakObjectVector(ctx, ret);
    return 1;
}

static duk_ret_t Server_SetActionSender_UserConnection(duk_context* ctx)
{
    Server* thisObj = GetThisWeakObject<Server>(ctx);
    UserConnection* user = GetWeakObject<UserConnection>(ctx, 0);
    thisObj->SetActionSender(user);
    return 0;
}

static duk_ret_t Server_Port(duk_context* ctx)
{
    Server* thisObj = GetThisWeakObject<Server>(ctx);
    int ret = thisObj->Port();
    duk_push_number(ctx, ret);
    return 1;
}

static duk_ret_t Server_Protocol(duk_context* ctx)
{
    Server* thisObj = GetThisWeakObject<Server>(ctx);
    String ret = thisObj->Protocol();
    duk_push_string(ctx, ret.CString());
    return 1;
}

static duk_ret_t Server_Start_unsigned_short_String(duk_context* ctx)
{
    int numArgs = duk_get_top(ctx);
    Server* thisObj = GetThisWeakObject<Server>(ctx);
    unsigned short port = (unsigned short)duk_require_number(ctx, 0);
    String protocol = numArgs > 1 ? duk_require_string(ctx, 1) : "";
    bool ret = thisObj->Start(port, protocol);
    duk_push_boolean(ctx, ret);
    return 1;
}

static duk_ret_t Server_Stop(duk_context* ctx)
{
    Server* thisObj = GetThisWeakObject<Server>(ctx);
    thisObj->Stop();
    return 0;
}

static duk_ret_t Server_IsRunning(duk_context* ctx)
{
    Server* thisObj = GetThisWeakObject<Server>(ctx);
    bool ret = thisObj->IsRunning();
    duk_push_boolean(ctx, ret);
    return 1;
}

static duk_ret_t Server_IsAboutToStart(duk_context* ctx)
{
    Server* thisObj = GetThisWeakObject<Server>(ctx);
    bool ret = thisObj->IsAboutToStart();
    duk_push_boolean(ctx, ret);
    return 1;
}

static duk_ret_t Server_AuthenticatedUsers(duk_context* ctx)
{
    Server* thisObj = GetThisWeakObject<Server>(ctx);
    UserConnectionList ret = thisObj->AuthenticatedUsers();
    PushWeakObjectVector(ctx, ret);
    return 1;
}

static duk_ret_t Server_UserConnectionById_u32(duk_context* ctx)
{
    Server* thisObj = GetThisWeakObject<Server>(ctx);
    u32 connectionID = (u32)duk_require_number(ctx, 0);
    UserConnectionPtr ret = thisObj->UserConnectionById(connectionID);
    PushWeakObject(ctx, ret);
    return 1;
}

static duk_ret_t Server_ActionSender(duk_context* ctx)
{
    Server* thisObj = GetThisWeakObject<Server>(ctx);
    UserConnectionPtr ret = thisObj->ActionSender();
    PushWeakObject(ctx, ret);
    return 1;
}

static const duk_function_list_entry Server_Functions[] = {
    {"UserConnections", Server_UserConnections, 0}
    ,{"SetActionSender", Server_SetActionSender_UserConnection, 1}
    ,{"Port", Server_Port, 0}
    ,{"Protocol", Server_Protocol, 0}
    ,{"Start", Server_Start_unsigned_short_String, DUK_VARARGS}
    ,{"Stop", Server_Stop, 0}
    ,{"IsRunning", Server_IsRunning, 0}
    ,{"IsAboutToStart", Server_IsAboutToStart, 0}
    ,{"AuthenticatedUsers", Server_AuthenticatedUsers, 0}
    ,{"UserConnectionById", Server_UserConnectionById_u32, 1}
    ,{"ActionSender", Server_ActionSender, 0}
    ,{nullptr, nullptr, 0}
};

void Expose_Server(duk_context* ctx)
{
    duk_push_object(ctx);
    duk_push_object(ctx);
    duk_put_function_list(ctx, -1, Server_Functions);
    DefineProperty(ctx, "UserAboutToConnect", Server_Get_UserAboutToConnect, nullptr);
    DefineProperty(ctx, "UserDisconnected", Server_Get_UserDisconnected, nullptr);
    DefineProperty(ctx, "ServerStarted", Server_Get_ServerStarted, nullptr);
    DefineProperty(ctx, "ServerStopped", Server_Get_ServerStopped, nullptr);
    DefineProperty(ctx, "userConnections", Server_UserConnections, nullptr);
    DefineProperty(ctx, "port", Server_Port, nullptr);
    DefineProperty(ctx, "protocol", Server_Protocol, nullptr);
    DefineProperty(ctx, "running", Server_IsRunning, nullptr);
    DefineProperty(ctx, "aboutToStart", Server_IsAboutToStart, nullptr);
    DefineProperty(ctx, "authenticatedUsers", Server_AuthenticatedUsers, nullptr);
    DefineProperty(ctx, "actionSender", Server_ActionSender, Server_SetActionSender_UserConnection);
    duk_put_prop_string(ctx, -2, "prototype");
    duk_put_global_string(ctx, Server_ID);
}

}