#pragma once

#include "mail.h"

struct mail* incrementTimeIn(struct mail* head);

struct mail* appendNewMail(struct mail* head);

// deliver up to 1 mail *to* each reciever (each unique value of To will get
// one mail or zero)
struct mail* deliverMail(struct mail* head, char* users[]);

// delete all nodes with timeIn > 3 unless priority >= 1 or resend = 1
struct mail* deleteExpiredMail(struct mail* head);

// if timein > 3 and priority >= 1, priority = 0 and resend = 1
struct mail* updatePriority(struct mail* head);

void swap_values(struct mail* a, struct mail* b);