#ifndef CI_TECHNO_TETRA_H
#define CI_TECHNO_TETRA_H

#include <stdlib.h>
#include <math.h>

typedef struct Point {
    double x, y, z;
} Point;
typedef struct Vector {
    double x, y, z;
} Vector;

Vector makeVectorAB(const Point A, const Point B);
Vector vectorProd(const Vector v1, const Vector v2);
double vectorLength(const Vector v);
double triangleArea(const Point *const p1, const Point *const p2, const Point *const p3);

double * EdgeMinArea(const Point ** const points, int nPoints);
Point ** generatePoints(int nPoints, int down, int up);
void freePoints(Point ** points, int nPoints);

#endif //CI_TECHNO_TETRA_H
