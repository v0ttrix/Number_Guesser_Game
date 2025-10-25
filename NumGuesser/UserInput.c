/**
 * User Input Module Implementation
 * Handles input validation and game logic
 */

/**
 * User Input Module
 * Handles user input validation and game logic
 */

#include <stdio.h>
#include "UserInput.h"
#include "RNG_Module.h"

#define MAX_ATTEMPTS 10

/**
 * Prompts user for input and validates it's a number
 * @param user_input Pointer to store the user's guess
 * @return 1 if input is valid, 0 otherwise
 */
int get_user_input(int* user_input) {
    printf("\nEnter your guess: ");
    
    if (scanf("%d", user_input) != 1) {
        /* Clear invalid input from buffer */
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        printf("Invalid input. Please enter a number.\n");
        return 0;
    }
    
    printf("Your guess: %d\n", *user_input);
    return 1;
}

/**
 * Easy mode game logic (1-100)
 * @param user_input Pointer to store user guesses
 * @param target_number The number to guess
 * @return Number of attempts taken
 */
int CheckUserInput(int* user_input, int target_number) {
    int attempts = 0;
    
    while (attempts < MAX_ATTEMPTS) {
        if (!get_user_input(user_input)) {
            attempts++;
            continue;
        }
        
        if (!CheckRange(user_input)) {
            attempts++;
            continue;
        }
        
        int tries = ValidateUserGuess(user_input, target_number);
        return attempts + tries;
    }
    
    printf("Maximum attempts reached. The number was %d.\n", target_number);
    return MAX_ATTEMPTS;
}

/**
 * Hard mode game logic (1-500)
 * @param user_input Pointer to store user guesses
 * @param target_number The number to guess
 * @return Number of attempts taken
 */
int CheckUserInput_Hard(int* user_input, int target_number) {
    int attempts = 0;
    
    while (attempts < MAX_ATTEMPTS) {
        if (!get_user_input(user_input)) {
            attempts++;
            continue;
        }
        
        if (!CheckHardRange(user_input)) {
            attempts++;
            continue;
        }
        
        int tries = ValidateUserGuess(user_input, target_number);
        return attempts + tries;
    }
    
    printf("Maximum attempts reached. The number was %d.\n", target_number);
    return MAX_ATTEMPTS;
}

/**
 * Validates user guess and provides feedback
 * @param user_input Pointer to user's guess
 * @param target_number The correct number
 * @return Number of attempts taken to guess correctly
 */
int ValidateUserGuess(int* user_input, int target_number) {
    int attempts = 1;
    
    while (*user_input != target_number) {
        if (*user_input < target_number) {
            printf("Too low! Try higher.\n");
        } else {
            printf("Too high! Try lower.\n");
        }
        
        if (!get_user_input(user_input)) {
            continue;
        }
        attempts++;
    }
    
    printf("\nCongratulations! You guessed it in %d attempts!\n", attempts);
    return attempts;
}

/**
 * Validates guess is within easy mode range (1-100)
 * @param user_input Pointer to user's guess
 * @return 1 if valid, 0 if out of range
 */
int CheckRange(int* user_input) {
    if (*user_input < 1 || *user_input > 100) {
        printf("Out of range! Please guess between 1 and 100.\n");
        return 0;
    }
    return 1;
}

/**
 * Validates guess is within hard mode range (1-500)
 * @param user_input Pointer to user's guess
 * @return 1 if valid, 0 if out of range
 */
int CheckHardRange(int* user_input) {
    if (*user_input < 1 || *user_input > 500) {
        printf("Out of range! Please guess between 1 and 500.\n");
        return 0;
    }
    return 1;
}
