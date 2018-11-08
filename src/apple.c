#include <progbase/canvas.h>
#include <stdlib.h>

#include "apple.h"
#include "body.h"
#include "utils.h"

Apple Apple_spawn(Body snakeBody, Box box) {
    Apple apple = {
        .color = {255, 0, 0},
        .location =
            {
                .x = getRandomInt(2, box.w - 2),
                .y = getRandomInt(2, box.h - 2),
            },
    };

    // check if apple generated on snake body
    for (int i = 0; i < snakeBody.length; i++) {
        BodyPart part = snakeBody.parts[i];

        if (part.location.x == apple.location.x && part.location.y == apple.location.y) {
            return Apple_spawn(snakeBody, box);
        }
    }

    return apple;
}

void Apple_render(Apple *apple) {
    Canvas_setColorRGB(apple->color.R, apple->color.G, apple->color.B);
    Canvas_putPixel(apple->location.x, apple->location.y);
}
