#include "node.h"
#include "node_binding.h"
#include "env-inl.h"
#include "v8.h"

namespace node {
namespace borit {

using v8::Context;
using v8::FunctionCallbackInfo;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;

void Borit(const FunctionCallbackInfo<Value>& args) {
  args.GetReturnValue().Set(
      String::NewFromUtf8(args.GetIsolate(), "Borit :3").ToLocalChecked());
}

void Initialize(Local<Object> target,
                Local<Value> unused,
                Local<Context> context,
                void* priv) {
  Environment* env = Environment::GetCurrent(context);
  SetMethod(env->context(), target, "borit", Borit);
}

}  // namespace borit
}  // namespace node

NODE_BINDING_CONTEXT_AWARE_INTERNAL(borit, node::borit::Initialize)