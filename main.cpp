#include <dlfcn.h>

#include <iostream>

#include "plugin_base.hpp"

int main(int argv, char *argc[]) {
  plugin_base *(*func1)(void);

  if (argv < 2) return -1;

  void *handle = dlopen(argc[1], RTLD_LAZY);
  if (!handle) {
    std::cout << "Dynamic library can't load" << std::endl;
    exit(EXIT_FAILURE);
  }
  *(void **)(&func1) = dlsym(handle, "Registration");
  if (!func1) {
    std::cout << "Dynamic library can't load function" << std::endl;
    exit(EXIT_FAILURE);
  }
  auto a = func1();

  a->info();

  dlclose(handle);
}
