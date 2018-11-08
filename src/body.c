#include <stdlib.h>

#include "header.h"

const Color COLOR_GREEN = {
    .R = 102,
    .G = 204,
    .B = 0,
};

const Color COLOR_GREEN_DARK = {
    .R = 0,
    .G = 153,
    .B = 0,
};

const Color COLOR_GREEN_LIGHT = {
    .R = 153,
    .G = 255,
    .B = 51,
};

void Body_push(Body *body, BodyPart newPart) {
    const int newLength = body->length + 1;
    body->parts         = (BodyPart *)realloc(body->parts, newLength * sizeof(BodyPart));

    body->parts[body->length] = newPart;
    body->length              = newLength;
}

BodyPart Body_createPart(int bodyLength, enum Directions direction, Point2D location) {
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
