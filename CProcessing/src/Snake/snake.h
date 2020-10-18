#pragma once

typedef enum
{
	LEFT = 1,
	RIGHT,
	UP,
	DOWN
} direction;

void snake_init(void);
void snake_update(void);
void snake_exit(void);