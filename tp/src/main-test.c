#include "algo.h"
#include "util.h"

int main (int argc, char *argv[])
{
    // Check args
    if (argc < EXPECTED_ARG_NUM)
        exit_error ("usage: ./project.bin population_size number_of_generations", ERR_USAGE);

    // Argument parsing
    const unsigned int population_size = atoi(argv[ARG_POP_SIZE]);
    const unsigned int number_of_generations = atoi(argv[ARG_NUM_GEN]);

    // Display starting message
    char* start_msg;
    if (DEBUG)
    {
      start_msg = (char*) malloc (START_MSG_SIZE * sizeof(char));
      sprintf (start_msg, "The experience start. The population will have %d individuals and will run over %d generations.", population_size, number_of_generations);
      message (start_msg);
      free (start_msg);
    }

    // Generate the town_names array
    char** town_names = (char**) calloc (NUMBER_OF_TOWNS, LONGEST_NAME * sizeof (char));
    fill_names (town_names);
    // Generate the coordinates array
    int coordinates[NUMBER_OF_TOWNS][X_Y];
    fill_coordinates (coordinates);

    // Generate the first generation
    int population[population_size][NUMBER_OF_TOWNS];
    genese (population_size, population);

    // Generate the distances array
    int distances[NUMBER_OF_TOWNS][NUMBER_OF_TOWNS];
    fill_distances (coordinates, distances);

    for (int generation = 0; generation < number_of_generations; generation++)
    {
        int pivot = adaptation_and_selection (population_size, population, distances);
        reproduction (population_size, population, pivot);
        mutation (population_size, population, MUTATION_PROB);
        if (DEBUG) {
            display_best (population_size, population, distances, town_names);
        }
    }
    if (DEBUG) {
        display_best (population_size, population, distances, town_names);
        message ("Experience finished");
    }
    return SUCCESS;
}
