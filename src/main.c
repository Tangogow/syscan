#include "syscan.h"

void clearScreen() {
  system(CLEAR);
  usleep(100000);
}

void quit() {
  printf("Quitter\n");
  exit(0);
}

void checkBackToMenu(char *buf) {
  if (strcmp(buf, "r") == 0) {
   clearScreen();
   menu();
  }
  else if (strcmp(buf, "q") == 0)
   quit();
}

void backToMenu() {
  printf("\n\nr = retour, q = quitter\n");
  char input = getChar();

  while (input != 'r' && input != 'q') {
    printf("r = retour, q = quitter\n");
    input = getChar();
  }
  if (input == 'r') {
    clearScreen();
    menu();
  }
  else if (input == 'q')
    quit();
}


void menu() {
  menuText();
  int choice = 0;

  while (choice < 1 || choice > 7) {
    choice = getInt(1, 1, 9, "Entrez votre choix");
    switch (choice) {
      case 1:
        lsusb();
        backToMenu();
        break;
      case 2:
        lscpu();
        backToMenu();
        break;
      case 3:
        lsip();
        backToMenu();
        break;
      case 4:
        lsuname();
        backToMenu();
        break;
      case 5:
        lsrelease();
        backToMenu();
        break;
      case 6:
        lsmeminfo();
        backToMenu();
        break;
      case 7:
        lsram();
        backToMenu();
        break;
      case 8:
        lspart();
        backToMenu();
        break;
      default:
        clearScreen();
        printf("Erreur: Choix non reconnu\n\n");
        menu();
        break;
      }
  }
}

int main(int ac, char **av) {
  //clearScreen();
  //menuBanner(30, "Syscan ");
  menu();
	return 0;
}
