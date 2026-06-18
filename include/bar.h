// SPDX-License-Identifier: GPL
#ifndef _BAR_H_
#define _BAR_H_

#define BAR_WIDTH 50

void printBar(char *description, int percentage);
void flushBar(char *description);
void incrementBar(char *description, int max);

#endif
