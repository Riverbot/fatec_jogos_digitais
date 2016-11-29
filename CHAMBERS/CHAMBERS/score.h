#pragma once

typedef struct Score {
	int score;
	char* txtScore;
	void (*SumScore)();
}Score;

void ConstructStructFuncScore(Score* f);
