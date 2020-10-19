
/*-------------------------
This is for casting a grid
--------------------------*/

#define GRID_WIDTH 24							//Set the horizontal length
#define GRID_HEIGHT 18							//Set the vertical length

#define GRID_SIZE GRID_WIDTH*GRID_HEIGHT		//Total size

//Grid that stores the GRID_ELEMENTS type
typedef enum 
{
	GE_VOID,		//Empty
	GE_WALL,		//Wall
	GE_SNAKE,		//Snake
	GE_TAIL,		//TAIL
	GE_FOOD			//Food

}GRID_ELEMENTS;

void GridInit(GRID_ELEMENTS* grid);
void GridUpdate(GRID_ELEMENTS* grid);