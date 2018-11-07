#include <stdlib.h>
#include <time.h>

int getRandomInt(int min, int max) { return (rand() % (max - min + 1)) + min; }

void sleepMillis(unsigned long int milliseconds) {
    struct timespec tim;
    tim.tv_sec  = (milliseconds / 1000L);
    tim.tv_nsec = (milliseconds % 1000L) * 1000000L;

    nanosleep(&tim, NULL);
}