#ifndef SNAKE_H
#define SNAKE_H

#include <stdbool.h>

#include "apple.h"
#include "body.h"
#include "change-points.h"

typedef struct {
    unsigned int score;
    Body body;
    ChangePointsList changePoints;
    enum Directions direction;
} Snake;

void Snake_move(Snake *snake, Apple *apple, Box box, enum Directions newDirection);
void Snake_render(Snake *snake);
void Snake_tryEatApple(Snake *snake, Apple *apple, Box box);
void Snake_changeDirection(Snake *snake, enum Directions newDirection);
bool Snake_directionsOpposite(enum Directions d1, enum Directions d2);
Snake Snake_new(int length, enum Directions direction, int headX, int headY);

#endif
