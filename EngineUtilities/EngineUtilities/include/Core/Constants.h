#pragma once

/**
 * @file Constants.h
 * @brief Defines commonly used mathematical constants for the engine.
 */

namespace EU {
    namespace Constants {

        // Pi and common multiples
        constexpr float PI = 3.14159265358979323846f;
        constexpr float TWO_PI = 6.28318530717958647692f; // 2 * PI
        constexpr float HALF_PI = 1.57079632679489661923f; // PI / 2
        constexpr float QUARTER_PI = 0.785398163397448309616f; // PI / 4

        // Degree ↔ Radian conversion
        constexpr float DEG_TO_RAD = PI / 180.0f;
        constexpr float RAD_TO_DEG = 180.0f / PI;

        // Epsilon for floating-point comparison
        constexpr float EPSILON = 1e-6f;

        // Useful constants
        constexpr float ONE = 1.0f;
        constexpr float ZERO = 0.0f;
        constexpr float INF = 1e30f;   // Not technically infinity, but large enough
        constexpr float NEG_INF = -1e30f;

    } // namespace Constants
} // namespace EngineUtilities