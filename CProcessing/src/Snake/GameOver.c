#include <cprocessing.h>
#include "../UI/button.h"

float textSize = 50.0f;
CP_Color textColor;

BU

void GameOverInit(void)
{
	textColor = CP_Color_Create(255, 255, 255, 255);
	CP_Settings_TextSize(textSize);
	CP_Settings_Fill(textColor);
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_MIDDLE);
	CP_Font_DrawText("GameOver", CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 2.0f);
}

void GameOverUpdate(void)
{

}

void GameOverExit(void)
{

}