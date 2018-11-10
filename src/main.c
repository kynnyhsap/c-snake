#include <progbase/canvas.h>
#include <progbase/console.h>
#include <stdlib.h>
#include <time.h>

#include "apple.h"
#include "snake.h"
#include "utils.h"

void render(Snake *snake, Apple *apple) {
    Canvas_beginDraw();
    Snake_render(snake);
    Apple_render(apple);
    Canvas_endDraw();

    Console_setCursorAttribute(FG_CYAN);
    Console_setCursorAttribute(BG_BLACK);
    Console_setCursorPosition(1, 1);
    printf("Score: %i", snake->score);
    Console_setCursorAttribute(FG_BLACK);  // fg need to be the same color with bg

    Console_hideCursor();
}

int main() {
    srand(time(NULL));

    struct ConsoleSize consoleSize = Console_size();

    Box box = {
        .w = consoleSize.columns,
        .h = consoleSize.rows * 2,
    };

    Console_clear();
    Canvas_setSize(box.w, box.h);
    Canvas_invertYOrientation();

    Snake snake = Snake_new(4, RIGHT, 10, 10);
    Apple apple = Apple_spawn(snake.body, box);

    render(&snake, &apple);

    bool quitGame = false;
    while (1) {
        if (quitGame) break;

        if (Console_isKeyDown()) {
            char key = getchar();

            switch (key) {
                case BUTTON_MOVE_UP: {
                    Snake_changeDirection(&snake, UP);
                    break;
                }
                case BUTTON_MOVE_DOWN: {
                    Snake_changeDirection(&snake, DOWN);
                    break;
                }
                case BUTTON_MOVE_LEFT: {
                    Snake_changeDirection(&snake, LEFT);
                    break;
                }
                case BUTTON_MOVE_RIGHT: {
                    Snake_changeDirection(&snake, RIGHT);
                    break;
                }
                case BUTTON_QUIT_GAME: {
                    quitGame = true;
                    break;
                }
            }
        } else {
            Snake_move(&snake, &apple, box);

            render(&snake, &apple);

            sleepMillis(150);
        }
    }

    Console_showCursor();

    return 0;
}
