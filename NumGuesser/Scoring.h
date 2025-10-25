/**
 * Scoring System Header
 * Defines constants and functions for score tracking
 */

#ifndef SCORING_H
#define SCORING_H

#define HISTORY_SIZE 5

/* Function prototypes */
void update_score_history(int* history, int new_score);
void print_score_history(const int* history);

#endif /* SCORING_H */
