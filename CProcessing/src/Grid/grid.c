#include <stdio.h>
#include <stdlib.h>
#include <cprocessing.h>

/*-------------------------
This is for casting a grid
--------------------------*/

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

}GRID_ELEMENTS;	//@todo Might want to relocate to header file

//Grid that stores the GRID_ELEMENTS type
GRID_ELEMENTS grid[GRID_SIZE];	//@todo Might want to relocate to snake, or I can make a getter to return this variable

/*Initialize Grid*/
void Grid_Init(void) 
{
	//Boundary
	for (int i = 0; i < GRID_SIZE; i++) {

		if (	i < GRID_WIDTH												/*Top Boundary*/
			|| (i % GRID_WIDTH) == 0										/*Left Boundary*/
			|| (i % GRID_WIDTH) == GRID_WIDTH - 1							/*Right Boundary*/
			|| i >= (GRID_HEIGHT - 1) * GRID_WIDTH  && i < GRID_SIZE		/*Bottom Boundary*/
			) {
			grid[i] = GE_WALL;												//Set Grid element to wall
		}
		else 
		{
			grid[i] = GE_VOID;												//Empty Element
		}
		
	}
}

/*Draw Call/Update Function for Grid*/
void Grid_Update(void)
{
	//Checks thru all the elements
	for (int i = 0; i < GRID_SIZE; i++) 
	{
		
		switch (grid[i]) 
		{
		case GE_WALL:
			CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
			CP_Graphics_DrawRect(
				(CP_System_GetWindowWidth() / (float)GRID_WIDTH) * (i % GRID_WIDTH),
				(CP_System_GetWindowHeight() / (float)GRID_HEIGHT) * (i / GRID_WIDTH),
				CP_System_GetWindowWidth() / (float)GRID_WIDTH,
				CP_System_GetWindowHeight() / (float)GRID_HEIGHT);
			break;
		case GE_VOID:
			break;

		}
	}
}