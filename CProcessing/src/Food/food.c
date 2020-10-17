#include "food.h"
#include "../../CProcessing/inc/cprocessing.h"
#define GRID_WIDTH 48							//Set the horizontal length
#define GRID_HEIGHT 36							//Set the vertical length
#define GRID_SIZE GRID_WIDTH*GRID_HEIGHT		//Total size

//function for setting food position
int spawn_food(int food_pos)
{
	do
		food_pos = CP_Random_RangeInt(0, GRID_SIZE); // spawn food randomly within grid
	while ((food_pos % GRID_WIDTH) <= 1 || (food_pos % GRID_WIDTH) >= (GRID_WIDTH - 2)  //redo if food near or within sides
		|| (food_pos / GRID_WIDTH) <= 1 || (food_pos / GRID_WIDTH) >= (GRID_HEIGHT - 1)); //redo if food near or within top or bottom
	return food_pos;
}

//function for checking if snake eats food
void eat_food(int snake_head_pos, int food_pos)
{
	if (snake_head_pos == food_pos) // if snake head is in the same grid as food
	{
		spawn_food(food_pos); //respawn food somewhere else
	}
}