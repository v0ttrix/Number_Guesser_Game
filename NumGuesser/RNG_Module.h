#pragma once
#ifndef RNG_MODULE_H
#define RNG_MODULE_H

// Function to initialize RNG (seeding with time)
void init_rng();

// Function to generate random number between 1 and 100(easy)
int generate_random_number();
// Function to generate random number between 1 and 500(hard)
int generate_random_hard_number();

#endif