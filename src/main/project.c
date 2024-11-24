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
  printf("%-8s%-8s%-8s%-10s%-8s%-9s%-7s\n", "To", "From", "Mail ID",
         "Time Sent", "Time In", "Priority", "Resend");
  while (current != NULL) {
    printf("%-8s%-8s%-8d%-10d%-8d%-9c%-7c\n", current->To, current->From,
           current->mailId, current->timeSent, current->timeIn,
           current->priority, current->resend);
    current = current->nextmail;
  }
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

void terminate_write(struct mail* head) {
  struct mail* current = head;
  FILE* txt;
  fopen_s(&txt, "remainingQueue.txt", "w");
  while (current != NULL) {
    fprintf(txt, "%s\n", current->To);
    fprintf(txt, "%s\n", current->From);
    fprintf(txt, "%d\n", current->mailId);
    fprintf(txt, "%d\n", current->timeSent);
    fprintf(txt, "%d\n", current->timeIn);
    fprintf(txt, "%c\n", current->priority);
    fprintf(txt, "%c\n", current->resend);
    fprintf(txt, "\n");
    current = current->nextmail;
  }
  fclose(txt);
  free_list(head);
}

void free_list(struct mail* head) {
  struct mail* current = head;
  struct mail* prev;
  while (current != NULL) {
    if (current != head) {
      free(prev);
    }
    prev = current;
    current = current->nextmail;
  }
}

void set_priority(struct mail* head, int mailID, char newPriority) {
  struct mail* current = head;
  while (current != NULL) {
    if (current->mailId == mailID) {
      current->priority = newPriority;
      return;
    }
    current = current->nextmail;
  }
}