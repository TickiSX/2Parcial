#pragma once

//#include "../Prerequisites.h"
#include <Vectors/Vector3.h>
#include <Math/EngineMath.h>

namespace EU {

    /**
     * @file Quaternion.h
     * @brief Represents a 3D rotation using quaternions.
     */
    class
        Quaternion {
    public:
        float x;
        float y;
        float z;
        float w;

        // Constructors

        /**
         * @brief Default constructor. Creates an identity quaternion (0,0,0,1).
         */
        Quaternion()
            : x(0.f), y(0.f), z(0.f), w(1.f) {
        }

        /**
         * @brief Parameterized constructor.
         * @param x X component.
         * @param y Y component.
         * @param z Z component.
         * @param w W component (real part).
         */
        Quaternion(float x, float y, float z, float w)
            : x(x), y(y), z(z), w(w) {
        }

        // Operators

        /**
         * @brief Multiplies two quaternions (combines rotations).
         */
        Quaternion
            operator*(const Quaternion& other) const {
            return Quaternion(
                w * other.x + x * other.w + y * other.z - z * other.y,
                w * other.y - x * other.z + y * other.w + z * other.x,
                w * other.z + x * other.y - y * other.x + z * other.w,
                w * other.w - x * other.x - y * other.y - z * other.z
            );
        }

        Quaternion&
            operator*=(const Quaternion& other) {
            *this = *this * other;
            return *this;
        }

        bool
            operator==(const Quaternion& other) const {
            return x == other.x && y == other.y && z == other.z && w == other.w;
        }

        bool
            operator!=(const Quaternion& other) const {
            return !(*this == other);
        }

        // Utilities

        /**
         * @brief Returns the magnitude of the quaternion.
         */
        float
            length() const {
            return Math::sqrt(x * x + y * y + z * z + w * w);
        }

        /**
         * @brief Normalizes the quaternion.
         */
        void
            normalize() {
            float len = length();
            if (len == 0.f) return;
            x /= len;
            y /= len;
            z /= len;
            w /= len;
        }

        /**
         * @brief Returns a normalized version of this quaternion.
         */
        Quaternion
            normalized() const {
            float len = length();
            if (len == 0.f) return Quaternion(0.f, 0.f, 0.f, 1.f);
            return Quaternion(x / len, y / len, z / len, w / len);
        }

        /**
         * @brief Returns the inverse of this quaternion.
         */
        Quaternion
            inverse() const {
            float lenSq = x * x + y * y + z * z + w * w;
            if (lenSq == 0.f) return Quaternion(); // Return identity
            return Quaternion(-x / lenSq, -y / lenSq, -z / lenSq, w / lenSq);
        }

        /**
         * @brief Creates a quaternion from an axis and angle (in radians).
         * @param axis Rotation axis.
         * @param angle Angle in radians.
         */
        static
            Quaternion fromAxisAngle(const CVector3& axis, float angle) {
            float halfAngle = angle * 0.5f;
            float s = Math::sin(halfAngle);
            float c = Math::cos(halfAngle);
            return Quaternion(axis.x * s, axis.y * s, axis.z * s, c);
        }

        /**
         * @brief Rotates a 3D vector using this quaternion.
         * @param v Vector to rotate.
         * @return Rotated vector.
         */
        CVector3
            rotate(const CVector3& v) const {
            Quaternion qv(v.x, v.y, v.z, 0.f);
            Quaternion result = (*this) * qv * inverse();
            return CVector3(result.x, result.y, result.z);
        }

        /**
         * @brief Linearly interpolates between two quaternions (not normalized).
         * @param a Start quaternion.
         * @param b End quaternion.
         * @param t Interpolation factor (0-1).
         */
        static
            Quaternion lerp(const Quaternion& a, const Quaternion& b, float t) {
            t = (t < 0.f) ? 0.f : ((t > 1.f) ? 1.f : t);
            return Quaternion(
                a.x + (b.x - a.x) * t,
                a.y + (b.y - a.y) * t,
                a.z + (b.z - a.z) * t,
                a.w + (b.w - a.w) * t
            ).normalized();
        }

        /**
         * @brief Returns the identity quaternion (no rotation).
         */
        static
            Quaternion identity() {
            return Quaternion(0.f, 0.f, 0.f, 1.f);
        }

    };

} // namespace EU