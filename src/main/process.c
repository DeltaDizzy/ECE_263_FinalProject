#include "process.h"
#include <stdlib.h>
#include <string.h>
#include "library.h"

struct mail* incrementTimeIn(struct mail* head) {
  struct mail* current = head;
  while (current != NULL) {
    current->timeIn++;
    current = current->nextmail;
  }
  return head;
}

struct mail* appendNewMail(struct mail* head) {
  struct mail* current = head;
  while (current->nextmail != NULL) {
    current = current->nextmail;
  }
  current->nextmail = genNewMail(0);
  return head;
}

// deliver up to 1 mail *to* each reciever (each unique value of To will get
// one mail or zero)
struct mail* deliverMail(struct mail* head, char* users[]) {
  int deliveryTracker[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  struct mail* current = head;
  for (int i = 0; i < 15; i++) {
    // if this index has already had a delivery, skip it
    if (deliveryTracker[i] == 1) {
      continue;
    }
    // we havent delivered mail for this person yet, so go through the list
    // until we find one from them
    struct mail* prev;
    while (current != NULL) {
      if (!strcmp(users[i], current->To)) {
        // deliver the mail (delete it)
        if (current == head) {
          head = current->nextmail;
        } else {
          prev->nextmail = current->nextmail;
        }
        free(current);
        deliveryTracker[i] = 1;
        break;
      }
      prev = current;
    }
  }
  return head;
}

// delete all nodes with timeIn > 3 unless priority >= 1 or resend = 1
struct mail* deleteExpiredMail(struct mail* head) {
  struct mail* current = head;
  struct mail* prev;
  while (current != NULL) {
    if (current->timeIn > 3) {
      if (current->priority >= 1 || current->resend == 1) {
        continue;
      } else {
        if (current == head) {
          head = current->nextmail;
        } else {
          prev->nextmail = current->nextmail;
        }
        free(current);
      }
    }
    prev = current;
    current = current->nextmail;
  }
  return head;
}

// if timein > 3 and priority >= 1, priority = 0 and resend = 1
struct mail* updatePriority(struct mail* head) {
  struct mail* current = head;
  while (current != NULL) {
    if (current->timeIn > 3 && current->priority >= 1) {
      current->priority = 0;
      current->resend = 1;
    }
    current = current->nextmail;
  }
  return head;
}

void swap_values(struct mail* a, struct mail* b) {
  struct mail temp = *a;
  *a = *b;
  *b = temp;
}
