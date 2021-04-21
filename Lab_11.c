#ifndef LAB_11_C
#define LAB_11_C
#include "functions.h"
#include <stdlib.h>
#include <stdio.h>
int is_letter (char str) {
	if (((str >= 'A') && (str <= 'Z')) || ((str >= 'a') && (str <= 'z')) || (str == '.')) {
		return 1;
	} else {
		return 0;
	}
}

int word_count (char *string) {
	int i = 0, count = 0;
	char in_word = 0;
	while (string[i] != 0) {
		if (is_letter (string[i]) == 1) {
			in_word = 1;
		} else {
			if (in_word == 1) {
				count++;
				in_word = 0;
			}
		}
		i++;
	}
	if (in_word == 1) {
		count++;
	}
	return count;
}

void argssplit (char *args, int *argc, char **argv) {
	*argc = 0;
	*argc = word_count (args);
	int i = 0, j = 0, k = 0;
	char **tmp = (char**) realloc (argv, *argc * sizeof (char*));
	if (tmp == NULL) {
		free (argv);
		printf ("NOT ENOUGH MEMORY!\n");
		exit (1);
	} else {
		argv = tmp;
	}
	int capacity = 5;
	for (i = 0; i < *argc; i++) {
		argv[i] = (char*) malloc (capacity * sizeof (char));
		if (argv[i] == NULL) {
			printf ("NOT ENOUGH MEMORY!\n");
			exit (1);
		}
	}
	i = 0;
	int symbols = 0;
	while (args[k] != 0) {
		if (is_letter(args[k]) == 1) {
			if (j == capacity) {
				capacity *= 2;
				char *tmp1 = (char*) realloc (argv[i], capacity * sizeof (char));
				if (tmp1 == NULL) {
					free (argv[i]);
					printf ("NOT ENOUGH MEMORY!\n");
					exit (1);
				} else {
					argv[i] = tmp1;
				}
			}
			argv[i][j] = args[k];
			j++;
			symbols = 0;
		} else {
			symbols++;
			if ((symbols == 1) && (j != 0)) {
				i++;
				j = 0;
				capacity = 5;
			}
		}
		k++;
	}
}
#endif
