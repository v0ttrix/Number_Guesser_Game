#!/bin/bash

# Remove Windows-specific defines
sed -i 's/#define _CRT_SECURE_NO_WARNINGS//g' NumGuesser/*.c

# Fix header include case
sed -i 's/"rng_module.h"/"RNG_Module.h"/g' NumGuesser/RNG_Module.c

# Add professional README
cat > README.md << 'READMEEOF'
# Number Guesser Game

## Overview
Professional C implementation of a number guessing game with modular design, file I/O, and scoring system.

## Author
Jaden Mardini

## Features
- Two difficulty levels (Easy: 1-100, Hard: 1-500)
- Persistent high score tracking
- Game history storage
- Input validation and error handling
- Professional modular code structure

## Building
```bash
make
./number_guesser save.txt
```

## Technical Skills Demonstrated
- Modular C programming
- File I/O operations
- Input validation
- Random number generation
- Memory management
- Error handling
- Build systems
READMEEOF

# Build and test
make clean && make
