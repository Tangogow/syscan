#include "syscan.h"

void lsmeminfo() {
  char *buf;

  buf = malloc(sizeof(char *) * 1000);
  readFile("/proc/meminfo", buf);
  printf("\n%s", buf);
}
