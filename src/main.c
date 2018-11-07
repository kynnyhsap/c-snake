#include <progbase/canvas.h>
#include <progbase/console.h>
#include <stdlib.h>
#include <time.h>

#include "header.h"

const Color COLOR_GREEN = {
    .R = 102,
    .G = 204,
    .B = 0,
};

const Color COLOR_GREEN_DARK = {
    .R = 0,
    .G = 153,
    .B = 0,
};

const Color COLOR_GREEN_LIGHT = {
    .R = 153,
    .G = 255,
    .B = 51,
};

void render(Snake snake, Apple apple) {
    Canvas_beginDraw();
    Snake_render(snake);
    Apple_render(apple);
    Canvas_endDraw();
}

int main() {
    srand(time(NULL));

    struct ConsoleSize consoleSize = Console_size();
    const int canvasWidth          = consoleSize.columns;
    const int canvasHeight         = consoleSize.rows * 2;

    Console_clear();
    Canvas_setSize(canvasWidth, canvasHeight);
    Canvas_invertYOrientation();

    Snake snake = {
        .score     = 0,
        .direction = RIGHT,
        .body      = {.length = 0},
    };

    snake.body.parts = (BodyPart*)malloc(4 * sizeof(BodyPart));

    for (int i = 0; i < 4; i++) {
        Point2D loc = {10 - i, 10};

        Body_push(&snake.body, Body_createPart(snake.body.length, RIGHT, loc));
    }

    Apple apple = Apple_generate(canvasWidth, canvasHeight);

    render(snake, apple);

    char keyCode = 0;
    do {
        keyCode = Console_getChar();

        switch (keyCode) {
            case BUTTON_UP: {
                Snake_changeDirection(&snake, UP);
                Snake_move(&snake, &apple);
                break;
            }
            case BUTTON_DOWN: {
                Snake_changeDirection(&snake, DOWN);
                Snake_move(&snake, &apple);
                break;
            }
            case BUTTON_LEFT: {
                Snake_changeDirection(&snake, LEFT);
                Snake_move(&snake, &apple);
                break;
            }
            case BUTTON_RIGHT: {
                Snake_changeDirection(&snake, RIGHT);
                Snake_move(&snake, &apple);
                break;
            }
        }

        render(snake, apple);
    } while (keyCode != '\n');

    return 0;
}
