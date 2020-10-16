#include "snake.h"
#include <stdlib.h>
#include "cprocessing.h"
#include "../Grid/grid.h"
#include "food.h"

/*-------------------------
This is for casting a grid
--------------------------*/

#define GRID_WIDTH 48							//Set the horizontal length
#define GRID_HEIGHT 36							//Set the vertical length

#define GRID_SIZE GRID_WIDTH*GRID_HEIGHT		//Total size

GRID_ELEMENTS grid[GRID_SIZE];	//@todo Might want to relocate to snake, or I can make a getter to return this variable

CP_Color bgColor;

int snakeSize = 3;

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
		
	}
}

void snake_update(void)
{
	Snake_Draw();
}

void snake_exit(void)
{

}