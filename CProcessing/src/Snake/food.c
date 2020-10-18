#include <cprocessing.h>
#include "../Grid/grid.h"

void SpawnFood(GRID_ELEMENTS *grid, int gridSize)
{
	do 
	{
		int i = CP_Random_RangeInt(0, (unsigned int)gridSize);
		if (grid[i] != GE_VOID) continue;
		else 
		{
			grid[i] = GE_FOOD;
			break;
		}

	} while (1);
}

void eat_food(CP_Vector snake_head_pos, CP_Vector food_pos)
{
	/*if (CP_Vector_Distance(snake_head_pos,food_pos) == 0)
	{
		spawn_food(food_pos);
	}*/
}