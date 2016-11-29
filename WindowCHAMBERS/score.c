#include <stdlib.h>
#include <stdio.h>
#include "global.h"
#include "score.h"


char initializer[1024];
void SumScore(){
	score.txtScore = initializer;
	score.score += 100;
	sprintf(score.txtScore, "%d", score.score);
}

void ConstructStructFuncScore(Score* scr){
	scr->SumScore = SumScore;
}