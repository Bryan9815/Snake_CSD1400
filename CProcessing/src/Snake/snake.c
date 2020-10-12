#include "snake.h"
#include <stdlib.h>
#include "cprocessing.h"
#include "../Grid/grid.h"


void snake_init(void)
{
	Grid_Init();
}

void snake_update(void)
{
	Grid_Update();
}

void snake_exit(void)
{

}