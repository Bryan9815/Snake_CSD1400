#include "MainMenu.h"
#include "Cprocessing.h"
#include "snake.h"

CP_Color fontColour, titlefontColour, bgColour;

void MainMenu_init(void)
{
	titlefontColour = CP_Color_Create(255, 0, 0, 255);
	fontColour = CP_Color_Create(255, 255, 255, 255);
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_MIDDLE);
	bgColour = CP_Color_Create(0, 0, 0, 255);
}

void MainMenu_update(void)
{
	CP_Settings_Background(bgColour);
	CP_Settings_Fill(titlefontColour);
	CP_Settings_TextSize(CP_System_GetWindowWidth() / 10.0f);
	CP_Font_DrawText("SNAKE", CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 2.5f);

	CP_Settings_Fill(fontColour);
	CP_Settings_TextSize(CP_System_GetWindowWidth() / 30.0f);
	CP_Font_DrawText("Press Space to Begin", CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 1.5f);

	if (CP_Input_KeyTriggered(KEY_SPACE))
	{
		CP_Engine_SetNextGameState(snake_init, snake_update, snake_exit);
	}
}

void MainMenu_exit(void)
{

}