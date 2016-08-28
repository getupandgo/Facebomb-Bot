#include "wrapper.h"

v8::Persistent<v8::Function> FaceBomberWrapper::constructor;

FaceBomberWrapper::FaceBomberWrapper() {
    bomber = new FaceBomber();
}

FaceBomberWrapper::~FaceBomberWrapper() {
    delete bomber;
}

void FaceBomberWrapper::Init(v8::Local<v8::Object> exports) {
    std::cout << "ini" <<std::endl;
  v8::Isolate* isolate = exports->GetIsolate();

  // Prepare constructor template
  v8::Local<v8::FunctionTemplate> tpl = v8::FunctionTemplate::New(isolate, New);
  tpl->SetClassName(v8::String::NewFromUtf8(isolate, "FaceBomberWrapper"));
  tpl->InstanceTemplate()->SetInternalFieldCount(1);

  // Prototype
  NODE_SET_PROTOTYPE_METHOD(tpl, "sayHello", SayHello);

  // Setting up constructor for our node object
  constructor.Reset(isolate, tpl->GetFunction());
  exports->Set(v8::String::NewFromUtf8(isolate, "FaceBomberWrapper"), tpl->GetFunction());
}

void FaceBomberWrapper::New(const v8::FunctionCallbackInfo<v8::Value>& args) {
  v8::Isolate* isolate = args.GetIsolate();

  if (args.IsConstructCall()) {
    // Invoked as constructor: `new MyObject(...)`
    FaceBomberWrapper* obj = new FaceBomberWrapper();
    obj->Wrap(args.This());
    args.GetReturnValue().Set(args.This());
  } else {
    // Invoked as plain function `MyObject(...)`, turn into construct call.
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::Local<v8::Function> cons = v8::Local<v8::Function>::New(isolate, constructor);
    v8::Local<v8::Object> result =
        cons->NewInstance(context).ToLocalChecked();
    args.GetReturnValue().Set(result);
  }
}

void FaceBomberWrapper::SayHello(const v8::FunctionCallbackInfo<v8::Value>& args) {
    FaceBomberWrapper* wrapper = ObjectWrap::Unwrap<FaceBomberWrapper>(args.Holder());
    wrapper->bomber->sayHello();
}

