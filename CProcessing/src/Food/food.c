#include "food.h"
#include "../../CProcessing/inc/cprocessing.h"
#include "../Grid/grid.h"
#include <stdio.h>
#include "../Score/score.h"

//function for setting food position
int Spawn_Food(GRID_ELEMENTS *grid, int food_number)
{
	static int timer = 0;
	if (timer % (int)(4 * CP_System_GetFrameRate()) == 0 && food_number < 5) //1 food spawns every 4 sec if <5 food
	{
		int food_pos = 0;
		do
			food_pos = CP_Random_RangeInt(0, GRID_SIZE); // spawn food randomly within grid
		while ((food_pos % GRID_WIDTH) <= 1 || (food_pos % GRID_WIDTH) >= (GRID_WIDTH - 2)  //redo if food near or within sides
			|| (food_pos / GRID_WIDTH) <= 1 || (food_pos / GRID_WIDTH) >= (GRID_HEIGHT - 1) //redo if food near or within top or bottom
			|| grid[food_pos] == GE_SNAKE || grid[food_pos] == GE_TAIL); //redo if inside snake
		grid[food_pos] = GE_FOOD;
		timer=0;
		food_number++;
	}
	timer++;
	return food_number;
}