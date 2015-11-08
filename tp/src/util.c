#include "util.h"

void exit_error (const char *msg, const int err_num)
{
    fprintf (stderr, ANSI_RED);
    fprintf (stderr, msg);
    fprintf (stderr, ANSI_RESET);
    fprintf (stderr, "\n");
    exit (err_num);
}

void message (const char *msg)
{
    fprintf (stdout, ANSI_GREEN);
    fprintf (stdout, msg);
    fprintf (stdout, ANSI_RESET);
    fprintf (stdout, "\n");
}
