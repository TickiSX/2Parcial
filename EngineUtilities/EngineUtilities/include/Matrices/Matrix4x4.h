#pragma once

//#include "../Prerequisites.h"
#include <Vectors/Vector3.h>
#include <Vectors/Vector4.h>
#include <Math/EngineMath.h>

/**
 * @file Matrix4x4.h
 * @brief Represents a 4x4 matrix with standard operations for 3D transformations.
 */

namespace EU {

    /**
     * @class Matrix4x4
     * @brief A 4x4 matrix for 3D linear transformations such as translation, rotation, and scaling.
     *        Commonly used in graphics pipelines for transforming vertices and objects in 3D space.
     */
    class
        Matrix4x4 {
    public:

        /**
         * @brief Matrix elements in row-major order.
         */
        float m[4][4];

        /**
         * @brief Default constructor. Initializes the matrix as identity.
         */
        Matrix4x4();

        /**
         * @brief Constructs a matrix with 16 float values.
         * @param m00-m33 Values in row-major order.
         */
        Matrix4x4(
            float m00, float m01, float m02, float m03,
            float m10, float m11, float m12, float m13,
            float m20, float m21, float m22, float m23,
            float m30, float m31, float m32, float m33);

        /**
         * @brief Adds two matrices element-wise.
         * @param other The other matrix.
         * @return Sum of both matrices.
         */
        Matrix4x4
            operator+(const Matrix4x4& other) const;

        /**
         * @brief Subtracts two matrices element-wise.
         * @param other The matrix to subtract.
         * @return Difference of both matrices.
         */
        Matrix4x4
            operator-(const Matrix4x4& other) const;

        /**
         * @brief Multiplies each element of this matrix by a scalar.
         * @param scalar Scalar value.
         * @return Scaled matrix.
         */
        Matrix4x4
            operator*(float scalar) const;

        /**
         * @brief Multiplies this matrix by another 4x4 matrix.
         * @param other Matrix to multiply with.
         * @return Product matrix.
         */
        Matrix4x4
            operator*(const Matrix4x4& other) const;

        /**
         * @brief Transforms a 4D vector by this matrix.
         * @param vec Vector to transform.
         * @return Transformed 4D vector.
         */
        CVector4
            operator*(const CVector4& vec) const;

        /**
         * @brief Transforms a 3D vector using homogeneous coordinates.
         * @param vec 3D vector.
         * @return Transformed vector.
         */
        CVector3
            transformPoint(const CVector3& vec) const;

        /**
         * @brief Adds another matrix to this matrix (in-place).
         * @param other Matrix to add.
         * @return Reference to this matrix.
         */
        Matrix4x4&
            operator+=(const Matrix4x4& other);

        /**
         * @brief Subtracts another matrix from this matrix (in-place).
         * @param other Matrix to subtract.
         * @return Reference to this matrix.
         */
        Matrix4x4&
            operator-=(const Matrix4x4& other);

        /**
         * @brief Multiplies this matrix by a scalar (in-place).
         * @param scalar Scalar value.
         * @return Reference to this matrix.
         */
        Matrix4x4&
            operator*=(float scalar);

        /**
         * @brief Accesses a matrix element by row and column.
         * @param row Row index (0-3).
         * @param col Column index (0-3).
         * @return Reference to the element.
         */
        float&
            operator()(int row, int col);

        /**
         * @brief Const access to a matrix element.
         * @param row Row index (0-3).
         * @param col Column index (0-3).
         * @return Const reference to the element.
         */
        const
            float& operator()(int row, int col) const;

        /**
         * @brief Returns the transposed version of this matrix.
         * @return Transposed matrix.
         */
        Matrix4x4
            transpose() const;

        /**
         * @brief Sets this matrix to the identity matrix.
         */
        void
            setIdentity();

        /**
         * @brief Sets this matrix as a scaling transformation.
         * @param scaleX Scale along X.
         * @param scaleY Scale along Y.
         * @param scaleZ Scale along Z.
         */
        void
            setScale(float scaleX, float scaleY, float scaleZ);

        /**
         * @brief Sets this matrix as a translation transformation.
         * @param tx Translation along X.
         * @param ty Translation along Y.
         * @param tz Translation along Z.
         */
        void
            setTranslation(float tx, float ty, float tz);

        /**
         * @brief Sets this matrix as a Z-axis rotation matrix (for 2D rotation in 3D space).
         * @param radians Angle in radians.
         */
        void
            setRotation(float radians);

        /**
         * @brief Creates and returns an identity matrix.
         * @return Identity matrix.
         */
        static
            Matrix4x4 identity();

        /**
         * @brief Creates and returns a zero-filled matrix.
         * @return Zero matrix.
         */
        static
            Matrix4x4 zero();
    };

} // namespace EU