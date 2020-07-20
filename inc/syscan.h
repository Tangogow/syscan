//#ifdef SUTDGEST_H
//#define SUTDGEST_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <math.h>
#include <time.h>
#include <usb.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/utsname.h>
#include <sys/resource.h>
//#include <linux/wireless.h> //conflit net/if
#include <arpa/inet.h>
#include <linux/if_link.h>
#include <blkid/blkid.h>

#define MAX_COLS_LEN 100
#define _GNU_SOURCE

/* clearScreen */
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

typedef struct usbID {
  char *vendor;
  char *product;
};

/* main.c */
void menu();
void backToMenu();
void checkBackToMenu(char *);
void quit();
void clearScreen();

/* cpu.c */
void lscpu();

/* draw.c */
void drawArrBar(int, int *);
void drawCell(int, char *, int);
void drawMenuBar(int);
void drawMenuRow(int);
void drawMenuText(int, char *);
void menuBanner(int, char *);
void menuText();

/* ip.c */
void lsip();

/* main.c */
void clearScreen();
void quit();
void checkBackToMenu(char *);
void backToMenu();
void menu();

/* meminfo.c */
void lsmeminfo();

/* partitions.c */
void lspart();

/* ram.c */
void lsram();

/* release */
void lsrelease();

/* uname */
void lsuname();

/* usb.c */
char *getUSBIDs();
struct usbID getVendorAndProduct(char *, char *, char *, struct usbID);
char *getClassUsage(int);
char *getClassDescription(int);
void lsusb();

/* utils.c */
int checkIfStrOdd(int, char *);
char *itoa(int);
int doesFileExist(char *);
void repeatChar(char, int);
void *initArr(int *, int);
int intlen(int);
int getMax(int, int);
int getNumber(int, int, int, char *);
char *getString(int, int, char *);
void clearBuffer();
int stringIsInt(char *);
void *fmalloc(int);
float getFloat(int, int, int);
void writeFile(const char *, const char *, char *);

//#endif
