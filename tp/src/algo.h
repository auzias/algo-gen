#include "util.h"
#include <time.h>
#include <stdlib.h>

void genese (int population_size, int population[population_size][NUMBER_OF_TOWNS]);
void adaptation_and_selection (int population_size, int population[population_size][NUMBER_OF_TOWNS]);
void reproduction (int population_size, int population[population_size][NUMBER_OF_TOWNS]);
void mutation (int population_size, int population[population_size][NUMBER_OF_TOWNS]);
