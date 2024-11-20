#include "prj.h"
#include "pr1.h"

struct mail *process_myQ (struct mail * head);
void display_myQ (struct mail *head);
struct mail *  delete_mail (struct mail *head, struct mail * mailToGo);
struct mail * delete_allmailOfFrom  (struct  mail *head,  char *fromName);
struct mail *    sort_byPriority (struct mail *head);
void 	terminate_write (struct mail *head);
void 	free_list(struct mail *head);
void set_priority (struct mail *head,  int mailID, char newPriority);

