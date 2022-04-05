#include "example.h"
using namespace std;
int example::isPrime(int num){
 
 int flag=1;
    for(int i = 2; i <= num / 2; i++) {
       if(num % i == 0) {
          flag = 0;
          break;
       }
    }
    return flag;
}
Napi::Number example::isPrimeWrapped(const Napi::CallbackInfo& info){
 Napi::Env env = info.Env();
 //check if arguments are integer only.
 if(info.Length()<1 || !info[0].IsNumber()){
    Napi::TypeError::New(env, "arg1::Number, arg2::Number expected").ThrowAsJavaScriptException();
 }
 //convert javascripts datatype to c++
 Napi::Number first = info[0].As<Napi::Number>();
//run c++ function return value and return it in javascript
 Napi::Number returnValue = Napi::Number::New(env, example::isPrime(first.Int32Value()));
 
 return returnValue;
}
Napi::Object example::Init(Napi::Env env, Napi::Object exports) 
{
  //export Napi function
  exports.Set("isPrime", Napi::Function::New(env, example::isPrimeWrapped));
  return exports;
}