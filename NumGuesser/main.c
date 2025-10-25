/*
 * Number Guesser Game
 * Author: Jaden Mardini
 */

/**
 * Number Guesser Game
 * Author: Jaden Mardini
 * Professional C implementation with modular design
 */

/**
 * Number Guesser Game
 * Author: Jaden Mardini
 * 
 * A professional number guessing game demonstrating:
 * - Modular C programming
 * - File I/O operations
 * - Random number generation
 * - Input validation
 * - Score tracking system
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "UserInput.h"
#include "RNG_Module.h"
#include "FileHandling.h"
#include "Scoring.h"

#define MAX_FILENAME 256

/**
 * Displays the main menu and gets user's difficulty choice
 * @return User's choice (1 for easy, 2 for hard)
 */
int get_difficulty_choice(void) {
    int choice;
    printf("\n=== Number Guesser Game ===\n");
    printf("Select difficulty level:\n");
    printf("1. Easy (1-100)\n");
    printf("2. Hard (1-500)\n");
    printf("Enter your choice: ");
    
    if (scanf("%d", &choice) != 1) {
        printf("Invalid input. Please enter a number.\n");
        return -1;
    }
    
    return choice;
}

/**
 * Plays the game based on selected difficulty
 * @param difficulty 1 for easy, 2 for hard
 * @return Number of attempts taken, or -1 on error
 */
int play_game(int difficulty) {
    int user_guess;
    int attempts = 0;
    
    if (difficulty == 1) {
        int random_number = generate_random_number();
        printf("\nGuess the number between 1 and 100!\n");
        attempts = CheckUserInput(&user_guess, random_number);
    } else if (difficulty == 2) {
        int random_number = generate_random_hard_number();
        printf("\nGuess the number between 1 and 500!\n");
        attempts = CheckUserInput_Hard(&user_guess, random_number);
    } else {
        printf("Invalid difficulty selection.\n");
        return -1;
    }
    
    return attempts;
}

/**
 * Handles score tracking and display
 * @param attempts Number of attempts taken
 */
void handle_scoring(int attempts) {
    /* Load and check high score */
    int best_score = load_high_score();
    
    if (attempts < best_score) {
        save_high_score(attempts);
        printf("\nNew personal best! You guessed it in %d attempts!\n", attempts);
    } else {
        printf("\nYou took %d attempts. Your best score is %d attempts.\n", 
               attempts, best_score);
    }
    
    /* Update score history */
    int history[HISTORY_SIZE];
    load_score_history(history, HISTORY_SIZE);
    update_score_history(history, attempts);
    save_score_history(history, HISTORY_SIZE);
    print_score_history(history);
}

/**
 * Main game entry point
 */
int main(int argc, char* argv[]) {
    /* Validate command line arguments */
    if (argc != 2) {
        printf("Usage: %s <savefile>\n", argv[0]);
        printf("Example: %s game_save.txt\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    /* Validate save file */
    char save_file[MAX_FILENAME];
    strncpy(save_file, argv[1], MAX_FILENAME - 1);
    save_file[MAX_FILENAME - 1] = '\0';
    
    FILE* file = fopen(save_file, "a");  /* Create if doesn't exist */
    if (!file) {
        printf("Error: Cannot access save file '%s'\n", save_file);
        return EXIT_FAILURE;
    }
    fclose(file);
    
    /* Initialize random number generator */
    init_rng();
    
    /* Get difficulty choice */
    int difficulty = get_difficulty_choice();
    if (difficulty < 1 || difficulty > 2) {
        printf("Invalid choice. Exiting.\n");
        return EXIT_FAILURE;
    }
    
    /* Play the game */
    int attempts = play_game(difficulty);
    if (attempts < 0) {
        printf("Game error occurred.\n");
        return EXIT_FAILURE;
    }
    
    /* Handle scoring */
    handle_scoring(attempts);
    
    printf("\nThanks for playing!\n");
    return EXIT_SUCCESS;
}
