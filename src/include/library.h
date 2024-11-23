#pragma once

#include "mail.h"

void assignData(struct mail*, int);
struct mail* sortByTime(struct mail*);
void displayNewMail(struct mail*);
struct mail* genNewMail(int);
