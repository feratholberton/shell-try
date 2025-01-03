#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/wait.h>

void _printBanner();
void _printPrompt();
char *_getline();
char **_strtok(char *, char *, int *);
void _execve(char *, char **);
char *_getEnvironPath();
char *_searchPath(const char *);

#endif
