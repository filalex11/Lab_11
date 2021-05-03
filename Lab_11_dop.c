#ifndef LAB_11_C
#define LAB_11_C
#include "functions.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int word_count (const char *string) {
	int count = 0, i = 0;
	char in_word = 0;
	while (string[i]) {
		if (isalpha (string[i])) {
			in_word = 1;
		} else {
			if (in_word) {
				++count;
				in_word = 0;
			}
		}
		++i;
	}
	if (in_word) {
		++count;
	}
	return count;
}
void argssplit (char *args, int *argc, char **argv) {
	*argc = 0;
	*argc = word_count (args);
	if (!*argc) {
		return;
	}
	int i = 0, j = 0, k = 0, capacity = 10;
	char in_word = 0;
	while (args[k]) {
		if (isalpha (args[k])) {
			in_word = 1;
			if (j == 0) {
				argv[i] = (char*) malloc (capacity * sizeof (char));
				if (argv[i] == NULL) {
					printf ("NOT ENOUGH MEMORY!\n");
					exit (1);
				}
			}
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
			++j;
		} else {
			if (in_word) {
				in_word = 0;
				argv[i][j] = '\0';
				++i;
				j = 0;
			}
		}
		++k;
	}
	
	if (in_word) {
		argv[i][j] = '\0';
	}
}
void quicksort (char** argv, int first, int last) {
	if (first < last) {
		int left = first, right = last;
		char* middle = argv[(left + right) / 2];
		while (left <= right) {
			while (strcmp (argv[left], middle) < 0) {
				++left;
			}
			while (strcmp (argv[right], middle) > 0) {
				--right;
			}
			if (left <= right) {
				char* tmp = argv[left];
				argv[left] = argv[right];
				argv[right] = tmp;
				++left;
				--right;
			}
		}
		quicksort (argv, first, right);
		quicksort (argv, left, last);
	}
}
#endif
