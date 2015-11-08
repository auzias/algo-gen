#include "algo.h"
#include "util.h"

int main (int argc, char *argv[]) {
    //Check args
    if (argc < 2)
        exit_error ("usage: ./project.bin ./path/to/ville.dat population_size number_of_generations", ERR_USAGE);
    const unsigned int population_size = atoi(argv[2]);
    const unsigned int number_of_generations = atoi(argv[3]);

    char* start_msg = malloc(START_MSG_SIZE * sizeof(char));
    sprintf (start_msg, "The experience start. The population will have %d individuals and will run over %d generations.", population_size, number_of_generations);
    message (start_msg);







    message ("Experience finished");
    free (start_msg);
    return SUCCESS;
}
