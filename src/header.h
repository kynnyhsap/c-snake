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
    enum Directoins to;
} Apple;

typedef struct {
    Body body;
    ChangePointsList changePoints;
    enum Directoins direction;
} Snake;