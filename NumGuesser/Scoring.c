/**
 * Scoring System Implementation
 * Tracks and displays game scores and history
 */

/**
 * Scoring System Implementation
 * Handles score history tracking and display
 */

#include <stdio.h>
#include "Scoring.h"

/**
 * Updates score history by shifting left and adding new score
 * @param history Array of previous scores
 * @param new_score Latest score to add
 */
void update_score_history(int* history, int new_score) {
    /* Shift all scores left by one position */
    for (int i = 0; i < HISTORY_SIZE - 1; i++) {
        history[i] = history[i + 1];
    }
    /* Add new score at the end */
    history[HISTORY_SIZE - 1] = new_score;
}

/**
 * Prints the score history in a formatted manner
 * @param history Array of scores to display
 */
void print_score_history(const int* history) {
    printf("\n=== Recent Game History ===\n");
    
    int games_played = 0;
    for (int i = 0; i < HISTORY_SIZE; i++) {
        if (history[i] > 0) {
            printf("Game %d: %d attempts\n", ++games_played, history[i]);
        }
    }
    
    if (games_played == 0) {
        printf("No previous games recorded.\n");
    }
}
