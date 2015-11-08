#include "algo.h"
#include "util.h"

int main (int argc, char *argv[])
{
    // Check args
    if (argc < 3)
        exit_error ("usage: ./project.bin population_size number_of_generations", ERR_USAGE);

    const unsigned int population_size = atoi(argv[1]);
    const unsigned int number_of_generations = atoi(argv[2]);

    // Display starting message
    char* start_msg;
    if (DEBUG)
    {
      start_msg = (char*) malloc (START_MSG_SIZE * sizeof(char));
      sprintf (start_msg, "The experience start. The population will have %d individuals and will run over %d generations.", population_size, number_of_generations);
      message (start_msg);
    }

    // Generate the town_names array
    char** town_names = (char**) calloc (NUMBER_OF_TOWNS, LONGEST_NAME * sizeof (char));
    fill_names (town_names);
    // Generate the coordinates array
    int coordinates[NUMBER_OF_TOWNS][2];
    fill_coordinates (coordinates);

    // Generate the first generation:
    int population[population_size][NUMBER_OF_TOWNS];
    genese (population_size, population);

    for (int generation = 0; generation < number_of_generations; generation++)
    {
      adaptation_and_selection (population_size, population);
      reproduction (population_size, population);
      mutation (population_size, population);
    }

    display_best (population_size, population);

    message ("Experience finished");
    free (start_msg);
    return SUCCESS;
}
