#include <stdio.h>
#include <stdlib.h>

// Readibility:
#define SUCCESS           0
#define ERR_USAGE        -1
#define START_MSG_SIZE    256

// Color code:
#define ANSI_RED     "\x1b[31m"
#define ANSI_GREEN   "\x1b[32m"
#define ANSI_BLUE    "\x1b[34m"
#define ANSI_RESET   "\x1b[0m"

void exit_error (const char *msg, const int err_num);
void message (const char *msg);

void parse_towns (const char *pathname, int[][] population)
