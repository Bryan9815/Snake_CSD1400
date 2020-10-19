#include "../../CProcessing/inc/cprocessing.h"
#include "score.h"
#include "../Food/food.h"
#include <stdio.h>

int AddScore() //function for time-based score
{
	int ScorePerFrame = (int)(CP_System_GetDt() * 60); //score increases by 60 per sec
	return ScorePerFrame;
}

void DisplayScore(int score) //function to display the score on screen
{
	char scoreBuffer[15]; //buffer for value of score
	sprintf_s(scoreBuffer, 15, "Score: %d", score); // print score into buffer

	CP_Color textColor = CP_Color_Create(255, 255, 255, 255); //set text to white, size to 20
	CP_Settings_Fill(textColor);
	CP_Settings_TextSize(20);
	CP_Font_DrawText(scoreBuffer, 30.f, 40.f); //display score at top left corner
}