
#include <stdlib.h>
#include <cprocessing.h>

#define GRID_WIDTH 50
#define GRID_HEIGHT 50

#define GRID_SIZE GRID_WIDTH*GRID_HEIGHT


typedef enum
{
	GE_VOID,
	GE_WALL,
	GE_SNAKE,
	GE_FOOD

}GRID_ELEMENTS;

GRID_ELEMENTS grid[GRID_SIZE];


void Grid_Init(void) 
{
	//Boundary
	for (int i = 0; i < GRID_SIZE; i++) {

		if (i < GRID_WIDTH
			|| (i % GRID_WIDTH) == 0
			|| (i % GRID_WIDTH) == GRID_WIDTH - 1
			|| i >= (GRID_HEIGHT - 1) * GRID_WIDTH  && i < GRID_SIZE
			) {
			grid[i] = GE_WALL;
		}
		else 
		{
			grid[i] = GE_VOID;
		}
		
	}
}

void Grid_Update(void)
{
	for (int i = 0; i < GRID_SIZE; i++) 
	{
		switch (grid[i]) 
		{
		case GE_WALL:
			CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
			//CP_Settings_RectMode(CP_POSITION_CENTER);
			CP_Graphics_DrawRect(CP_System_GetWindowWidth() / (float)GRID_WIDTH * ((i) /GRID_WIDTH),
				CP_System_GetWindowHeight() / (float)GRID_HEIGHT * ((i ) % GRID_HEIGHT),
				CP_System_GetWindowWidth() / (float)GRID_WIDTH,
				CP_System_GetWindowHeight() / (float)GRID_HEIGHT);
			break;
		case GE_VOID:
			break;

		}
	}
	
}




/*CP_Vector *CreateGridWRWindow(int size, int width, int height) {
	
	
}*/
