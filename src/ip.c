#include "syscan.h"

void lsip()
{
  struct ifaddrs *ifaddr, *ifa;
  int family, s;
  char host[NI_MAXHOST];

  if (getifaddrs(&ifaddr) == -1) {
    perror("getifaddrs");
    exit(EXIT_FAILURE);
  }
  for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
    family = ifa->ifa_addr->sa_family;
    if (family == AF_INET) {
      printf("\n%s", ifa->ifa_name);
      getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in), host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);
      printf("\tinet: %s\t", host);
      getnameinfo(ifa->ifa_netmask, sizeof(struct sockaddr_in), host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);
      printf("\tmask: %s\t", host);
      getnameinfo(ifa->ifa_broadaddr, sizeof(struct sockaddr_in), host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);
      printf("\tbroad: %s", host);
      /*if (((ifaptr)->ifa_addr)->sa_family == AF_LINK) {
        ptr = (unsigned char *)LLADDR((struct sockaddr_dl *)(ifaptr)->ifa_addr);
        printf("%s: %02x:%02x:%02x:%02x:%02x:%02x\n",
        (ifaptr)->ifa_name,
        *ptr, *(ptr+1), *(ptr+2), *(ptr+3), *(ptr+4), );*(ptr+5));
      }*/
    }
    else if (family == AF_INET6) {
      printf("\n");
      getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in6), host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);
      printf("\tinet6: %s\n", host);
    }
  }
  freeifaddrs(ifaddr);
}
