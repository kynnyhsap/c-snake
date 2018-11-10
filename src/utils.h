#ifndef UTILS_H
#define UTILS_H

enum Directions { UP, DOWN, LEFT, RIGHT };

#define BUTTON_MOVE_UP 'w'
#define BUTTON_MOVE_DOWN 's'
#define BUTTON_MOVE_LEFT 'a'
#define BUTTON_MOVE_RIGHT 'd'
#define BUTTON_QUIT_GAME 'q'
#define BUTTON_PAUSE_GAME 'p'

typedef struct {
    unsigned int w, h;
} Box;

typedef struct {
    unsigned int R, G, B;
} Color;

int getRandomInt(int min, int max);
void sleepMillis(unsigned long int milliseconds);

extern const Color COLOR_GREEN;
extern const Color COLOR_GREEN_LIGHT;
extern const Color COLOR_GREEN_DARK;

#endif
