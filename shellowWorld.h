#ifndef SHELLOWWORLD_H
#define SHELLOWWORLD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>

void display_prompt(void);
void print_string(const char *);
void read_command(char *, size_t );
void execute_command(const char *);

#endif
