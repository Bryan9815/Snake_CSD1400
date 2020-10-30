#pragma once
#include "snake.h"
#include <stdlib.h>
#include "cprocessing.h"
#include "../Grid/grid.h"
#include "../Food/food.h"
#include "../Score/score.h"
#include "GameOver.h"
#include <stdio.h>

typedef enum
{
	GAME,
	GAME_OVER,
	QUIT,
}GameState;

//snake object
typedef struct
{
	int			snakePos;		//Snake Position (grid)
	float		delay;			//Timer for movement delay
	direction	dir,			//current direction
				inputdir;		//input direction

}snake;

CP_Color snakeColor;
snake s;
int tail[GRID_SIZE];
int tailSize;
GameState gameState = GAME;
float defaultDelay;

int foodNumber;
float Score;
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
	s.inputdir = s.dir;
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
	defaultDelay = 10.0f;
}

void snake_init(void)
{
	bgColor = CP_Color_Create(0, 0, 0, 255);
	Score = 0;
	tailSize = 1;
	foodNumber = 0;
	Grid_Init(grid);
	Snake_Create();
}

void Snake_Death(void)
{
	GameOver_init((int)Score);
	gameState = GAME_OVER;
	snake_init();
}

//Snake Direction
void Snake_Movement(void)
{
	if (CP_Input_KeyTriggered(KEY_UP) && (s.dir != DOWN))
	{
		s.inputdir = UP;
	}

	else if (CP_Input_KeyTriggered(KEY_DOWN) && (s.dir != UP))
	{
		s.inputdir = DOWN;
	}

	else if (CP_Input_KeyTriggered(KEY_LEFT) && (s.dir != RIGHT))
	{
		s.inputdir = LEFT;
	}

	else if (CP_Input_KeyTriggered(KEY_RIGHT) && (s.dir != LEFT))
	{
		s.inputdir = RIGHT;
	}

	if (CP_Input_KeyTriggered(KEY_R))
	{
		snake_init();
	}
}

#if 1
//Constant Snake Movement
void Snake_Update_Position(void)
{
	if (s.delay >= defaultDelay)
	{
		int oldSnakePos = s.snakePos;

		switch (s.inputdir) //Compute snake movement
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
		s.dir = s.inputdir;
		if (grid[s.snakePos] == GE_WALL || grid[s.snakePos] == GE_TAIL) //Wall and Tail collision check
			Snake_Death();
		else //Update Snake Position
		{
			for (int i = 0; i < tailSize; i++) // Wipe old snake & tail positions
			{
				grid[tail[i]] = GE_VOID;
			}
			for (int i = tailSize - 1; i > 0; i--) //Update Tail position
			{
				tail[i] = tail[i - 1];
			}
			tail[0] = oldSnakePos;
			grid[tail[0]] = GE_TAIL;
			if (grid[s.snakePos] == GE_FOOD) //Eat food
			{
				Score += 50;
				foodNumber--;
				tailSize++;
				tail[tailSize - 1] = tail[tailSize - 2];
			}
			Snake_Draw(); //Draw snake at updated position
		}
		s.delay = CP_System_GetDt() - s.delay;
	}
	else
	{
		s.delay += 1;
	}
}

#endif


void snake_update(void)
{
	switch (gameState)
	{
	case(GAME):
		foodNumber = Spawn_Food(grid, foodNumber);
		Snake_Draw();
		Snake_Update_Position();
		Snake_Movement();
		Score += AddScore();
		DisplayScore(Score);
		break;
	case(GAME_OVER):
		gameState = GameOver_update();
		break;
	case(QUIT):
		snake_exit();
		break;
	default:
		break;
	}
}

void snake_exit(void)
{
	CP_Engine_Terminate();
}