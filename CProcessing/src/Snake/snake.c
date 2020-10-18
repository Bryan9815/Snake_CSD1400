#pragma once
#include "snake.h"
#include <stdlib.h>
#include "cprocessing.h"
#include "../Grid/grid.h"
#include "../Food/food.h"
#include "../Score/score.h"

int foodPosition;
int Score;
CP_Color bgColor;

//Grid that stores the GRID_ELEMENTS type
GRID_ELEMENTS grid[GRID_SIZE];

//Draw Call, maybe can relocate this as well
void Snake_Draw(void)
{
	CP_Settings_Background(bgColor);
	Grid_Update(grid);
}


void snake_init(void)
{
	bgColor = CP_Color_Create(0, 0, 0, 255);
	spawn_food(foodPosition);
	Score = 0;
	Grid_Init(grid);
}

void snake_update(void)
{
	Snake_Draw();
	Score += AddScore();
	DisplayScore(Score);
}

void snake_exit(void)
{

}