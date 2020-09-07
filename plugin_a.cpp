#include <stdio.h>

#include "plugin_base.hpp"

class plugin_a : public plugin_base {
 private:
  /* data */
 public:
  plugin_a(/* args */);
  ~plugin_a();

  void info() override;
};

plugin_a::plugin_a(/* args */) { printf("plugin a\n"); }

plugin_a::~plugin_a() {}

void plugin_a::info() { printf("My name is plugin a.\n"); };

REGISTER(plugin_a)
