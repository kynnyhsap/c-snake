#ifndef CHANGE_POINTS_H
#define CHANGE_POINTS_H

#include "utils.h"

typedef struct {
    Point2D point;
    enum Directions from;
    enum Directions to;
} ChangePoint;

typedef struct {
    ChangePoint *list;
    int length;
} ChangePointsList;

void ChangePoints_push(ChangePointsList *changePoints, ChangePoint newPoint);
void ChangePoints_shift(ChangePointsList *changePoints);

#endif
