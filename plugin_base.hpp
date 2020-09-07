#ifndef _PLUGIN_
#define _PLUGIN_
#include <stdio.h>

class plugin_base {
 private:
  /* data */
 public:
  plugin_base(/* args */);
  ~plugin_base();

  virtual void info() = 0;
};

plugin_base::plugin_base(/* args */) { printf("produce\n"); }

plugin_base::~plugin_base() {}

#define REGISTER(classname)                                           \
  extern "C" {                                                        \
  __attribute__((visibility("default"))) plugin_base *Registration(); \
  plugin_base *Registration() { return new classname(); };            \
  };
#endif

#define INFO(object)                        \
  extern "C" {                              \
  void Info(plugin_base *obj){obj->info()}; \
  void Info(obj);                           \
  }
