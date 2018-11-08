#include <progbase/canvas.h>
#include <stdbool.h>
#include <stdlib.h>

#include "apple.h"
#include "snake.h"

void Snake_render(Snake *snake) {
    for (int i = 0; i < snake->body.length; i++) {
        BodyPart part = snake->body.parts[i];

        Canvas_setColorRGB(part.color.R, part.color.G, part.color.B);
        Canvas_putPixel(part.location.x, part.location.y);
    }
}

Snake Snake_new(int length, enum Directions direction, int headX, int headY) {
    Snake snake = {
        .score     = 0,
        .direction = direction,
    };

    snake.body = Body_new(length, direction, headX, headY);

    return snake;
}

bool Snake_directionsOpposite(enum Directions d1, enum Directions d2) {
    if (d1 != d2) {
        if ((d1 == RIGHT || d1 == LEFT) && (d2 == RIGHT || d2 == LEFT)) return true;
        if ((d1 == UP || d1 == DOWN) && (d2 == UP || d2 == DOWN)) return true;
    }

    return false;
}

void Snake_changeDirection(Snake *snake, enum Directions newDirection) {
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

void Snake_tryEatApple(Snake *snake, Apple *apple, Box box) {
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

        BodyPart newPart = Body_newPart(snake->body.length, tail.direction, location);

        Body_push(&snake->body, newPart);

        *apple = Apple_spawn(snake->body, box);

        snake->score++;
    }
}

void Snake_move(Snake *snake, Apple *apple, Box box, enum Directions newDirection) {
    if (newDirection != snake->direction) {
        if (Snake_directionsOpposite(snake->direction, newDirection)) {
            return;
        }

        Snake_changeDirection(snake, newDirection);
    }

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

        Snake_tryEatApple(snake, apple, box);
    }
}
