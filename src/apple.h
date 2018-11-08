#ifndef APPLE_H
#define APPLE_H

#include <progbase/canvas.h>
#include <stdlib.h>

#include "body.h"
#include "utils.h"

typedef struct {
    Point2D location;
    Color color;
} Apple;

Apple Apple_spawn(Body snakeBody, Box box);
void Apple_render(Apple *apple);

#endif
