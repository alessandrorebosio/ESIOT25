#include "score.h"

static int score = 0;

int getScore(void) { return score; }

void increase(void) { score++; }

void reset(void) { score = 0; }