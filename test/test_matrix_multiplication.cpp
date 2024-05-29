#include "matrix_multiplication.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>


// ######################### Source code of multiplyMatrices in src/matrix_mult

TEST(MatrixMultiplicationTest, TestMultiplyMatrices) {
    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6}
    };
    std::vector<std::vector<int>> B = {
        {7, 8},
        {9, 10},
        {11, 12}
    };

    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 3, 2);

    std::vector<std::vector<int>> expected = {
        {58, 64},
        {139, 154}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((((";
}

/*
 * #####################################################################################################################
 * Testing neutral element property (identity matrix on left).
 * I x B = B
 * #####################################################################################################################
 */
TEST(MatrixMultiplicationTest, TestLeftIdentityMatrix) {
    std::vector<std::vector<int>> A = {
            {1, 0, 0},
            {0, 1, 0},
            {0, 0, 1}
    };
    std::vector<std::vector<int>> B = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };

    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 3, 2);

    std::vector<std::vector<int>> expected = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };

    ASSERT_EQ(C, expected) << "Multiplication with left identity matrix failed! :(((((";
}

/*
 * #####################################################################################################################
 * Testing scalar product.
 * a x b = ab
 * #####################################################################################################################
 */
TEST(MatrixMultiplicationTest, TestScalarProduct) {
    std::vector<std::vector<int>> A = {
            {7}
    };
    std::vector<std::vector<int>> B = {
            {5}
    };

    std::vector<std::vector<int>> C(1, std::vector<int>(1, 0));

    multiplyMatrices(A, B, C, 1, 1, 1);

    std::vector<std::vector<int>> expected = {
            {35}
    };

    ASSERT_EQ(C, expected) << "Scalar product failed! :(((((";

    multiplyMatrices(B, A, C, 1, 1, 1);
    ASSERT_EQ(C, expected) << "Commutative scalar product failed! :(((((";
}

/*
 * #####################################################################################################################
 * Testing 0-element property for scalar product.
 * 0 x b = 0
 * Includes: metamorphic relation to test commutative property and so 0-product for both factors A and B.
 * a x 0 = 0
 * #####################################################################################################################
 */
TEST(MatrixMultiplicationTest, Test0ElementScalarProduct) {
    std::vector<std::vector<int>> A = {
            {0}
    };
    std::vector<std::vector<int>> B = {
            {7}
    };

    std::vector<std::vector<int>> C(1, std::vector<int>(1, 0));

    multiplyMatrices(A, B, C, 1, 1, 1);

    std::vector<std::vector<int>> expected = {
            {0}
    };

    ASSERT_EQ(C, expected) << "0-element property (left 0) for scalar product failed! :(((((";

    multiplyMatrices(B, A, C, 1, 1, 1);
    ASSERT_EQ(C, expected) << "0-element property (right 0) for scalar product failed! :(((((";
}

/*
 * #####################################################################################################################
 * Testing neutral element property for scalar product.
 * 1 x b = b
 * Includes: metamorphic relation to test commutative property and so 1-product for both factors A and B.
 * a x 1 = a
 * #####################################################################################################################
 */
TEST(MatrixMultiplicationTest, TestNeutralElementScalarProduct) {
    std::vector<std::vector<int>> A = {
            {1}
    };
    std::vector<std::vector<int>> B = {
            {7}
    };

    std::vector<std::vector<int>> C(1, std::vector<int>(1, 0));

    multiplyMatrices(A, B, C, 1, 1, 1);

    std::vector<std::vector<int>> expected = {
            {7}
    };

    ASSERT_EQ(C, expected) << "Neutral element property (left 1) for scalar product failed! :(((((";

    multiplyMatrices(B, A, C, 1, 1, 1);
    ASSERT_EQ(C, expected) << "Neutral element property (right 1) for scalar product failed! :(((((";
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
