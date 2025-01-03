#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/wait.h>

void print_banner();
void print_prompt();
char *get_line();
char **get_tokens(char *, char *, int *);
int execute(char *, char **);
char *search_path(const char *);
char *get_environ_path();
void free_tokens(char **tokens, int count);

#endif
