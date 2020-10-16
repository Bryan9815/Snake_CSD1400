
//Grid that stores the GRID_ELEMENTS type
typedef enum
{
	GE_VOID,		//Empty
	GE_WALL,		//Wall
	GE_SNAKE,		//Snake
	GE_FOOD			//Food

}GRID_ELEMENTS;	

void GridInit(GRID_ELEMENTS* grid, int gridW, int gridH);
void GridUpdate(GRID_ELEMENTS* grid, int gridW, int gridH);