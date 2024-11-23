#include "project.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"
#include "process.h"

char* users[] = {"Aaron", "Albert",  "Bernie",  "Donovan", "Dontel",
                 "Evan",  "Eve",     "Francis", "George",  "Hannah",
                 "Isaac", "Jackson", "Tyrone",  "Warren",  "Zoe"};

int recievedMask[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

struct mail* process_myQ(struct mail* head) {
  head = incrementTimeIn(head);
  head = appendNewMail(head);
  head = deliverMail(head, users);
  head = deleteExpiredMail(head);
  head = updatePriority(head);
  head = sortByTime(head);
  return head;
}

void display_myQ(struct mail* head) {
  struct mail* current = head;
  if (current == NULL) {
    printf("The mail queue is empty.");
  }
  // To, From, mailId, timeSent, timeIn, priority, resend
  // header
  printf("%-8s%-8s%-8s%-10s%-8s%-9s%-7s", "To", "From", "Mail ID", "Time Sent",
         "Time In", "Priority", "Resend");
}

struct mail* delete_mail(struct mail* head, struct mail* mailToGo) {
  struct mail* current = head;
  struct mail* prev;

  while (current != NULL) {
    if (current == mailToGo) {
      break;
    }
    prev = current;
    current = current->nextmail;
  }
  prev->nextmail = mailToGo->nextmail;
  free(mailToGo);
  return head;
}

struct mail* delete_allmailOfFrom(struct mail* head, char* fromName) {
  struct mail* current = head;
  struct mail* prev;
  while (current != NULL) {
    if (!strcmp(current->From, fromName)) {
      // delete this node
      if (current == head) {
        struct mail* temp = current;
        head = current->nextmail;
        free(temp);
        continue;
      } else {
        prev->nextmail = current->nextmail;
        free(current);
      }
    }
    prev = current;
    current = current->nextmail;
  }
  return head;
}

struct mail* sort_byPriority(struct mail* head) {
  return NULL;
}

void terminate_write(struct mail* head) {}

void free_list(struct mail* head) {}

void set_priority(struct mail* P, int mailID, char newPriority) {}