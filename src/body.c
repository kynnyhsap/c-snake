#include <stdlib.h>

#include "body.h"
#include "utils.h"

void Body_push(Body *body, BodyPart newPart) {
    const int newLength = body->length + 1;
    body->parts         = (BodyPart *)realloc(body->parts, newLength * sizeof(BodyPart));

    body->parts[body->length] = newPart;
    body->length              = newLength;
}

BodyPart Body_newPart(int bodyLength, enum Directions direction, Point2D location) {
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

Body Body_new(int bodyLength, enum Directions direction, int headX, int headY) {
    Body body = {.length = 0};

    body.parts = (BodyPart *)malloc(bodyLength * sizeof(BodyPart));

    for (int i = 0; i < bodyLength; i++) {
        Point2D location = {.x = headX - i, .y = headY};

        Body_push(&body, Body_newPart(i, direction, location));
    }

    body.parts[0].color = COLOR_GREEN_DARK;  // highlight head =)

    return body;
}
