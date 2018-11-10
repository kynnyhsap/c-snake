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
    int w;
    int h;
} Box;

typedef struct {
    unsigned int R;
    unsigned int G;
    unsigned int B;
} Color;

typedef struct {
    int x;
    int y;
} Point2D;

int getRandomInt(int min, int max);
void sleepMillis(unsigned long int milliseconds);

extern const Color COLOR_GREEN;
extern const Color COLOR_GREEN_LIGHT;
extern const Color COLOR_GREEN_DARK;

#endif
