/*-------------------------
This is for casting a grid
--------------------------*/
#pragma once
#define GRID_WIDTH 48							//Set the horizontal length
#define GRID_HEIGHT 36							//Set the vertical length

#define GRID_SIZE GRID_WIDTH*GRID_HEIGHT		//Total size

//Different type of elements store for the array;
typedef enum
{
	GE_VOID,		//Empty
	GE_WALL,		//Wall
	GE_SNAKE,		//Snake
	GE_FOOD			//Food

}GRID_ELEMENTS;	

void Grid_Init(GRID_ELEMENTS *grid);
void Grid_Update(GRID_ELEMENTS* grid);