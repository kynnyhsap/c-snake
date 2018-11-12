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

    unsigned int renderDelay = 150;

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
            Console_lockInput();

            Console_setCursorPosition(2, 1);
            Console_setCursorAttribute(FG_CYAN);
            printf("%c", key);

            switch (key) {
                case BUTTON_MOVE_UP: {
                    if (!snake.canChangeDirection) break;

                    Snake_changeDirection(&snake, UP);

                    if (snake.canChangeDirection) {
                        Snake_move(&snake, &apple, box);
                    }

                    render(&snake, &apple);
                    sleepMillis(renderDelay);
                    Console_unlockInput();

                    break;
                }
                case BUTTON_MOVE_DOWN: {
                    if (!snake.canChangeDirection) break;

                    Snake_changeDirection(&snake, DOWN);

                    if (snake.canChangeDirection) {
                        Snake_move(&snake, &apple, box);
                    }

                    render(&snake, &apple);
                    sleepMillis(renderDelay);
                    Console_unlockInput();

                    break;
                }
                case BUTTON_MOVE_LEFT: {
                    if (!snake.canChangeDirection) break;

                    Snake_changeDirection(&snake, LEFT);
                    if (snake.canChangeDirection) {
                        Snake_move(&snake, &apple, box);
                    }

                    render(&snake, &apple);
                    sleepMillis(renderDelay);
                    Console_unlockInput();

                    break;
                }
                case BUTTON_MOVE_RIGHT: {
                    if (!snake.canChangeDirection) break;

                    Snake_changeDirection(&snake, RIGHT);
                    if (snake.canChangeDirection) {
                        Snake_move(&snake, &apple, box);
                    }

                    render(&snake, &apple);
                    sleepMillis(renderDelay);
                    Console_unlockInput();

                    break;
                }
                case BUTTON_QUIT_GAME: {
                    quitGame = true;
                    Console_unlockInput();

                    break;
                }
                default: {
                    Console_unlockInput();

                    break;
                }
            }

        } else {
            if (snake.canChangeDirection) {
                Snake_move(&snake, &apple, box);
            }

            render(&snake, &apple);
            sleepMillis(renderDelay);
        }
    }

    Console_showCursor();

    return 0;
}
