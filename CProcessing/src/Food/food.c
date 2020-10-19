#include "food.h"
#include "../../CProcessing/inc/cprocessing.h"
#include "../Grid/grid.h"
#include <stdio.h>
#include "../Score/score.h"

//function for setting food position
int Spawn_Food(GRID_ELEMENTS *grid)
{
	int food_pos = 0;
	do
		food_pos = CP_Random_RangeInt(0, GRID_SIZE); // spawn food randomly within grid
	while ((food_pos % GRID_WIDTH) <= 1 || (food_pos % GRID_WIDTH) >= (GRID_WIDTH - 2)  //redo if food near or within sides
		|| (food_pos / GRID_WIDTH) <= 1 || (food_pos / GRID_WIDTH) >= (GRID_HEIGHT - 1)); //redo if food near or within top or bottom
	grid[food_pos] = GE_FOOD;
	return food_pos;
}

//function for checking if snake eats food
void Eat_Food(int score, GRID_ELEMENTS* grid)
{
	Spawn_Food(grid); //respawn food somewhere else
	score += 200;
}