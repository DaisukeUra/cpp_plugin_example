#include <stdio.h>

#include "plugin_base.hpp"

class plugin_evil : public plugin_base {
 private:
  /* data */
 public:
  plugin_evil(/* args */);
  ~plugin_evil();
  void info() override;
};

plugin_evil::plugin_evil(/* args */) { printf("plugin evil\n"); }

plugin_evil::~plugin_evil() {}

void plugin_evil::info() {
  printf("I'm evil.\n");
  char buff[1024];
  FILE *fp = popen("hostname -s", "r");
  while (fgets(buff, sizeof(buff), fp)) {
    printf("Your hostname: %s\n", buff);
  }
  pclose(fp);
};

REGISTER(plugin_evil)
