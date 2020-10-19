#include <stdio.h>
#include <stdlib.h>
#include <cprocessing.h>
#include "grid.h"

/*Debug Flag*/
#define debug false

/*Initialize Grid*/
void Grid_Init(GRID_ELEMENTS* grid)
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
void Grid_Update(GRID_ELEMENTS* grid)
{
	//Checks thru all the elements
	for (int i = 0; i < GRID_SIZE; i++) 
	{
#if !debug
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
		case GE_FOOD:
			CP_Settings_Fill(CP_Color_Create(255, 0, 255, 255));
			CP_Settings_EllipseMode(CP_POSITION_CORNER);
			CP_Graphics_DrawEllipse(
				(CP_System_GetWindowWidth() / (float)GRID_WIDTH) * (i % GRID_WIDTH),
				(CP_System_GetWindowHeight() / (float)GRID_HEIGHT) * (i / GRID_WIDTH),
				CP_System_GetWindowWidth() / (float)GRID_WIDTH,
				CP_System_GetWindowHeight() / (float)GRID_HEIGHT);
			break;
		case GE_SNAKE:
			CP_Settings_Fill(CP_Color_Create(255, 0, 255, 255));
			CP_Graphics_DrawRect(
				(CP_System_GetWindowWidth() / (float)GRID_WIDTH) * (i % GRID_WIDTH),
				(CP_System_GetWindowHeight() / (float)GRID_HEIGHT) * (i / GRID_WIDTH),
				CP_System_GetWindowWidth() / (float)GRID_WIDTH,
				CP_System_GetWindowHeight() / (float)GRID_HEIGHT);
			break;
		case GE_TAIL:
			CP_Settings_Fill(CP_Color_Create(255, 0, 255, 255));
			CP_Graphics_DrawRect(
				(CP_System_GetWindowWidth() / (float)GRID_WIDTH) * (i % GRID_WIDTH),
				(CP_System_GetWindowHeight() / (float)GRID_HEIGHT) * (i / GRID_WIDTH),
				CP_System_GetWindowWidth() / (float)GRID_WIDTH,
				CP_System_GetWindowHeight() / (float)GRID_HEIGHT);
			break;
		case GE_VOID:
			break;

		}
#endif
	}

#if debug
	char _buffer[20];
	snprintf(_buffer, 20, "%d", i - '0');
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	CP_Font_DrawText(_buffer,
		(CP_System_GetWindowWidth() / (float)gridW) * (i % gridW),
		(CP_System_GetWindowHeight() / (float)gridH) * (i / gridW));

#endif	
}