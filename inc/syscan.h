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
#include <ifaddrs.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/wireless.h>

#define MAX_COLS_LEN 100

/* clearScreen */
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

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

/* main.c */
void menu();
void backToMenu();
void checkBackToMenu(char *);
void quit();
void clearScreen();

//#endif
