#pragma once
#include "snake.h"
#include <stdlib.h>
#include "cprocessing.h"
#include "../Grid/grid.h"
#include "../Food/food.h"

int foodPosition;
CP_Color bgColor;

//Draw Call, maybe can relocate this as well
void Snake_Draw(void)
{
	CP_Settings_Background(bgColor);
	
	Grid_Update();
}


void snake_init(void)
{
	bgColor = CP_Color_Create(0, 0, 0, 255);
	spawn_food(foodPosition);
	Grid_Init();
}

void snake_update(void)
{
	Snake_Draw();
}

void snake_exit(void)
{

}