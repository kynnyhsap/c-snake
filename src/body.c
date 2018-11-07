#include <stdlib.h>

#include "header.h"

void Body_push(Body *body, BodyPart newPart) {
    const int newLength = body->length + 1;
    body->parts         = (BodyPart *)realloc(body->parts, newLength * sizeof(BodyPart));

    body->parts[body->length] = newPart;
    body->length              = newLength;
}

BodyPart Body_createPart(int bodyLength, enum Directoins direction, Point2D location) {
    BodyPart part = {
        .direction = direction,
        .location  = location,
    };

    if (bodyLength % 2 == 0) {
        part.color = COLOR_GREEN;
    } else {
        part.color = COLOR_GREEN_LIGHT;
    }

    return part;
}
