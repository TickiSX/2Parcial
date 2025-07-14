#pragma once

//#include "../Prerequisites.h"
#include <Math/EngineMath.h>

/**
 * @file CVector3.h
 * @brief Represents a custom 3D vector with common mathematical operations.
 */
class
    CVector3 {
public:
    float x;
    float y;
    float z;

    // Constructors

    /**
     * @brief Default constructor. Initializes the vector to (0, 0, 0).
     */
    CVector3() : x(0.f), y(0.f), z(0.f) {}

    /**
     * @brief Parameterized constructor.
     * @param x The X component.
     * @param y The Y component.
     * @param z The Z component.
     */
    CVector3(float x, float y, float z) : x(x), y(y), z(z) {}

    // Arithmetic operators
    CVector3
        operator+(const CVector3& other) const {
        return CVector3(x + other.x, y + other.y, z + other.z);
    }

    CVector3
        operator-(const CVector3& other) const {
        return CVector3(x - other.x, y - other.y, z - other.z);
    }

    CVector3
        operator*(float scalar) const {
        return CVector3(x * scalar, y * scalar, z * scalar);
    }

    CVector3
        operator/(float divisor) const {
        return CVector3(x / divisor, y / divisor, z / divisor);
    }

    // Compound assignment operators
    CVector3&
        operator+=(const CVector3& other) {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    CVector3&
        operator-=(const CVector3& other) {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }

    CVector3&
        operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return *this;
    }

    CVector3&
        operator/=(float scalar) {
        x /= scalar;
        y /= scalar;
        z /= scalar;
        return *this;
    }

    // Comparison operators
    bool
        operator==(const CVector3& other) const {
        return x == other.x && y == other.y && z == other.z;
    }

    bool
        operator!=(const CVector3& other) const {
        return !(*this == other);
    }

    // Index access

    /**
     * @brief Access vector components by index.
     * @param index 0 for x, 1 for y, 2 for z.
     * @return Reference to the component.
     */
    float&
        operator[](int index) {
        if (index == 0) return x;
        if (index == 1) return y;
        return z;
    }

    const
        float& operator[](int index) const {
        if (index == 0) return x;
        if (index == 1) return y;
        return z;
    }

    // Geometric functions

    /**
     * @brief Calculates the length (magnitude) of the vector.
     * @return The Euclidean length.
     */
    float
        length() const {
        return EU::Math::sqrt(x * x + y * y + z * z);
    }

    /**
     * @brief Calculates the squared length. Useful for comparisons (avoids sqrt).
     * @return The squared length.
     */
    float
        lengthSquared() const {
        return x * x + y * y + z * z;
    }

    /**
     * @brief Calculates the dot (scalar) product between this and another vector.
     * @param other The other vector.
     * @return The dot product.
     */
    float
        dot(const CVector3& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    /**
     * @brief Calculates the 3D cross product between this and another vector.
     * @param other The other vector.
     * @return The resulting perpendicular vector.
     */
    CVector3
        cross(const CVector3& other) const {
        return CVector3(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        );
    }

    /**
     * @brief Returns a normalized copy of this vector.
     * @return A unit vector, or (0,0,0) if length is zero.
     */
    CVector3 normalized() const {
        float
            len = length();
        if (len == 0.f) return CVector3(0.f, 0.f, 0.f);
        return CVector3(x / len, y / len, z / len);
    }

    /**
     * @brief Normalizes this vector in-place.
     */
    void
        normalize() {
        float
            len = length();
        if (len != 0.f) {
            x /= len;
            y /= len;
            z /= len;
        }
    }

    // Static utility methods

    /**
     * @brief Calculates the distance between two points.
     * @param a First point.
     * @param b Second point.
     * @return Distance.
     */
    static
        float distance(const CVector3& a, const CVector3& b) {
        return (a - b).length();
    }

    /**
     * @brief Performs linear interpolation between two vectors.
     * @param a Start vector.
     * @param b End vector.
     * @param t Interpolation factor in [0,1].
     * @return Interpolated vector.
     */
    static
        CVector3 lerp(const CVector3& a, const CVector3& b, float t) {
        if (t < 0.f) t = 0.f;
        if (t > 1.f) t = 1.f;
        return a + (b - a) * t;
    }

    /**
     * @brief Returns a zero vector (0,0,0).
     */
    static
        CVector3 zero() {
        return CVector3(0.f, 0.f, 0.f);
    }

    /**
     * @brief Returns a vector with all components set to 1.
     */
    static
        CVector3 one() {
        return CVector3(1.f, 1.f, 1.f);
    }

    // Transform-style debug methods

    /**
     * @brief Sets this vector as a position.
     * @param position A vector representing absolute position.
     */
    void
        setPosition(const CVector3& position) {
        x = position.x;
        y = position.y;
        z = position.z;
    }

    /**
     * @brief Moves this vector by an offset.
     * @param offset A vector representing the amount to move.
     */
    void
        move(const CVector3& offset) {
        x += offset.x;
        y += offset.y;
        z += offset.z;
    }

    /**
     * @brief Sets the scale of this vector.
     * @param factors A vector of scale factors.
     */
    void
        setScale(const CVector3& factors) {
        x = factors.x;
        y = factors.y;
        z = factors.z;
    }

    /**
     * @brief Multiplies this vector by scale factors.
     * @param factors A vector of scale factors.
     */
    void
        scale(const CVector3& factors) {
        x *= factors.x;
        y *= factors.y;
        z *= factors.z;
    }

    /**
     * @brief Sets this vector as an origin point.
     * @param origin A vector representing origin.
     */
    void
        setOrigin(const CVector3& origin) {
        x = origin.x;
        y = origin.y;
        z = origin.z;
    }


};