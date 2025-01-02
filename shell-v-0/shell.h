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
char *_getenv(const char *);
char *_getEnvironmentPath();
#endif
