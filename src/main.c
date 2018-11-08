#include <progbase/canvas.h>
#include <progbase/console.h>
#include <stdlib.h>
#include <time.h>

#include "header.h"

void render(Snake snake, Apple apple) {
    Canvas_beginDraw();
    Snake_render(snake);
    Apple_render(apple);
    Canvas_endDraw();
}

int main() {
    srand(time(NULL));

    struct ConsoleSize consoleSize = Console_size();

    Box box = {.w = consoleSize.columns, .h = consoleSize.rows * 2};

    Console_clear();
    Canvas_setSize(box.w, box.h);
    Canvas_invertYOrientation();

    Snake snake = Snake_create(4, RIGHT, 10, 10);
    Apple apple = Apple_generate(snake, box);

    render(snake, apple);

    char keyCode = 0;
    do {
        keyCode = Console_getChar();

        switch (keyCode) {
            case BUTTON_UP: {
                Snake_move(&snake, &apple, box, UP);
                break;
            }
            case BUTTON_DOWN: {
                Snake_move(&snake, &apple, box, DOWN);
                break;
            }
            case BUTTON_LEFT: {
                Snake_move(&snake, &apple, box, LEFT);
                break;
            }
            case BUTTON_RIGHT: {
                Snake_move(&snake, &apple, box, RIGHT);
                break;
            }
        }

        render(snake, apple);
    } while (keyCode != '\n');

    return 0;
}
