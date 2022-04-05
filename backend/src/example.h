#include <napi.h>
#include <iostream>
using namespace std;
namespace example{
 //add number function
 int isPrime(int num);
//add function wrapper
 Napi::Number isPrimeWrapped(const Napi::CallbackInfo& info);
 //Export API
 Napi::Object Init(Napi::Env env, Napi::Object exports);
 NODE_API_MODULE(addon, Init)
}