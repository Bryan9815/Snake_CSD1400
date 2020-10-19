#include "food.h"
#include "../../CProcessing/inc/cprocessing.h"
#include "../Grid/grid.h"
#include <stdio.h>

//function for setting food position
void Spawn_Food(GRID_ELEMENTS *grid)
{
	int food_pos;
	do
		food_pos = CP_Random_RangeInt(0, GRID_SIZE); // spawn food randomly within grid
	while ((food_pos % GRID_WIDTH) <= 1 || (food_pos % GRID_WIDTH) >= (GRID_WIDTH - 2)  //redo if food near or within sides
		|| (food_pos / GRID_WIDTH) <= 1 || (food_pos / GRID_WIDTH) >= (GRID_HEIGHT - 1)); //redo if food near or within top or bottom
	grid[food_pos] = GE_FOOD;
}

//function for checking if snake eats food
int Eat_Food(int snake_head_pos, int food_pos, GRID_ELEMENTS *grid)
{
	int foodscore = 0;
	if (snake_head_pos == food_pos) // if snake head is in the same grid as food
	{
		Spawn_Food(grid); //respawn food somewhere else
		foodscore = 200; //add 200 to score
	}
	return foodscore;
}