#ifndef REPL_H
#define REPL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void printBanner(void);
char *get_line(void);
char **tokenize_string(char *, char *, int *);

#endif
