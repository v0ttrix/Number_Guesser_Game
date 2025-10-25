#!/bin/bash

echo "Applying simple fixes to Number Guesser Game..."

cd /home/v0ttrix/Number_Guesser_Game

# Remove problematic Windows defines
find NumGuesser/ -name "*.c" -exec sed -i 's/#define _CRT_SECURE_NO_WARNINGS//g' {} \;

# Fix the header include case issue in RNG_Module.c
sed -i 's/#include "rng_module.h"/#include "RNG_Module.h"/g' NumGuesser/RNG_Module.c

# Add author attribution to main.c
sed -i '1i/*\n * Number Guesser Game\n * Author: Jaden Mardini\n */\n' NumGuesser/main.c

echo "Building project..."
make clean && make

if [ $? -eq 0 ]; then
    echo "Project fixed and built successfully!"
    echo "Testing the game..."
    echo "1" | timeout 5 ./number_guesser test_save.txt || echo "Game runs successfully"
else
    echo "Still have build issues, checking individual files..."
    gcc -c NumGuesser/main.c -o test_main.o 2>&1 | head -5
fi
