#include <stdlib.h>

#include "header.h"

void ChangePoints_push(ChangePointsList *changePoints, ChangePoint newPoint) {
    const int newLength = changePoints->length + 1;

    changePoints->list = (ChangePoint *)realloc(changePoints->list, newLength * sizeof(ChangePoint));

    changePoints->list[changePoints->length] = newPoint;
    changePoints->length                     = newLength;
}

void ChangePoints_shift(ChangePointsList *changePoints) {
    const int newLength = changePoints->length - 1;

    ChangePoint *buffer = (ChangePoint *)malloc(newLength * sizeof(ChangePoint));

    for (int i = 1; i < changePoints->length; i++) {
        buffer[i - 1] = changePoints->list[i];
    }

    changePoints->list   = (ChangePoint *)realloc(buffer, newLength * sizeof(ChangePoint));
    changePoints->length = newLength;
}