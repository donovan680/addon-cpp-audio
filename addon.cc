#include <iostream>
#include <stdlib.h>
#include <nan.h>
#include <regex>
#include <windows.h>
#include <stdio.h>
#pragma comment(lib, "winmm.lib")

void RunCallback(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Function> cb = info[0].As<v8::Function>();
  const unsigned argc = 1;
  v8::Local<v8::Value> argv[argc] = { Nan::New("hello world").ToLocalChecked() };
  Nan::MakeCallback(Nan::GetCurrentContext()->Global(), cb, argc, argv);
}

void Init(v8::Local<v8::Object> exports, v8::Local<v8::Object> module) 
{
  Nan::SetMethod(module, "exports", RunCallback);
  std::cout << "Playing WAV file : \n";
  PlaySound("C:\\RockyRoadBlues.wav", NULL, SND_FILENAME);
  std::cout << "Playing WAV file : \n";
  PlaySound("C:\\Hey_You.wav", NULL, SND_FILENAME);
}

NODE_MODULE(addon, Init)  
