// SPDX-License-Identifier: GPL
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "bar.h"

void flushBar(char *description)
{
	char bar[BAR_WIDTH + 3] =
		"[##################################################]";

	printf("\033[2K\033[G");
	printf(description);
	printf(bar);
	putchar('\n');
}

void printBar(char *description, int percentage)
{
	char bar[BAR_WIDTH + 3] =
		"[--------------------------------------------------]";

	percentage = percentage < 50 ? percentage : 50;
	memset(bar + 1, '#', percentage);

	printf("\033[2K\033[G");
	printf(description);
	printf(bar);
	fflush(stdout);
}

void incrementBar(char *description, int max)
{
	char bar[BAR_WIDTH + 3] =
		"[--------------------------------------------------]";

	// by bitwise anding, we emulate min(percentage, 50);
	static int amount;
	static int percentage;

	amount++;
	int newPercentage =
		((100 * amount / max) < 100) ? (100 * amount / max) : 100;

	if (newPercentage == percentage)
		return;

	percentage = newPercentage;

	memset(bar + 1, '#', (percentage / 2));

	printf("\033[2K\033[G");
	printf(description);
	printf(bar);
	fflush(stdout);
}
