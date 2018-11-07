#include <progbase/canvas.h>
#include <stdlib.h>

#include "header.h"

Apple Apple_generate(unsigned int maxX, unsigned int maxY) {
    // todo: check if apple generated on snake body

    Apple apple = {
        .color = {255, 0, 0},
        .location =
            {
                .x = getRandomInt(0, maxX),
                .y = getRandomInt(0, maxY),
            },
    };

    return apple;
}

void Apple_render(Apple apple) {
    Canvas_setColorRGB(apple.color.R, apple.color.G, apple.color.B);
    Canvas_putPixel(apple.location.x, apple.location.y);
}