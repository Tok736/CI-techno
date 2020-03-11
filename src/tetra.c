#include <tetra.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>



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
    if (!p1 || !p2 || !p3) return -1;
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
        if (!points[i]) return NULL;

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

void printPoints(const Point **const points, int nPoints) {
    if (!points) return;
    for (int i = 0; i < nPoints; i++) {
        if (!points[i]) return;
        if (i != 0) printf(", ");
        printf("(%.1f, %.1f, %.1f)", points[i]->x, points[i]->y, points[i]->z);
    }
    printf("\n");
}
