#ifndef REPL_H
#define REPL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void printBanner(void);
char *get_line(void);

#endif
