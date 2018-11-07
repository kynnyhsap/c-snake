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
    // todo: disallow change if new direction invertable to current
    snake->direction = newDirection;

    BodyPart head = snake->body.parts[0];

    snake->body.parts[0].direction = newDirection;

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
        BodyPart tail = snake->body.parts[snake->body.length - 1];

        Point2D location = tail.location;

        switch (tail.direction) {
            case UP: {
                location.y--;
                break;
            }
            case DOWN: {
                location.y++;
                break;
            }
            case LEFT: {
                location.x++;
                break;
            }
            case RIGHT: {
                location.x--;
                break;
            }
        }

        BodyPart newPart = Body_createPart(snake->body.length, tail.direction, location);

        Body_push(&snake->body, newPart);

        *apple = Apple_generate(10, 30);  // todo: dynamic size limits
    }
}

void Snake_move(Snake *snake, Apple *apple) {
    for (int i = 0; i < snake->body.length; i++) {
        switch (snake->body.parts[i].direction) {
            case UP: {
                snake->body.parts[i].location.y++;
                break;
            }
            case DOWN: {
                snake->body.parts[i].location.y--;
                break;
            }
            case RIGHT: {
                snake->body.parts[i].location.x++;
                break;
            }
            case LEFT: {
                snake->body.parts[i].location.x--;
                break;
            }
        }

        // ... change direction if need
        for (int j = 0; j < snake->changePoints.length; j++) {
            ChangePoint changePoint = snake->changePoints.list[j];

            if (changePoint.point.x == snake->body.parts[i].location.x &&
                changePoint.point.y == snake->body.parts[i].location.y &&
                changePoint.from == snake->body.parts[i].direction) {
                snake->body.parts[i].direction = changePoint.to;

                if (j == 0 && i == snake->body.length - 1) {
                    ChangePoints_shift(&snake->changePoints);
                }
            }
        }

        Snake_tryEatApple(snake, apple);
    }
}
