#include <stdlib.h>
#include <time.h>

#include "utils.h"

int getRandomInt(int min, int max) { return (rand() % (max - min + 1)) + min; }

void sleepMillis(unsigned long int milliseconds) {
    struct timespec tim;
    tim.tv_sec  = (milliseconds / 1000L);
    tim.tv_nsec = (milliseconds % 1000L) * 1000000L;

    nanosleep(&tim, NULL);
}

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
