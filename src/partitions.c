#include "syscan.h"

void lspart() {
  char *buf;

  buf = malloc(sizeof(char *) * 1000);
  readFile("/proc/partitions", buf);
  printf("\n%s", buf);
}

/*void lspart() {
  blkid_probe pr = blkid_new_probe_from_filename(argv[1]);
  if (!pr)
    err(1, "Failed to open %s", argv[1]);
  blkid_partlist ls;
  int nparts;
  char *uuid;
  char *label;
  char *type;

  ls = blkid_probe_get_partitions(pr);
  nparts = blkid_partlist_numof_partitions(ls);
  printf("Number of partitions:%d\n", nparts);

  if (nparts <= 0)
    printf("Mauvais nombre de partition");

  for (int i = 0; i < nparts; i++) {
    char dev_name[20];

    sprintf(dev_name, "%s%d", argv[1], (i+1));
    pr = blkid_new_probe_from_filename(dev_name);
    blkid_do_probe(pr);
    blkid_probe_lookup_value(pr, "UUID", &uuid, NULL);
    blkid_probe_lookup_value(pr, "LABEL", &label, NULL);
    blkid_probe_lookup_value(pr, "TYPE", &type, NULL);
    printf("Name=%s, UUID=%s, LABEL=%s, TYPE=%s\n", dev_name, uuid, label, type);
   }
  blkid_free_probe(pr);
}*/
