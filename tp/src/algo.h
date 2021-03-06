#include "util.h"
#include <time.h>
#include <stdlib.h>
#include <math.h>

void genese (int population_size, int population[population_size][NUMBER_OF_TOWNS]);
int adaptation_and_selection (int population_size, int population[population_size][NUMBER_OF_TOWNS], int distances[NUMBER_OF_TOWNS][NUMBER_OF_TOWNS]);
void reproduction (int population_size, int population[population_size][NUMBER_OF_TOWNS], int pivot);
void mutation (int population_size, int population[population_size][NUMBER_OF_TOWNS], int probality);
void display_best (int population_size, int population[population_size][NUMBER_OF_TOWNS], int distances[NUMBER_OF_TOWNS][NUMBER_OF_TOWNS], char** town_names);
void fill_distances (int coordinates[NUMBER_OF_TOWNS][X_Y], int distances[NUMBER_OF_TOWNS][NUMBER_OF_TOWNS]);
