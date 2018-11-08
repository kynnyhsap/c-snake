#include <stdbool.h>

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

typedef struct {
    Color color;
    Point2D location;
    enum Directions direction;
} BodyPart;

typedef struct {
    BodyPart *parts;
    int length;
} Body;

typedef struct {
    Point2D point;
    enum Directions from;
    enum Directions to;
} ChangePoint;

typedef struct {
    ChangePoint *list;
    int length;
} ChangePointsList;

typedef struct {
    Point2D location;
    Color color;
} Apple;

typedef struct {
    unsigned int score;
    Body body;
    ChangePointsList changePoints;
    enum Directions direction;
} Snake;

int getRandomInt(int min, int max);
void sleepMillis(unsigned long int milliseconds);

void Snake_render(Snake snake);
Snake Snake_create(int length, enum Directions direction, int headX, int headY);
void Snake_changeDirection(Snake *snake, enum Directions newDirection);
bool Snake_directionsOpposite(enum Directions d1, enum Directions d2);
void Snake_move(Snake *snake, Apple *apple, Box box, enum Directions newDirection);
void Snake_tryEatApple(Snake *snake, Apple *apple, Box box);

BodyPart Body_createPart(int bodyLength, enum Directions direction, Point2D location);
void Body_push(Body *body, BodyPart newPart);

Apple Apple_generate(Snake snake, Box box);
void Apple_render(Apple apple);

void ChangePoints_push(ChangePointsList *changePoints, ChangePoint newPoint);
void ChangePoints_shift(ChangePointsList *changePoints);

extern const Color COLOR_GREEN;
extern const Color COLOR_GREEN_LIGHT;
extern const Color COLOR_GREEN_DARK;
