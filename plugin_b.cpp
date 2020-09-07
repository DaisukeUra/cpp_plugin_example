#include <stdio.h>

#include "plugin_base.hpp"

class plugin_b : public plugin_base {
 private:
  /* data */
 public:
  plugin_b(/* args */);
  ~plugin_b();
  void info() override;
};

plugin_b::plugin_b(/* args */) { printf("plugin b\n"); }

plugin_b::~plugin_b() {}

void plugin_b::info() { printf("My name is plugin b.\n"); };

REGISTER(plugin_b)
