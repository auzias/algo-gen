#include <stdio.h>
#include <stdlib.h>

// Readibility:
#define SUCCESS           0
#define START_MSG_SIZE    256
#define LONGEST_NAME      16
#define NUMBER_OF_TOWNS   45
#define ARG_POP_SIZE      1
#define ARG_NUM_GEN       2
#define EXPECTED_ARG_NUM  3

// Errors:
#define ERR_USAGE        -1
#define ERR_OPEN_FILE    -2

// Color code:
#define ANSI_RED          "\x1b[31m"
#define ANSI_GREEN        "\x1b[32m"
#define ANSI_BLUE         "\x1b[34m"
#define ANSI_RESET        "\x1b[0m"

// Utility:
#define DEBUG             1

void exit_error (const char *msg, const int err_num);
void message (const char *msg);

void fill_coordinates (int coordinates[NUMBER_OF_TOWNS][2]);
void fill_names (char** town_names);
