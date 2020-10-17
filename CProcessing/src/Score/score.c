#include "../../CProcessing/inc/cprocessing.h"
#include "score.h"
#include <stdlib.h>

int AddScore(void) //function for time-based score
{
	int ScorePerSec = (int)(CP_System_GetDt() * 60); //score increases by 60 per sec
	return ScorePerSec;
}

void DisplayScore(int score) //function to display the score on screen
{
	char scoreBuffer[7]; //separate buffer for value of score
	_itoa_s(score, scoreBuffer, 7, 10); //convert score value to string
	char scoreString[15] = {'S','c','o','r','e',':','\0'}; //buffer for full string
	strcat_s(scoreString, 15, scoreBuffer); //adds score value to the end of "Score: "
	
	CP_Color textColor = CP_Color_Create(0, 255, 255, 255); //set text to white
	CP_Settings_Fill(textColor);
	CP_Settings_TextSize(20);
	CP_Font_DrawText(scoreString, 30.f, 40.f); //display score
}