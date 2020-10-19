#pragma once
#include "../../CProcessing/inc/cprocessing.h"
#include "../Grid/grid.h"

void Spawn_Food(GRID_ELEMENTS *grid);
int Eat_Food(int snake_head_pos, int food_pos, GRID_ELEMENTS *grid);