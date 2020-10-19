#include <cprocessing.h>
#include "snake.h"
#include "../UI/button.h"

float textSize = 50.0f;
CP_Color textColor;

Button buttons[2];

/*Button Functions*/
void retryOnClick(void) 
{
	CP_Engine_SetNextGameState(SnakeInit, SnakeUpdate, SnakeExit);
}

void exityOnClick(void)
{
	CP_Engine_Terminate();
}



void GameOverInit(void)
{
	textColor = CP_Color_Create(255, 255, 255, 255);
	CP_Settings_TextSize(textSize);
	CP_Settings_Fill(textColor);
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_MIDDLE);
	CP_Font_DrawText("GameOver", CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 2.0f);


	/*Button retry;

	retry.name = "retry";
	retry.text = "retry";

	retry.x = CP_System_GetWindowWidth() / 2.0f;
	retry.y = CP_System_GetWindowHegith() / 2.0f + 100.0f; //100.0f is not good
	retry.width = 100.0f;
	retry.height = 75.0f;

	retry.colorFont = CP_Color_Create(0, 0, 0, 255);
	retry.colorDefault = CP_Color_Create(255, 255, 255, 255);
	retry.colorHover = CP_Color_Create(100, 100, 100, 255);

	retry.onClick = &retryOnClick,

		
	buttons[0] = retry;*/
}

void GameOverUpdate(void)
{

}

void GameOverExit(void)
{

}