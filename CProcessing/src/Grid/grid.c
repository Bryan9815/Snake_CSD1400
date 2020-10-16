#include <stdio.h>
#include <stdlib.h>
#include <cprocessing.h>

//Different type of elements store for the array;


//Grid that stores the GRID_ELEMENTS type

typedef enum
{
	GE_VOID,		//Empty
	GE_WALL,		//Wall
	GE_SNAKE,		//Snake
	GE_FOOD			//Food

}GRID_ELEMENTS;	//@todo Might want to relocate to header file

/*Initialize Grid*/
void GridInit(GRID_ELEMENTS* grid, int gridW, int gridH)
{

	//Boundary
	for (int i = 0; i < gridW * gridH; i++) {

		if (	i < gridW												/*Top Boundary*/
			|| (i % gridW) == 0										/*Left Boundary*/
			|| (i % gridW) == gridW - 1							/*Right Boundary*/
			|| i >= (gridH - 1) * gridW && i < gridW * gridH		/*Bottom Boundary*/
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
void GridUpdate(GRID_ELEMENTS* grid, int gridW, int gridH)
{
	//Checks thru all the elements
	for (int i = 0; i < gridW * gridH; i++)
	{
		
		switch (grid[i]) 
		{
		case GE_WALL:
			CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
			CP_Graphics_DrawRect(
				(CP_System_GetWindowWidth() / (float)gridW) * (i % gridW),
				(CP_System_GetWindowHeight() / (float)gridH) * (i / gridW),
				CP_System_GetWindowWidth() / (float)gridW,
				CP_System_GetWindowHeight() / (float)gridH);
			break;
		case GE_VOID:
			break;

		}
	}
}