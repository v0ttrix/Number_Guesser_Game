/**
 * Random Number Generator Module
 * Provides random number generation for different difficulty levels
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "RNG_Module.h"

/**
 * Initializes the random number generator with current time seed
 */
void init_rng() {
    srand((unsigned int)time(NULL));
}

/**
 * Generates random number for easy mode (1-100)
 * @return Random integer between 1 and 100 inclusive
 */
int generate_random_number() {
    return (rand() % 100) + 1;
}

/**
 * Generates random number for hard mode (1-500)
 * @return Random integer between 1 and 500 inclusive
 */
int generate_random_hard_number() {
    return (rand() % 500) + 1;
}