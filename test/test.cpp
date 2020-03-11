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


