#ifndef NODE_WRAPPER_H
#define NODE_WRAPPER_H

#include <node.h>
#include <node_object_wrap.h>

#include "./FaceBomber/FaceBomber.h"

class FaceBomberWrapper : public node::ObjectWrap {
 public:
 static void Init(v8::Local<v8::Object> exports);
 static void SayHello(const v8::FunctionCallbackInfo<v8::Value>& args);

 private:
 FaceBomber* bomber;

 explicit FaceBomberWrapper();
 ~FaceBomberWrapper();

 static void New(const v8::FunctionCallbackInfo<v8::Value>& args);
 static v8::Persistent<v8::Function> constructor;
};

#endif