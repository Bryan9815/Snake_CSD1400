#include "snake.h"
#include <stdio.h>
#include <stdlib.h>
#include "cprocessing.h"
#include "../Grid/grid.h"
#include "food.h"


/*-------------------------
This is for casting a grid
--------------------------*/

#define GRID_WIDTH 24							//Set the horizontal length
#define GRID_HEIGHT 18							//Set the vertical length

#define GRID_SIZE GRID_WIDTH*GRID_HEIGHT		//Total size

GRID_ELEMENTS grid[GRID_SIZE];	//Grid Array

/*-------------------------
Snake
--------------------------*/

#define Delta 0.3f;

typedef enum
{
	RIGHT,
	LEFT,
	UP,
	DOWN

} DIRECTION;

DIRECTION dir = RIGHT;
int snakeSize = 1;

int snakePos = 0;
int snakeTail[GRID_SIZE];

float speed = 0;


/*-------------------------
Graphics
--------------------------*/

CP_Color bgColor;



//Draw Call, maybe can relocate this as well
void Snake_Draw(void)
{
	CP_Settings_Background(bgColor);
	GridUpdate(grid, GRID_WIDTH, GRID_HEIGHT);

}


void snake_init(void)
{
	bgColor = CP_Color_Create(0, 0, 0, 255);
	GridInit(grid, GRID_WIDTH, GRID_HEIGHT);

	for (int i = 0; i < snakeSize; i++)
	{
		grid[GRID_SIZE / 2 - (GRID_WIDTH / 2) - i] = GE_SNAKE;
		snakePos = GRID_SIZE / 2 - (GRID_WIDTH / 2) - i;
	}

	
}

void snake_update(void)
{
	//CP_Input_KeyTriggered
	speed -= CP_System_GetDt();
	if (CP_Input_KeyTriggered(KEY_W))
	{
		dir = UP;
	}
	else if (CP_Input_KeyTriggered(KEY_S))
	{
		dir = DOWN;
	}
	else if (CP_Input_KeyTriggered(KEY_A))
	{
		dir = LEFT;
	}
	else if (CP_Input_KeyTriggered(KEY_D))
	{
		dir = RIGHT;
	}
	
	if (speed <= 0) 
	{
		switch (dir)
		{
		case UP:
			if (grid[snakePos - GRID_WIDTH] != GE_WALL) 
			{
				grid[snakePos - GRID_WIDTH] = GE_SNAKE;
				grid[snakePos] = GE_VOID;
				snakePos = snakePos - GRID_WIDTH;
			}
			break;
		case DOWN:
			if (grid[snakePos + GRID_WIDTH] != GE_WALL) 
			{
				grid[snakePos + GRID_WIDTH] = GE_SNAKE;
				grid[snakePos] = GE_VOID;
				snakePos = snakePos + GRID_WIDTH;
			}
			break;
		case LEFT:
			if (grid[snakePos - 1] != GE_WALL) 
			{
				grid[snakePos - 1] = GE_SNAKE;
				grid[snakePos] = GE_VOID;
				snakePos = snakePos - 1;
			}
			break;
		case RIGHT:
			if (grid[snakePos + 1] != GE_WALL) 
			{
				grid[snakePos + 1] = GE_SNAKE;
				grid[snakePos] = GE_VOID;
				snakePos = snakePos + 1;
			}
			break;
		}
		speed = Delta;
	}

	Snake_Draw();
}

void snake_exit(void)
{

}