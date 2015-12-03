#include "util.h"
#include <time.h>
#include <stdlib.h>

void genese (int population_size, int population[population_size][NUMBER_OF_TOWNS]);
void adaptation_and_selection (int population_size, int population[population_size][NUMBER_OF_TOWNS], int distances[NUMBER_OF_TOWNS][NUMBER_OF_TOWNS]);
void reproduction (int population_size, int population[population_size][NUMBER_OF_TOWNS], int distances[NUMBER_OF_TOWNS][NUMBER_OF_TOWNS]);
void mutation (int population_size, int population[population_size][NUMBER_OF_TOWNS], int distances[NUMBER_OF_TOWNS][NUMBER_OF_TOWNS]);
void display_best (int population_size, int population[population_size][NUMBER_OF_TOWNS], int distances[NUMBER_OF_TOWNS][NUMBER_OF_TOWNS], char** town_names);
void fill_distances (int population_size, int coordinates[NUMBER_OF_TOWNS][X_Y], int distances[NUMBER_OF_TOWNS][NUMBER_OF_TOWNS]);
