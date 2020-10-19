#include "snake.h"
#include <stdio.h>
#include <stdlib.h>
#include "cprocessing.h"
#include "../Grid/grid.h"
#include "food.h"
#include "GameOver.h"



GRID_ELEMENTS grid[GRID_SIZE];	//Grid Array

/*-------------------------
Snake
--------------------------*/

#define TIMER 0.3f;

typedef enum
{
	RIGHT,
	LEFT,
	UP,
	DOWN

} DIRECTION;

DIRECTION dir = RIGHT;
int snakeSize = 3;

int tailPos = 0;
int snakePos = 0;
int snakeTail[GRID_SIZE];

float time = 0;


/*-------------------------
Graphics
--------------------------*/

CP_Color bgColor;

void SnakeInput(void) 
{
	
	if (CP_Input_KeyTriggered(KEY_W) && dir != DOWN)
	{
		dir = UP;
	}
	else if (CP_Input_KeyTriggered(KEY_S) && dir != UP)
	{
		dir = DOWN;
	}
	else if (CP_Input_KeyTriggered(KEY_A) && dir != RIGHT)
	{
		dir = LEFT;
	}
	else if (CP_Input_KeyTriggered(KEY_D) && dir != LEFT)
	{
		dir = RIGHT;
	}
}

void CollisionUpdate(int newPos) 
{

	if (grid[newPos] == GE_WALL || grid[newPos] == GE_SNAKE) 
	{
		//LOSE GAME
		CP_Engine_SetNextGameState(GameOverInit, GameOverUpdate, GameOverExit);
	}
	else 
	{
		if (grid[newPos] == GE_FOOD) 
		{
			SpawnFood(grid, GRID_SIZE);
		}

		unsigned int i = snakeSize - 1;
		do {

			if (i == 0) snakeTail[i] = newPos;
			else
			{
				if (i == (unsigned int)((snakeSize - 1)) )
				{
					if (grid[newPos] == GE_FOOD)	//Check for Food
					{
						snakeTail[snakeSize] = snakeTail[i];
						snakeSize += 1;
					}
					else
					{
						grid[snakeTail[i]] = GE_VOID;	
					}

				} 
				
				snakeTail[i] = snakeTail[i - 1];
			}
			grid[snakeTail[i]] = GE_SNAKE;
			snakePos = newPos;
			if (i == 0) break;
			i--;


		} while (1);
		
	}

	


}
void MovementUpdate(void)
{
	int i = 0;
	switch (dir)
	{
		case UP:
			i = snakePos - GRID_WIDTH;
			CollisionUpdate(i);
			break;
		case DOWN:
			i = snakePos + GRID_WIDTH;
			CollisionUpdate(i);
			break;
		case LEFT:
			i = snakePos - 1;
			CollisionUpdate(i);
			break;
		case RIGHT:
			i = snakePos + 1;
			CollisionUpdate(i);
			break;
	}
}

//Draw Call, maybe can relocate this as well
void SnakeDraw(void)
{
	CP_Settings_Background(bgColor);
	GridUpdate(grid);
	//CP_IMAGE cm = CP_Image_Load
	//CP_Image_Draw(

}


void SnakeInit(void)
{
	bgColor = CP_Color_Create(0, 0, 0, 255);
	GridInit(grid);

	snakePos = GRID_SIZE / 2 - (GRID_WIDTH / 2);
	for (int i = 0; i < snakeSize; i++)
	{
		grid[GRID_SIZE / 2 - (GRID_WIDTH / 2) - i] = GE_SNAKE;
		snakeTail[i] = snakePos - i;
	}

	SpawnFood(grid, GRID_SIZE);
}

void SnakeUpdate(void)
{
	/*Input Checking*/
	SnakeInput();

	/*Game Update*/
	time -= CP_System_GetDt();
	if (time <= 0)
	{
		MovementUpdate();
		time = TIMER;
	}

	

	/*Draw Call*/
	SnakeDraw();
}

void SnakeExit(void)
{

}