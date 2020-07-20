#include "syscan.h"

void lsrelease() {
  char *buf;

  buf = malloc(sizeof(char *) * 100);
  readFile("/etc/lsb-release", buf);
  printf("\n%s", buf);
}
