#include "Score.h"

Score::Score() { }

Score::~Score() { }

void Score::AddScore(int point) {
    points += point;
}

void Score::RetractScore(int point) {
    points -= point;
}

int Score::GetScore() {
    return points;
}