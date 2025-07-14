#pragma once

//#include "../Prerequisites.h"
#include <Vectors/Vector2.h>
#include <Math/EngineMath.h>

/**
 * @file Matrix2x2.h
 * @brief Represents a 2x2 matrix with basic linear algebra operations for 2D transformations.
 */

namespace EU {

    /**
     * @class Matrix2x2
     * @brief A 2x2 matrix used for 2D linear transformations such as scaling and rotation.
     */
    class
        Matrix2x2 {
    public:
        float m00, m01;
        float m10, m11;

        /**
         * @brief Default constructor. Initializes as identity matrix.
         */
        Matrix2x2()
            : m00(1.f), m01(0.f), m10(0.f), m11(1.f) {
        }

        /**
         * @brief Constructor with values.
         * @param m00 Top-left value.
         * @param m01 Top-right value.
         * @param m10 Bottom-left value.
         * @param m11 Bottom-right value.
         */
        Matrix2x2(float m00, float m01, float m10, float m11)
            : m00(m00), m01(m01), m10(m10), m11(m11) {
        }

        //Addition and remainder operators

        /**
         * @brief Adds two matrices.
         * @param other The other matrix.
         * @return Resulting matrix.
         */
        Matrix2x2
            operator+(const Matrix2x2& other) const {
            return Matrix2x2(
                m00 + other.m00, m01 + other.m01,
                m10 + other.m10, m11 + other.m11
            );
        }

        /**
         * @brief Subtracts two matrices.
         * @param other The other matrix.
         * @return Resulting matrix.
         */
        Matrix2x2
            operator-(const Matrix2x2& other) const {
            return Matrix2x2(
                m00 - other.m00, m01 - other.m01,
                m10 - other.m10, m11 - other.m11
            );
        }



        /**
             * @brief Adds another matrix to this one (in-place).
             * @param other The other matrix.
             * @return Reference to this matrix.
             */
        Matrix2x2&
            operator+=(const Matrix2x2& other) {
            m00 += other.m00; m01 += other.m01;
            m10 += other.m10; m11 += other.m11;
            return *this;
        }

        /**
         * @brief Subtracts another matrix from this one (in-place).
         * @param other The other matrix.
         * @return Reference to this matrix.
         */
        Matrix2x2&
            operator-=(const Matrix2x2& other) {
            m00 -= other.m00; m01 -= other.m01;
            m10 -= other.m10; m11 -= other.m11;
            return *this;
        }

        //Multiplication operators


        /**
         * @brief Multiplies the matrix by a scalar.
         * @param scalar The scalar value.
         * @return Scaled matrix.
         */
        Matrix2x2
            operator*(float scalar) const {
            return Matrix2x2(
                m00 * scalar, m01 * scalar,
                m10 * scalar, m11 * scalar
            );
        }


        /**
         * @brief Multiplies this matrix with another 2x2 matrix.
         * @param other The other matrix.
         * @return Resulting matrix.
         */
        Matrix2x2
            operator*(const Matrix2x2& other) const {
            return Matrix2x2(
                m00 * other.m00 + m01 * other.m10,
                m00 * other.m01 + m01 * other.m11,
                m10 * other.m00 + m11 * other.m10,
                m10 * other.m01 + m11 * other.m11
            );
        }

        /**
         * @brief Multiplies this matrix by a 2D vector.
         * @param vec The vector to transform.
         * @return Transformed vector.
         */
        CVector2
            operator*(const CVector2& vec) const {
            return CVector2(
                m00 * vec.x + m01 * vec.y,
                m10 * vec.x + m11 * vec.y
            );
        }

        /**
         * @brief Multiplies this matrix by a scalar (in-place).
         * @param scalar The scalar value.
         * @return Reference to this matrix.
         */
        Matrix2x2&
            operator*=(float scalar) {
            m00 *= scalar; m01 *= scalar;
            m10 *= scalar; m11 *= scalar;
            return *this;
        }

        //Elements acces

        /**
         * @brief Accesses an element of the matrix.
         * @param row Row index (0 or 1).
         * @param col Column index (0 or 1).
         * @return Reference to the element.
         */
        float&
            operator()(int row, int col) {
            return *((&m00) + row * 2 + col);
        }

        /**
         * @brief Const access to an element of the matrix.
         * @param row Row index (0 or 1).
         * @param col Column index (0 or 1).
         * @return Const reference to the element.
         */
        const
            float& operator()(int row, int col) const {
            return *((&m00) + row * 2 + col);
        }

        //Determinant

        /**
         * @brief Calculates the determinant of the matrix.
         * @return Scalar determinant.
         */
        float
            determinant() const {
            return m00 * m11 - m01 * m10;
        }

        //Transpose

        /**
         * @brief Returns the transposed version of this matrix.
         * @return Transposed matrix.
         */
        Matrix2x2
            transpose() const {
            return Matrix2x2(
                m00, m10,
                m01, m11
            );
        }

        /**
         * @brief Returns the inverse of this matrix.
         * @return Inverted matrix, or identity if not invertible.
         */
        Matrix2x2
            inverse() const {
            float det = determinant();
            if (det == 0.f) return Matrix2x2(); // Not invertible → identity
            float invDet = 1.f / det;
            return Matrix2x2(
                m11 * invDet, -m01 * invDet,
                -m10 * invDet, m00 * invDet
            );
        }

        /**
         * @brief Sets this matrix as the identity matrix.
         */
        void
            setIdentity() {
            m00 = 1.f; m01 = 0.f;
            m10 = 0.f; m11 = 1.f;
        }

        /**
         * @brief Sets this matrix as a scale matrix.
         * @param scaleX Scale along the X axis.
         * @param scaleY Scale along the Y axis.
         */
        void
            setScale(float scaleX, float scaleY) {
            m00 = scaleX; m01 = 0.f;
            m10 = 0.f;    m11 = scaleY;
        }

        /**
         * @brief Sets this matrix as a 2D rotation matrix.
         * @param radians Angle in radians.
         */
        void
            setRotation(float radians) {
            float c = EU::Math::cos(radians);
            float s = EU::Math::sin(radians);
            m00 = c;  m01 = -s;
            m10 = s;  m11 = c;
        }

        /**
         * @brief Returns a matrix filled with zeros.
         * @return Zero matrix.
         */
        static
            Matrix2x2 zero() {
            return Matrix2x2(0.f, 0.f, 0.f, 0.f);
        }

        /**
         * @brief Returns an identity matrix.
         * @return Identity matrix.
         */
        static
            Matrix2x2 identity() {
            return Matrix2x2();
        }
    };

} // namespace EU