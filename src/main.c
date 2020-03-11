//      Условие ИЗ 1:
//  Составить программу нахождения минимальной площади грани тетраэдра,
//  заданного 4 вершинами. Оформить решение в виде функции, принимающей
//  на вход указатели на координаты вершин тетраэдра. На выходе функция
//  должна возвращать указатель на значение площади наименьшей грани.
//

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <tetra.h>

const int amountOfPoints = 4;

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








