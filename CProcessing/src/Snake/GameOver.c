#include "GameOver.h"
#include "../../CProcessing/inc/cprocessing.h"
#include <stdio.h>

int finalScore = 0;
CP_Color bgColor;

typedef enum
{
	RETRY,
	QUIT,
}Button;

Button button;

void GameOver_init(int score)
{
	finalScore = score;
	bgColor = CP_Color_Create(0, 0, 0, 255);
	button = RETRY;
}

void DrawScreen(void)
{
	char scoreBuffer[15]; //buffer for value of score
	sprintf_s(scoreBuffer, 15, "Score: %d", finalScore); // print score into buffer

	CP_Color textColor = CP_Color_Create(255, 255, 255, 255);
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_BASELINE);
	CP_Settings_Fill(textColor);
	CP_Settings_TextSize(48);
	CP_Font_DrawText(scoreBuffer, (float)CP_System_GetWindowWidth() / 2, (float) CP_System_GetWindowHeight() / 3); //Display score
	if (button == RETRY)
	{
		textColor = CP_Color_Create(0, 255, 0, 255);
		CP_Settings_Fill(textColor);
		CP_Font_DrawText("RETRY", (float)CP_System_GetWindowWidth() / 2, (float)CP_System_GetWindowHeight() / 2); //Display score
		textColor = CP_Color_Create(255, 255, 255, 255);
		CP_Settings_Fill(textColor);
		CP_Font_DrawText("QUIT", (float)CP_System_GetWindowWidth() / 2, (float)CP_System_GetWindowHeight() / 2+50); //Display score
	}
	else
	{
		CP_Font_DrawText("RETRY", (float)CP_System_GetWindowWidth() / 2, (float)CP_System_GetWindowHeight() / 2); //Display score
		textColor = CP_Color_Create(0, 255, 0, 255);
		CP_Settings_Fill(textColor);
		CP_Font_DrawText("QUIT", (float)CP_System_GetWindowWidth() / 2, (float)CP_System_GetWindowHeight() / 2 + 50); //Display score
	}
}

int GameOver_Input(void)
{
	switch (button)
	{
	case RETRY:
		if(CP_Input_KeyTriggered(KEY_UP) || CP_Input_KeyTriggered(KEY_DOWN))
			button = QUIT;
		if (CP_Input_KeyTriggered(KEY_SPACE))
			return 1;
		break;
	case QUIT:
		if(CP_Input_KeyTriggered(KEY_UP) || CP_Input_KeyTriggered(KEY_DOWN))
			button = RETRY;
		if (CP_Input_KeyTriggered(KEY_SPACE))
			return 0;
		break;
	default:
		break;
	}
	return 2;
}

int GameOver_update(void)
{
	CP_Settings_Background(bgColor);
	DrawScreen();
	return GameOver_Input();
}

void GameOver_exit(void)
{

}