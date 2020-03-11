#include "gtest/gtest.h"

extern "C" {
    #include "tetra.h"
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(vectorFunctionsTest, length) {
    const int size = 5;
    double PythQuad[size][4] = {
            {1, 2, 2, 3},
            {2, 3, 6, 7},
            {1, 4, 8, 9},
            {4, 4, 7, 9},
            {2, 6, 9, 11}
    };
    for (int i = 0; i < size; i++) {
        Vector temp = {PythQuad[i][0], PythQuad[i][1], PythQuad[i][2]};
        EXPECT_EQ(vectorLength(temp), PythQuad[i][3]);
    }
}

Point randPoint(int down, int up) {
    srand(time(0));
    Point temp;
    temp.x = rand() % (up - down) + down;
    temp.y = rand() % (up - down) + down;
    temp.z = rand() % (up - down) + down;
    return temp;
}

TEST(vectorFunctionsTest, makeVector) {
    Point A = randPoint(-50, 100);
    Point B = randPoint(-50, 100);
    Vector AB = makeVectorAB(A, B);
    Vector BA = makeVectorAB(B, A);
    EXPECT_EQ(AB.x, -BA.x);
    EXPECT_EQ(AB.y, -BA.y);
    EXPECT_EQ(AB.z, -BA.z);
    EXPECT_EQ(A.x + AB.x, B.x);
    EXPECT_EQ(A.y + AB.y, B.y);
    EXPECT_EQ(A.z + AB.z, B.z);
}

Vector randVector(int down, int up) {
    Point O = {0, 0, 0};
    return makeVectorAB(O, randPoint(down, up));
}

double scalarProd(Vector a, Vector b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

TEST(vectorFunctionsTest, vectorProd) {
    Vector a = randVector(-50, 100);
    Vector b = randVector(-50, 100);
    Vector result = vectorProd(a, b);
    EXPECT_EQ(scalarProd(a, result), 0);
    EXPECT_EQ(scalarProd(b, result), 0);
}

TEST(triangleAreaTest, invalidInput) {
    Point p1 = randPoint(-10, 10);
    Point p2 = randPoint(-10, 10);
    Point p3 = randPoint(-10, 10);
    EXPECT_EQ(triangleArea(NULL, &p2, &p3), -1);
    EXPECT_EQ(triangleArea(&p1, NULL, &p3), -1);
    EXPECT_EQ(triangleArea(&p1, &p2, NULL), -1);
}

TEST(triangleAreaTest, areaCheck) {
    Point p1 = {-1, -1, -1};
    Point p2 = {1, 2, 3};
    Point p3 = {9, 8, 7};
    double result = 0.5 * sqrt(864);
    EXPECT_EQ(triangleArea(&p1, &p2, &p3), result);
}

TEST(MinAreaTest, minAreaCheck) {
    const int nPoints = 4;
    double arrPoints[4][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {9, 7, 5},
            {-1, -3, -5}
    };
    double result = 11.022704;

    Point ** points = (Point**)malloc(nPoints * sizeof(Point*));
    for (int i = 0; i < nPoints; i++) {
        points[i] = (Point*)malloc(sizeof(Point));

        points[i]->x = arrPoints[i][0];
        points[i]->y = arrPoints[i][1];
        points[i]->z = arrPoints[i][2];
    }

    double * temp = EdgeMinArea(points, nPoints);
    EXPECT_TRUE(fabs(result - *temp) < 0.0001);
    free(points);
}

TEST(MinAreaTest, invalidInput) {
    const int nPoints = 4;
    Point ** points = NULL;
    EXPECT_EQ(EdgeMinArea(points, nPoints), NULL);
    EXPECT_EQ(EdgeMinArea(points, 3), NULL);
}