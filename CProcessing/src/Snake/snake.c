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
	int			snakePos;
	float		delay;
	direction	dir;

}snake;

typedef enum
{
	MAIN_MENU,
	GAME,
	GAME_OVER,
}GameState;

CP_Color snakeColor;
snake s;
int tail[100];
int tailSize = 1;
GameState gameState;
float defaultDelay;

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
	grid[s.snakePos] = GE_SNAKE;
	for (int i = 0; i < tailSize; i++) // Tail
	{
		grid[tail[i]] = GE_TAIL;
	}
}

//Initialize snake variables
void Snake_Create(void)
{
	s.dir = CP_Random_RangeInt(1, 4);
	s.delay = CP_System_GetDt();
	s.snakePos = GRID_SIZE / 2 - (GRID_WIDTH / 2);
	for (int i = 0; i < tailSize; i++)
	{
		switch (s.dir)
		{
		case LEFT:
			tail[i] = s.snakePos + i;
			break;
		case RIGHT:
			tail[i] = s.snakePos - i;
			break;
		case UP:
			tail[i] = s.snakePos + GRID_WIDTH * i;
			break;
		case DOWN:
			tail[i] = s.snakePos - GRID_WIDTH * i;
			break;
		default:
			break;
		}
	}
	defaultDelay = 7.0f;
}

void snake_init(void)
{
	bgColor = CP_Color_Create(0, 0, 0, 255);
	Score = 0;
	Grid_Init(grid);
	Snake_Create();
	gameState = GAME;
}

void Snake_Death(void)
{
	gameState = GAME_OVER;
}

//Snake Direction
void Snake_Movement(void)
{
	if (CP_Input_KeyTriggered(KEY_UP) && (s.dir != DOWN))
	{
		s.dir = UP;
	}

	else if (CP_Input_KeyTriggered(KEY_DOWN) && (s.dir != UP))
	{
		s.dir = DOWN;
	}

	else if (CP_Input_KeyTriggered(KEY_LEFT) && (s.dir != RIGHT))
	{
		s.dir = LEFT;
	}

	else if (CP_Input_KeyTriggered(KEY_RIGHT) && (s.dir != LEFT))
	{
		s.dir = RIGHT;
	}
	if (CP_Input_KeyTriggered(KEY_R))
	{
		snake_init();
	}
}

//Constant Snake Movement
void Snake_Update_Position(void)
{
	if (s.delay >= defaultDelay)
	{
		int oldSnakePos = s.snakePos;

		switch (s.dir) //Compute snake movement
		{
		case LEFT:
			s.snakePos--;
			break;

		case RIGHT:
			s.snakePos++;
			break;

		case UP:
			s.snakePos -= GRID_WIDTH;
			break;

		case DOWN:
			s.snakePos += GRID_WIDTH;
			break;

		default:
			break;
		}
		if (grid[s.snakePos] == GE_WALL || grid[s.snakePos] == GE_TAIL) //Wall and Tail collision check
			Snake_Death();
		else //Update Snake Position
		{
			for (int i = 0; i < tailSize; i++) // Wipe old snake & tail positions
			{
				grid[tail[i]] = GE_VOID;
			}
			for (int i = tailSize - 1; i > 0; i--) //Update Tail position;
			{
				tail[i] = tail[i - 1];
				grid[tail[i]] = GE_TAIL;
			}
			tail[0] = oldSnakePos;
			grid[tail[0]] = GE_TAIL;
			if (grid[s.snakePos] == GE_FOOD) //Eat food
			{
				Score += 50;
				tailSize++;
				tail[tailSize - 1] = tail[tailSize - 2];
			}
			grid[s.snakePos] = GE_SNAKE; //Draw snake head at updated position
		}
		s.delay = CP_System_GetDt() - s.delay;
	}
	else
	{
		s.delay += 1;
	}
}

void snake_update(void)
{
	switch (gameState)
	{
	case(GAME):
		Spawn_Food(grid);
		Snake_Draw();
		Snake_Update_Position();
		Snake_Movement();
		Score += AddScore();
		DisplayScore(Score);
		break;
	case(GAME_OVER):
		CP_Settings_Background(bgColor);
		break;
	default:
		break;
	}
}

void snake_exit(void)
{

}