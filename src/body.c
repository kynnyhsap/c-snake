#include <stdlib.h>

#include "header.h"

void Body_push(Body *body, BodyPart newPart) {
    const int newLength = body->length + 1;
    body->parts         = (BodyPart *)realloc(body->parts, newLength * sizeof(BodyPart));

    body->parts[body->length] = newPart;
    body->length              = newLength;
}

BodyPart Body_createPart(enum Directoins direction, Point2D location, Color color) {
    BodyPart part = {
        .direction = direction,
        .location  = location,
        .color     = color,
    };

    return part;
}