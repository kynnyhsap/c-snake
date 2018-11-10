#ifndef POINTS_H
#define POINTS_H

#include <stdbool.h>

typedef struct {
    int x, y;
} Point2D;

bool Points_equals(Point2D p1, Point2D p2);

#endif
