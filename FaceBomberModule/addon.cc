#include <node.h>
#include "wrapper.h"

void init(v8::Local<v8::Object> exports) {
  FaceBomberWrapper::Init(exports);
}

NODE_MODULE(FaceBomber, init)
