#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
/*
	Отсортировать слова в строке со сложностью n*log(n)
*/
int main () {
	int a = 0, length = 0, volume = 10;
	char* args = malloc (volume * sizeof (char));
	if (args == NULL) {
		printf ("NOT ENOUGH MEMORY!\n");
		return 1;
	}
	printf("Enter a string:\n");
	while ((a = getchar ()) != '\n') {
		if (length == volume) {
			volume *= 2;
			char *tmp = (char*) realloc (args, volume * sizeof (char));
			if (tmp == NULL) {
				free (args);
				printf ("NOT ENOUGH MEMORY!\n");
				return 1;
			} else {
				args = tmp;
			}
		}
		args[length] = a;
		++length;
	}
	args[length] = '\0';
	int argc = 0;
	int count = word_count (args);
	char **argv = (char**) malloc (count * sizeof (char*));
	if (argv == NULL) {
		printf ("NOT ENOUGH MEMORY!\n");
		exit (1);
	}
	argssplit (args, &argc, argv);
	free (args);
	printf ("Count of words: %d\n", argc);
	if (!argc) {
		free (argv);
		printf ("No output.\n");
		return 0;
	}
	printf ("Words:\n");
	quicksort (argv, 0, count - 1);
	for (int i = 0; i < argc; ++i) {
		printf ("%s\n", argv[i]);
		free (argv[i]);
	}
	free (argv);
	return 0;
}	
