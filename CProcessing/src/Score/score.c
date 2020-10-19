#include "../../CProcessing/inc/cprocessing.h"
#include "score.h"
#include <stdio.h>

float AddScore() //function for time-based score
{
	float ScorePerFrame = (CP_System_GetDt() * 20); //score increases by 60 per sec
	return ScorePerFrame;
}

void DisplayScore(float score) //function to display the score on screen
{
	char scoreBuffer[15]; //buffer for value of score
	sprintf_s(scoreBuffer, 15, "Score: %d", (int)score); // print score into buffer

	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_LEFT, CP_TEXT_ALIGN_V_BASELINE);
	CP_Color textColor = CP_Color_Create(255, 255, 255, 255); //set text to white, size to 20
	CP_Settings_Fill(textColor);
	CP_Settings_TextSize(20);
	CP_Font_DrawText(scoreBuffer, 30.f, 40.f); //display score at top left corner
}