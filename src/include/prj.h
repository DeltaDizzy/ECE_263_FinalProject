#pragma once

struct mail {
	char To[25];
	int mailId;
	int timeSent;
	int timeIn;
	char priority;
	char resend;
	char From[25];
	char message[100];
	struct mail	*nextmail;
};
