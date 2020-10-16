#include "food.h"
#include <cprocessing.h>

void spawn_food(CP_Vector food_pos)
{
	food_pos = CP_Vector_Set(CP_Random_RangeFloat(0.f, 1.0f), CP_Random_RangeFloat(0.f, 1.0f));
}

void eat_food(CP_Vector snake_head_pos, CP_Vector food_pos)
{
	if (CP_Vector_Distance(snake_head_pos,food_pos) == 0)
	{
		spawn_food(food_pos);
	}
}