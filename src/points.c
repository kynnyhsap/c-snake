#include <stdbool.h>

#include "points.h"

bool Points_equals(Point2D p1, Point2D p2) { return (p1.x == p2.x && p1.y == p2.y); }
