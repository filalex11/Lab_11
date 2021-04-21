#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
/*
	Написать функцию void argssplit(char *args, int *argc, char **argv), разбивающую строку args на слова. Слова хранить в динамической памяти (malloc). Функция должна вернуть количество аргументов (argc) и массив указателей на них (**argv).
*/
int main () {
	int a = 0, length = 0, i = 0, j = 0, volume = 10;
	char* args = malloc (volume * sizeof(char));
	if (args == NULL) {
		printf ("NOT ENOUGH MEMORY!\n");
		return 1;
	}
	printf("Enter a string:\n");
	while ((a = getchar ()) != '\n') {
		if (length == volume) {
			volume *= 2;
			char *tmp = (char*) realloc (args, volume * sizeof(char));
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
	args[length] = 0;
	int argc = 0;
	char **argv = (char**) malloc (sizeof(char*));
	if (argv == NULL) {
		printf ("NOT ENOUGH MEMORY!\n");
		return 1;
	}
	argssplit (args, &argc, argv);
	if (argc == 0) {
		printf ("No output.\n");
		return 0;
	}
	printf ("Count of words: %d\n", argc);
	printf ("Words:\n");
	for (i = 0; i < argc; i++) {
		for (j = 0; argv[i][j] != 0; j++) {
			printf ("%c", argv[i][j]);
		}
		free (argv[i]);
		printf ("\n");
	}
	free (argv);
	return 0;
}
