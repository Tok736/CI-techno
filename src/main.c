#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

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

const int amountOfPoints = 4;
double * EdgeMinArea(const Point ** const points, int nPoints);
Point ** generatePoints(int nPoints, int down, int up);
void freePoints(Point ** points, int nPoints);
void printPoints(Point ** points, int nPoints);

int main() {
    srand(time(0));

    int downEgde = -20, upEdge = 20;
    Point ** points = generatePoints(amountOfPoints, downEgde, upEdge);
    if (!points) return 0;
    printPoints(points, amountOfPoints);
    double * minArea = EdgeMinArea(points, amountOfPoints);
    if (!minArea) return 0;
    printf("Minimal area = %.3f", *minArea);

    freePoints(points, amountOfPoints);

    return 0;
}


Vector makeVectorAB(const Point A, const Point B) {
    Vector vec = {B.x - A.x, B.y - A.y, B.z - A.z};
    return vec;
}

Vector vectorProd(const Vector v1, const Vector v2) {
    Vector vec = {v1.y * v2.z - v2.y * v1.z, v1.x * v2.z - v2.x * v1.z, v1.x * v2.y - v2.x * v1.y};
    return vec;
}

double vectorLength(const Vector v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

double triangleArea(const Point *const p1, const Point *const p2, const Point *const p3) {
    Vector p1p2 = makeVectorAB(*p1, *p2), p1p3 = makeVectorAB(*p1, *p3);
    return vectorLength(vectorProd(p1p2, p1p3)) / 2;
}

double * EdgeMinArea(const Point **const points, int nPoints) {
    if (!points) return NULL;
    double * minArea = (double*)malloc(sizeof(double));
    if (!minArea) return NULL;


    *minArea = triangleArea(points[0], points[1], points[2]);
    for (int i = 0; i < nPoints - 2; i++) {
        for (int j = i + 1; j < nPoints - 1; j++) {
            for (int k = j + 1; k < nPoints; k++) {
                printf("%d, %d, %d\n", i, j, k);
                double tempArea = triangleArea(points[i], points[j], points[k]);
                if (tempArea < *minArea) *minArea = tempArea;
                printf("tempArea = %f\n", tempArea);
            }
        }
    }

    return minArea;
}

Point ** generatePoints(int nPoints, int down, int up) {
    Point ** points = (Point**)malloc(nPoints * sizeof(Point*));
    if (!points) return NULL;
    for (int i = 0; i < nPoints; i++) {
        points[i] = (Point*)malloc(sizeof(Point));
        if (!points) return NULL;

        points[i]->x = rand() % (up - down) + down;
        points[i]->y = rand() % (up - down) + down;
        points[i]->z = rand() % (up - down) + down;
    }
    return points;
}

void freePoints(Point ** points, int nPoints) {
    for (int i = 0; i < nPoints; i++) {
        free(points[i]);
    }
    free(points);
}

void printPoints(Point ** points, int nPoints) {
    if (!points) return;
    for (int i = 0; i < nPoints; i++) {
        if (!points[i]) return;
        if (i != 0) printf(", ");
        printf("(%.1f, %.1f, %.1f)", points[i]->x, points[i]->y, points[i]->z);
    }
    printf("\n");
}