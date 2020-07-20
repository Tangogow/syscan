#include "syscan.h"

void lsram() {
  struct rusage* memory = malloc(sizeof(struct rusage));

  getrusage(RUSAGE_SELF, memory);
  if (errno == EFAULT)
    printf("Error: EFAULT\n");
  else if (errno == EINVAL)
    printf("Error: EINVAL\n");
  printf("\nUsage RAM: %ld Ko\n", memory->ru_maxrss);
}
