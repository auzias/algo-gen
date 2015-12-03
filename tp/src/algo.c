#include "algo.h"

/**
 * Randomly fill the first generation.
 * Make sure that all towns are only
 * once in each individuals !
 */
void genese (int population_size, int population[population_size][NUMBER_OF_TOWNS])
{

}

/**
 *
 */
int adaptation_and_selection (int population_size,
                                int population[population_size][NUMBER_OF_TOWNS],
                                int distances[NUMBER_OF_TOWNS][NUMBER_OF_TOWNS])
{
    int pivot = 0; //TODO: à modifier

    return pivot;
}

/**
 *
 */
void reproduction (int population_size,
                   int population[population_size][NUMBER_OF_TOWNS],
                   int distances[NUMBER_OF_TOWNS][NUMBER_OF_TOWNS],
		   int pivot)
{

}

/**
 *
 */
void mutation (int population_size,
               int population[population_size][NUMBER_OF_TOWNS],
               int distances[NUMBER_OF_TOWNS][NUMBER_OF_TOWNS])
{

}

/**
 *
 */
void display_best (int population_size,
                   int population[population_size][NUMBER_OF_TOWNS],
                   int distances[NUMBER_OF_TOWNS][NUMBER_OF_TOWNS],
                   char** town_names)
{
    //Example of implementation
    double cost = 3.14159265358979323846264338327950288419716939937510582097;
    printf("Best is (%0.1f): ", cost);
    for(int i = 0; i < NUMBER_OF_TOWNS; i++) {
        printf("%d ", i);
    }
    putchar('\n');
}

/**
 *
 */
void fill_distances (int population_size,
		     int coordinates[NUMBER_OF_TOWNS][X_Y],
		     int distances[NUMBER_OF_TOWNS][NUMBER_OF_TOWNS])
{

}
