#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "pr1.h"
#include "pr2.h"
#include "prj.h"

void print_main_menu(void);

int main(void) {
  struct mail* myQ = NULL;

  char command = 'b';
  int mailID;
  int seed;

  char newPriority;
  char buffer[126];
  puts("enter a seed");
  fgets(buffer, 126, stdin);
  seed = atoi(buffer);
  myQ = genNewMail(seed);

  while ((command != 'Q') && (myQ != NULL)) {
    print_main_menu();
    printf(">>>>> Enter a command ");

    fgets(buffer, 126, stdin);
    command = toupper(buffer[0]);

    switch (command) {
      case 'D':
        puts("\n\nSelect a Sender to delete all their mail");
        display_myQ(myQ);
        fgets(buffer, 126, stdin);
        myQ = delete_allmailOfFrom(myQ, buffer);
        break;
      case 'O':
        // Display list
        display_myQ(myQ);
        break;
      case 'P':
        myQ = process_myQ(myQ);
        break;
      case 'Q':
        terminate_write(myQ);
        break;
      case 'R':
        display_myQ(myQ);
        puts("\nselect a mail ID to reset priotiy");
        fgets(buffer, 126, stdin);
        mailID = atoi(buffer);
        puts("enter new priority");
        fgets(buffer, 126, stdin);
        newPriority = *buffer - '0';
        set_priority(myQ, mailID, newPriority);
        break;
      case 'S':
        myQ = sort_byPriority(myQ);
        break;
      case 'T':
        myQ = sortByTime(myQ);
        break;
    }
  }
  return 1;
}

void print_main_menu() {
  printf("*******************************************************\n");
  printf("*******************************************************\n");
  printf("                Main Menu\n");
  printf("*******************************************************\n");
  printf("\tD\t\tDelete_all mail Of a Sender\n");
  printf("\tO\t\tDisplay all mail in the List\n");

  printf("\tP\t\tProcess List \n");
  printf("\tR\t\tReset Priority for a mail\n");
  printf("\tQ\t\tQuit, Terminate and write to file\n");
  printf("\tS\t\tSort list by Priority\n");
  printf("\tT\t\tSort list by Time\n");

  printf("*******************************************************\n");
  printf("*******************************************************\n");
}
