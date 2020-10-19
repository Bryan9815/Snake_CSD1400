#pragma once
#include "snake.h"
#include <stdlib.h>
#include "cprocessing.h"
#include "../Grid/grid.h"
#include "../Food/food.h"
#include "../Score/score.h"

//snake object
typedef struct
{
	CP_Vector	snakePos;
	int			radius;
	int			delay;
	direction	dir;

}snake;

CP_Color snakeColor;
snake s;
int defaultDelay = 20;

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

//Draw the snake's head
void Snake_Display(void)
{
	CP_Settings_Fill(snakeColor);
	CP_Settings_EllipseMode(CP_POSITION_CENTER);
	CP_Graphics_DrawCircle((s.snakePos.x / GRID_WIDTH) * CP_System_GetWindowWidth(),
		(s.snakePos.y / GRID_HEIGHT) * CP_System_GetWindowHeight(),
		(float)s.radius);
}

//Initialize snake variables
void Snake_Create(void)
{
	snakeColor = CP_Color_Create(255, 100, 100, 255);
	s.snakePos.x = GRID_WIDTH / 2;
	s.snakePos.y = GRID_HEIGHT / 2;
	s.radius = 40;
	s.dir = CP_Random_RangeInt(1, 4);
	s.delay = defaultDelay;
}

//Snake Direction
void Snake_Movement(void)
{
	if (CP_Input_KeyTriggered(KEY_UP) && (s.dir != DOWN))
	{
		s.dir = UP;
		s.snakePos.y -= 1;
	}

	else if (CP_Input_KeyTriggered(KEY_DOWN) && (s.dir != UP))
	{
		s.dir = DOWN;
		s.snakePos.y += 1;
	}

	else if (CP_Input_KeyTriggered(KEY_LEFT) && (s.dir != RIGHT))
	{
		s.dir = LEFT;
		s.snakePos.x -= 1;
	}

	else if (CP_Input_KeyTriggered(KEY_RIGHT) && (s.dir != LEFT))
	{
		s.dir = RIGHT;
		s.snakePos.x += 1;
	}
	
}

//Constant Snake Movement
void Snake_Update_Position(void)
{
	if (s.delay == defaultDelay)
	{
		switch (s.dir)
		{
		case LEFT:
			s.snakePos.x -= 1;
			break;

		case RIGHT:
			s.snakePos.y += 1;
			break;

		case UP:
			s.snakePos.y -= 1;
			break;

		case DOWN:
			s.snakePos.y += 1;
			break;

		default:
			break;
		}

		s.delay = 0;
	}
	else
	{
		s.delay += 1;
	}

}

void snake_init(void)
{
	bgColor = CP_Color_Create(0, 0, 0, 255);
	Grid_Init(grid);
	Score = 0;
	Spawn_Food(grid);
	Snake_Create();
}

void snake_update(void)
{
	Snake_Draw();
	Snake_Display();
	Snake_Update_Position();
	Snake_Movement();
	Score += AddScore();
	DisplayScore(Score);
}

void snake_exit(void)
{

}