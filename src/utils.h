#ifndef UTILS_H
#define UTILS_H

enum Directions { UP, DOWN, LEFT, RIGHT };

#define BUTTON_UP 'w'
#define BUTTON_DOWN 's'
#define BUTTON_LEFT 'a'
#define BUTTON_RIGHT 'd'

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
