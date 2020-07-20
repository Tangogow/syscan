#include "syscan.h"

void lsuname() {
  struct utsname buffer;

  errno = 0;
  if (uname(&buffer) != 0) {
     perror("uname");
     exit(EXIT_FAILURE);
  }

  printf("system name = %s\n", buffer.sysname);
  printf("node name   = %s\n", buffer.nodename);
  printf("release     = %s\n", buffer.release);
  printf("version     = %s\n", buffer.version);
  printf("machine     = %s\n", buffer.machine);
}
