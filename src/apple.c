#include <progbase/canvas.h>
#include <stdlib.h>

#include "header.h"

Apple Apple_generate(Snake *snake, unsigned int maxX, unsigned int maxY) {
    Apple apple = {
        .color = {255, 0, 0},
        .location =
            {
                .x = getRandomInt(0, maxX),
                .y = getRandomInt(0, maxY),
            },
    };

    // check if apple generated on snake body
    for (int i = 0; i < snake->body.length; i++) {
        BodyPart part = snake->body.parts[i];

        if (part.location.x == apple.location.x && part.location.y == apple.location.y) {
            return Apple_generate(snake, maxX, maxY);
        }
    }

    return apple;
}

void Apple_render(Apple apple) {
    Canvas_setColorRGB(apple.color.R, apple.color.G, apple.color.B);
    Canvas_putPixel(apple.location.x, apple.location.y);
}
