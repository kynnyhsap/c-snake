#ifndef BODY_H
#define BODY_H

#include "utils.h"

typedef struct {
    Color color;
    Point2D location;
    enum Directions direction;
} BodyPart;

typedef struct {
    BodyPart *parts;
    int length;
} Body;

BodyPart Body_createPart(int bodyLength, enum Directions direction, Point2D location);
void Body_push(Body *body, BodyPart newPart);

#endif
