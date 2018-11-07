#include <progbase/canvas.h>

#include "header.h"

void Snake_render(Snake snake) {
    for (int i = 0; i < snake.body.length; i++) {
        BodyPart part = snake.body.parts[i];

        Canvas_setColorRGB(part.color.R, part.color.G, part.color.B);
        Canvas_putPixel(part.location.x, part.location.y);
    }
}

void Snake_changeDirection(Snake *snake, enum Directoins newDirection) {
    snake->direction = newDirection;

    BodyPart head = snake->body.parts[0];

    ChangePoint newChangePoint = {
        .point = head.location,
        .from  = head.direction,
        .to    = newDirection,
    };

    ChangePoints_push(&snake->changePoints, newChangePoint);
}

void Snake_tryEatApple(Snake *snake, Apple *apple) {
    BodyPart head = snake->body.parts[0];

    if (head.location.x == apple->location.x && head.location.y == apple->location.y) {
        // todo: remake
        Color greenColor = {
            .R = 0,
            .G = 255,
            .B = 0,
        };

        BodyPart newPart = Body_createPart(snake->direction, apple->location, greenColor);

        Body_push(&snake->body, newPart);

        *apple = Apple_generate(100, 100);  // todo: dynamic size limits
    }
}

void Snake_move(Snake *snake, Apple *apple) {
    for (int i = 0; i < snake->body.length; i++) {
        BodyPart *part = &snake->body.parts[i];

        switch (part->direction) {
            case UP: {
                part->location.y++;
            }
            case DOWN: {
                part->location.y--;
            }
            case RIGHT: {
                part->location.x++;
            }
            case LEFT: {
                part->location.x--;
            }
        }

        // ... change direction if need
        for (int j = 0; j < snake->changePoints.length; j++) {
            ChangePoint changePoint = snake->changePoints.list[j];

            if (changePoint.point.x == part->location.x && changePoint.point.y == part->location.y &&
                changePoint.from == part->direction) {
                part->direction = changePoint.to;

                if (j == 0) {
                    ChangePoints_shift(&snake->changePoints);
                }
            }
        }

        Snake_tryEatApple(snake, apple);
    }
}
