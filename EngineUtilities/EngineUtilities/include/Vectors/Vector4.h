#pragma once

//#include "../Prerequisites.h"
#include <Math/EngineMath.h>
#include <Math/EngineMath.h>

/**
 * @file CVector4.h
 * @brief Represents a custom 4D vector with common mathematical operations.
 */
class
    CVector4 {
public:
    float x;
    float y;
    float z;
    float w;

    // Constructors

    /**
     * @brief Default constructor. Initializes the vector to (0, 0, 0, 0).
     */
    CVector4() : x(0.f), y(0.f), z(0.f), w(0.f) {}

    /**
     * @brief Parameterized constructor.
     * @param x The X component.
     * @param y The Y component.
     * @param z The Z component.
     * @param w The W component.
     */
    CVector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

    // Arithmetic operators
    CVector4
        operator+(const CVector4& other) const {
        return CVector4(x + other.x, y + other.y, z + other.z, w + other.w);
    }

    CVector4
        operator-(const CVector4& other) const {
        return CVector4(x - other.x, y - other.y, z - other.z, w - other.w);
    }

    CVector4
        operator*(float scalar) const {
        return CVector4(x * scalar, y * scalar, z * scalar, w * scalar);
    }

    CVector4
        operator/(float divisor) const {
        return CVector4(x / divisor, y / divisor, z / divisor, w / divisor);
    }

    // Compound assignment operators
    CVector4&
        operator+=(const CVector4& other) {
        x += other.x;
        y += other.y;
        z += other.z;
        w += other.w;
        return *this;
    }

    CVector4&
        operator-=(const CVector4& other) {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        w -= other.w;
        return *this;
    }

    CVector4&
        operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        w *= scalar;
        return *this;
    }

    CVector4&
        operator/=(float scalar) {
        x /= scalar;
        y /= scalar;
        z /= scalar;
        w /= scalar;
        return *this;
    }

    // Comparison operators
    bool
        operator==(const CVector4& other) const {
        return x == other.x && y == other.y && z == other.z && w == other.w;
    }

    bool
        operator!=(const CVector4& other) const {
        return !(*this == other);
    }

    // Index access

    /**
     * @brief Access vector components by index.
     * @param index 0 for x, 1 for y, 2 for z, 3 for w.
     * @return Reference to the component.
     */
    float& operator[](int index) {
        switch (index) {
        case 0: return x;
        case 1: return y;
        case 2: return z;
        default: return w;
        }
    }

    const
        float& operator[](int index) const {
        switch (index) {
        case 0: return x;
        case 1: return y;
        case 2: return z;
        default: return w;
        }
    }

    // Geometric functions

    /**
     * @brief Calculates the length (magnitude) of the vector.
     * @return The Euclidean length.
     */
    float
        length() const {
        return EU::Math::sqrt(x * x + y * y + z * z + w * w);
    }

    /**
     * @brief Calculates the squared length. Useful for comparisons (avoids sqrt).
     * @return The squared length.
     */
    float
        lengthSquared() const {
        return x * x + y * y + z * z + w * w;
    }

    /**
     * @brief Calculates the dot (scalar) product between this and another vector.
     * @param other The other vector.
     * @return The dot product.
     */
    float
        dot(const CVector4& other) const {
        return x * other.x + y * other.y + z * other.z + w * other.w;
    }

    /**
     * @brief Returns a normalized copy of this vector.
     * @return A unit vector, or (0,0,0,0) if length is zero.
     */
    CVector4 normalized() const {
        float len = length();
        if (len == 0.f) return CVector4(0.f, 0.f, 0.f, 0.f);
        return CVector4(x / len, y / len, z / len, w / len);
    }

    /**
     * @brief Normalizes this vector in-place.
     */
    void
        normalize() {
        float len = length();
        if (len != 0.f) {
            x /= len;
            y /= len;
            z /= len;
            w /= len;
        }
    }

    // Static utility methods

    /**
     * @brief Calculates the distance between two 4D vectors.
     * @param a First vector.
     * @param b Second vector.
     * @return Distance.
     */
    static
        float distance(const CVector4& a, const CVector4& b) {
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
        CVector4 lerp(const CVector4& a, const CVector4& b, float t) {
        if (t < 0.f) t = 0.f;
        if (t > 1.f) t = 1.f;
        return a + (b - a) * t;
    }

    /**
     * @brief Returns a zero vector (0,0,0,0).
     */
    static
        CVector4 zero() {
        return CVector4(0.f, 0.f, 0.f, 0.f);
    }

    /**
     * @brief Returns a vector with all components set to 1.
     */
    static
        CVector4 one() {
        return CVector4(1.f, 1.f, 1.f, 1.f);
    }

    // Transform-style debug methods

    /**
     * @brief Sets this vector as a position.
     * @param position A vector representing absolute position.
     */
    void
        setPosition(const CVector4& position) {
        x = position.x;
        y = position.y;
        z = position.z;
        w = position.w;
    }

    /**
     * @brief Moves this vector by an offset.
     * @param offset A vector representing the amount to move.
     */
    void
        move(const CVector4& offset) {
        x += offset.x;
        y += offset.y;
        z += offset.z;
        w += offset.w;
    }

    /**
     * @brief Sets the scale of this vector.
     * @param factors A vector of scale factors.
     */
    void
        setScale(const CVector4& factors) {
        x = factors.x;
        y = factors.y;
        z = factors.z;
        w = factors.w;
    }

    /**
     * @brief Multiplies this vector by scale factors.
     * @param factors A vector of scale factors.
     */
    void
        scale(const CVector4& factors) {
        x *= factors.x;
        y *= factors.y;
        z *= factors.z;
        w *= factors.w;
    }

    /**
     * @brief Sets this vector as an origin point.
     * @param origin A vector representing origin.
     */
    void
        setOrigin(const CVector4& origin) {
        x = origin.x;
        y = origin.y;
        z = origin.z;
        w = origin.w;
    }

};