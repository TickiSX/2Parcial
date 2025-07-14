#pragma once

//#include "../Prerequisites.h"
#include <Vectors/Vector2.h>   // Para CVector2
#include <Vectors/Vector3.h>   // Para CVector3
#include <Math/EngineMath.h>

/**
 * @file Matrix3x3.h
 * @brief Defines a 3x3 matrix for 2D/3D transformations with extended linear algebra operations.
 */

namespace EU {

    /**
     * @class Matrix3x3
     * @brief A 3x3 matrix used for 2D/3D linear transformations, including scaling, rotation, and shearing.
     *        Supports algebraic operations such as determinant, transpose, inverse, cofactor, and adjugate.
     */
    class
        Matrix3x3 {
    public:
        float m[3][3];

        /**
         * @brief Default constructor. Initializes as identity matrix.
         */
        Matrix3x3() {
            setIdentity();
        }

        /**
         * @brief Constructor with raw values in row-major order.
         * @param m00 Element at row 0, col 0.
         * @param m01 Element at row 0, col 1.
         * @param m02 Element at row 0, col 2.
         * @param m10 Element at row 1, col 0.
         * @param m11 Element at row 1, col 1.
         * @param m12 Element at row 1, col 2.
         * @param m20 Element at row 2, col 0.
         * @param m21 Element at row 2, col 1.
         * @param m22 Element at row 2, col 2.
         */
        Matrix3x3(
            float m00, float m01, float m02,
            float m10, float m11, float m12,
            float m20, float m21, float m22
        ) {
            m[0][0] = m00; m[0][1] = m01; m[0][2] = m02;
            m[1][0] = m10; m[1][1] = m11; m[1][2] = m12;
            m[2][0] = m20; m[2][1] = m21; m[2][2] = m22;
        }

        /**
         * @brief Matrix addition.
         * @param o Matrix to add.
         * @return Sum of matrices.
         */
        Matrix3x3
            operator+(const Matrix3x3& o) const {
            Matrix3x3 r;
            for (int i = 0; i < 3; ++i)
                for (int j = 0; j < 3; ++j)
                    r.m[i][j] = m[i][j] + o.m[i][j];
            return r;
        }

        /**
         * @brief Matrix subtraction.
         * @param o Matrix to subtract.
         * @return Difference of matrices.
         */
        Matrix3x3
            operator-(const Matrix3x3& o) const {
            Matrix3x3 r;
            for (int i = 0; i < 3; ++i)
                for (int j = 0; j < 3; ++j)
                    r.m[i][j] = m[i][j] - o.m[i][j];
            return r;
        }

        /**
         * @brief Multiplies matrix by a scalar.
         * @param scalar Scalar value.
         * @return Scaled matrix.
         */
        Matrix3x3
            operator*(float scalar) const {
            Matrix3x3 r;
            for (int i = 0; i < 3; ++i)
                for (int j = 0; j < 3; ++j)
                    r.m[i][j] = m[i][j] * scalar;
            return r;
        }

        /**
         * @brief In-place scalar multiplication.
         * @param scalar Scalar value.
         * @return Reference to this matrix.
         */
        Matrix3x3&
            operator*=(float scalar) {
            for (int i = 0; i < 3; ++i)
                for (int j = 0; j < 3; ++j)
                    m[i][j] *= scalar;
            return *this;
        }

        /**
         * @brief Matrix multiplication.
         * @param o Right-hand side matrix.
         * @return Product matrix.
         */
        Matrix3x3
            operator*(const Matrix3x3& o) const {
            Matrix3x3 r = zero();
            for (int row = 0; row < 3; ++row)
                for (int col = 0; col < 3; ++col)
                    for (int k = 0; k < 3; ++k)
                        r.m[row][col] += m[row][k] * o.m[k][col];
            return r;
        }

        /**
         * @brief Multiplies this matrix by a 2D vector in homogeneous coordinates (z=1).
         * @param vec 2D vector.
         * @return Transformed 2D vector.
         */
        CVector2
            operator*(const CVector2& vec) const {
            float x = m[0][0] * vec.x + m[0][1] * vec.y + m[0][2] * 1.0f;
            float y = m[1][0] * vec.x + m[1][1] * vec.y + m[1][2] * 1.0f;
            float w = m[2][0] * vec.x + m[2][1] * vec.y + m[2][2] * 1.0f;

            if (w != 0.0f) {
                x /= w;
                y /= w;
            }

            return CVector2(x, y);
        }

        /**
         * @brief Multiplies this matrix by a 3D vector.
         * @param vec 3D vector.
         * @return Transformed 3D vector.
         */
        CVector3
            operator*(const CVector3& vec) const {
            return CVector3(
                m[0][0] * vec.x + m[0][1] * vec.y + m[0][2] * vec.z,
                m[1][0] * vec.x + m[1][1] * vec.y + m[1][2] * vec.z,
                m[2][0] * vec.x + m[2][1] * vec.y + m[2][2] * vec.z
            );
        }

        /**
         * @brief Access matrix element by row and column.
         * @param row Row index (0-2).
         * @param col Column index (0-2).
         * @return Reference to the matrix element.
         */
        float&
            operator()(int row, int col) { return m[row][col]; }

        /**
         * @brief Const access to matrix element by row and column.
         * @param row Row index (0-2).
         * @param col Column index (0-2).
         * @return Const reference to the matrix element.
         */
        const
            float& operator()(int row, int col) const { return m[row][col]; }

        /**
         * @brief Computes the determinant of the matrix.
         * @return Scalar determinant.
         */
        float
            determinant() const {
            return
                m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]) -
                m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0]) +
                m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
        }

        /**
         * @brief Returns the transposed matrix.
         * @return A new transposed Matrix3x3.
         */
        Matrix3x3
            transpose() const {
            return Matrix3x3(
                m[0][0], m[1][0], m[2][0],
                m[0][1], m[1][1], m[2][1],
                m[0][2], m[1][2], m[2][2]
            );
        }

        /**
         * @brief Computes the cofactor of a given element.
         * @param row Row index of the element.
         * @param col Column index of the element.
         * @return Scalar cofactor value.
         */
        float
            cofactor(int row, int col) const {
            int r1 = (row + 1) % 3, r2 = (row + 2) % 3;
            int c1 = (col + 1) % 3, c2 = (col + 2) % 3;
            float minor = m[r1][c1] * m[r2][c2] - m[r1][c2] * m[r2][c1];
            return ((row + col) % 2 == 0) ? minor : -minor;
        }

        /**
         * @brief Returns the cofactor matrix.
         * @return Matrix of cofactors.
         */
        Matrix3x3
            cofactorMatrix() const {
            return Matrix3x3(
                cofactor(0, 0), cofactor(0, 1), cofactor(0, 2),
                cofactor(1, 0), cofactor(1, 1), cofactor(1, 2),
                cofactor(2, 0), cofactor(2, 1), cofactor(2, 2)
            );
        }

        /**
         * @brief Computes the adjugate matrix (transpose of the cofactor matrix).
         * @return Adjugate matrix.
         */
        Matrix3x3
            adjugate() const {
            return cofactorMatrix().transpose();
        }

        /**
         * @brief Computes the inverse of this matrix.
         * @return Inverted matrix or identity if not invertible.
         */
        Matrix3x3
            inverse() const {
            float det = determinant();
            if (det == 0.f) return identity(); // Non-invertible
            return adjugate() * (1.f / det);
        }

        /**
         * @brief Sets this matrix to the identity matrix.
         */
        void
            setIdentity() {
            m[0][0] = 1.f; m[0][1] = 0.f; m[0][2] = 0.f;
            m[1][0] = 0.f; m[1][1] = 1.f; m[1][2] = 0.f;
            m[2][0] = 0.f; m[2][1] = 0.f; m[2][2] = 1.f;
        }

        /**
         * @brief Returns an identity matrix.
         * @return Identity matrix.
         */
        static
            Matrix3x3 identity() {
            return Matrix3x3(
                1.f, 0.f, 0.f,
                0.f, 1.f, 0.f,
                0.f, 0.f, 1.f
            );
        }

        /**
         * @brief Returns a zero matrix.
         * @return Matrix with all components set to 0.
         */
        static
            Matrix3x3 zero() {
            return Matrix3x3(
                0.f, 0.f, 0.f,
                0.f, 0.f, 0.f,
                0.f, 0.f, 0.f
            );
        }


    };

} // namespace EU