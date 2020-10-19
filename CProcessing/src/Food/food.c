#include "food.h"
#include "../../CProcessing/inc/cprocessing.h"
#include "../Grid/grid.h"
#include <stdio.h>
#include "../Score/score.h"

//function for setting food position
void Spawn_Food(GRID_ELEMENTS *grid)
{
	static int timer = 0;
	if (timer % (int)(4 * CP_System_GetFrameRate()) == 0) //1 food spawns every 4 sec
	{
		int food_pos = 0;
		do
			food_pos = CP_Random_RangeInt(0, GRID_SIZE); // spawn food randomly within grid
		while ((food_pos % GRID_WIDTH) <= 1 || (food_pos % GRID_WIDTH) >= (GRID_WIDTH - 2)  //redo if food near or within sides
			|| (food_pos / GRID_WIDTH) <= 1 || (food_pos / GRID_WIDTH) >= (GRID_HEIGHT - 1)); //redo if food near or within top or bottom
		grid[food_pos] = GE_FOOD;
		timer=0;
	}
	timer++;
}