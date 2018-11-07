enum Directoins { UP, DOWN, LEFT, RIGHT };

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
    enum Directoins direction;
} BodyPart;

typedef struct {
    BodyPart *parts;
    int length;
} Body;

typedef struct {
    Point2D point;
    enum Directoins from;
    enum Directoins to;
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
    Body body;
    ChangePointsList changePoints;
    enum Directoins direction;
} Snake;

int getRandomInt(int min, int max);
void sleepMillis(unsigned long int milliseconds);

void Snake_render(Snake snake);
void Snake_changeDirection(Snake *snake, enum Directoins newDirection);
void Snake_move(Snake *snake);

BodyPart Body_createPart(enum Directoins direction, Point2D location, Color color);
void Body_push(Body *body, BodyPart newPart);

Apple Apple_generate(unsigned int maxX, unsigned int maxY);
void Apple_render(Apple apple);

void ChangePoints_push(ChangePointsList *changePoints, ChangePoint newPoint);
void ChangePoints_shift(ChangePointsList *changePoints);