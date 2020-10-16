#include <cprocessing.h>

int isFading = 0;
int fadeAlpha = 0;

void StartFade(float fadeSpeed) 
{
	isFading = 1;
}

void StopFade(void) 
{
	fadeAlpha = 0;
}
void UpdateFade(void)
{
	if (!isFading) 
	{
		CP_Settings_Fill(CP_Color_Create(0, 0, 0, fadeAlpha));
	}
		
	CP_Graphics_DrawRect(0, 0, CP_System_GetWindowWidth(), CP_System_GetWindowHeight());
}



