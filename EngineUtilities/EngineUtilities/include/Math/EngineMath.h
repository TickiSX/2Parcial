#pragma once

//#include "../Prerequisites.h" // Add this to Prerequisites

/**
 * @file EngineMath.h
 * @brief Provides general mathematical utility functions used across the engine.
 */

namespace EU {
    namespace Math {

        // Basic Math Functions

        /**
         * @brief Computes the square root using the Newton-Raphson method.
         * @param x Input value.
         * @return Approximate square root.
         */
        inline
            float sqrt(float x) {
            if (x <= 0.f) return 0.f;
            float guess = x / 2.f;
            for (int i = 0; i < 10; ++i) {
                guess = 0.5f * (guess + x / guess);
            }
            return guess;
        }

        /**
         * @brief Returns the square of a number.
         * @param x Input value.
         * @return x squared.
         */
        inline
            float square(float x) {
            return x * x;
        }

        /**
         * @brief Returns the cube of a number.
         * @param x Input value.
         * @return x cubed.
         */
        inline
            float cube(float x) {
            return x * x * x;
        }

        /**
         * @brief Raises x to the power of n (integer exponent).
         * @param x Base value.
         * @param n Exponent value.
         * @return x raised to the power of n.
         */
        inline
            float power(float x, int n) {
            float result = 1.f;
            for (int i = 0; i < n; ++i) {
                result *= x;
            }
            return result;
        }

        /**
         * @brief Returns the absolute value.
         * @param x Input value.
         * @return Absolute value of x.
         */
        inline
            float abs(float x) {
            return x < 0.f ? -x : x;
        }

        /**
         * @brief Returns the maximum between two values.
         * @param a First value.
         * @param b Second value.
         * @return Greater of a or b.
         */
        inline
            float EMax(float a, float b) {
            return a > b ? a : b;
        }

        /**
         * @brief Returns the minimum between two values.
         * @param a First value.
         * @param b Second value.
         * @return Lesser of a or b.
         */
        inline
            float EMin(float a, float b) {
            return a < b ? a : b;
        }

        // Rounding

        /**
         * @brief Rounds to the nearest integer.
         * @param x Input value.
         * @return Rounded integer.
         */
        inline
            int round(float x) {
            return (x >= 0.f) ? static_cast<int>(x + 0.5f) : static_cast<int>(x - 0.5f);
        }

        /**
         * @brief Rounds down to the nearest integer.
         * @param x Input value.
         * @return Floored integer.
         */
        inline
            int floor(float x) {
            int i = static_cast<int>(x);
            return (x < 0.f && x != i) ? i - 1 : i;
        }

        /**
         * @brief Rounds up to the nearest integer.
         * @param x Input value.
         * @return Ceiled integer.
         */
        inline
            int ceil(float x) {
            int i = static_cast<int>(x);
            return (x > 0.f && x != i) ? i + 1 : i;
        }

        /**
         * @brief Returns the floating-point absolute value.
         * @param x Input value.
         * @return Absolute value.
         */
        inline
            float fabs(float x) {
            return abs(x);
        }

        // Exponential and Logarithmic Functions

        /**
         * @brief Returns the floating-point remainder of a / b.
         * @param a Dividend.
         * @param b Divisor.
         * @return a modulo b.
         */
        inline
            float mod(float a, float b) {
            return a - b * floor(a / b);
        }

        /**
         * @brief Approximates the exponential function e^x using Taylor series.
         * @param x Exponent.
         * @return e raised to x.
         */
        inline
            float exp(float x) {
            float result = 1.0f;
            float term = 1.0f;
            for (int i = 1; i <= 10; ++i) {
                term *= x / static_cast<float>(i);
                result += term;
            }
            return result;
        }

        /**
         * @brief Approximates the natural logarithm (ln) for values near 1.
         * @param x Input value.
         * @return Natural logarithm of x.
         */
        inline
            float log(float x) {
            if (x <= 0.f) return 0.f;
            float y = (x - 1) / (x + 1);
            float y2 = y * y;
            float result = 0.f;
            for (int i = 1; i < 10; i += 2) {
                result += 1.0f / static_cast<float>(i) * power(y, i);
            }
            return 2 * result;
        }

        /**
         * @brief Returns base-10 logarithm of x.
         * @param x Input value.
         * @return log10(x)
         */
        inline
            float log10(float x) {
            return log(x) / 2.3025851f;
        }

        // Trigonometric Functions

        /**
         * @brief Approximates sine using Taylor series.
         * @param x Angle in radians.
         * @return Sine of x.
         */
        inline
            float sin(float x) {
            while (x > 3.14159265f) x -= 2.0f * 3.14159265f;
            while (x < -3.14159265f) x += 2.0f * 3.14159265f;
            float x2 = x * x;
            return x - (x2 * x) / 6.0f + (x2 * x2 * x) / 120.0f - (x2 * x2 * x2 * x) / 5040.0f;
        }

        /**
         * @brief Approximates cosine using Taylor series.
         * @param x Angle in radians.
         * @return Cosine of x.
         */
        inline
            float cos(float x) {
            while (x > 3.14159265f) x -= 2.0f * 3.14159265f;
            while (x < -3.14159265f) x += 2.0f * 3.14159265f;
            float x2 = x * x;
            return 1.0f - x2 / 2.0f + (x2 * x2) / 24.0f - (x2 * x2 * x2) / 720.0f;
        }

        /**
         * @brief Computes tangent as sin(x)/cos(x).
         * @param x Angle in radians.
         * @return Tangent of x.
         */
        inline
            float tan(float x) {
            float c = cos(x);
            if (c == 0.f) return 0.f;
            return sin(x) / c;
        }

        /**
         * @brief Approximates arcsine using Taylor series.
         * @param x Input between -1 and 1.
         * @return arcsin(x)
         */
        inline
            float asin(float x) {
            float x2 = x * x;
            return x + (x2 * x) / 6.0f + (3 * x2 * x2 * x) / 40.0f;
        }

        /**
         * @brief Returns arccosine using identity acos(x) = π/2 - asin(x).
         * @param x Input between -1 and 1.
         * @return arccos(x)
         */
        inline
            float acos(float x) {
            return 1.5707963f - asin(x); // π/2 - asin(x)
        }

        /**
         * @brief Approximates arctangent using simplified series.
         * @param x Input value.
         * @return arctan(x)
         */
        inline
            float atan(float x) {
            return x - (x * x * x) / 3.0f + (x * x * x * x * x) / 5.0f;
        }

        /**
         * @brief Returns hyperbolic sine.
         * @param x Input value.
         * @return sinh(x)
         */
        inline
            float sinh(float x) {
            return (exp(x) - exp(-x)) / 2.0f;
        }

        /**
         * @brief Returns hyperbolic cosine.
         * @param x Input value.
         * @return cosh(x)
         */
        inline
            float cosh(float x) {
            return (exp(x) + exp(-x)) / 2.0f;
        }

        /**
         * @brief Returns hyperbolic tangent.
         * @param x Input value.
         * @return tanh(x)
         */
        inline
            float tanh(float x) {
            return sinh(x) / cosh(x);
        }

        // Angle Conversion

        /**
         * @brief Converts degrees to radians.
         * @param degrees Angle in degrees.
         * @return Angle in radians.
         */
        inline
            float radians(float degrees) {
            return degrees * 3.14159265f / 180.0f;
        }

        /**
         * @brief Converts radians to degrees.
         * @param radians Angle in radians.
         * @return Angle in degrees.
         */
        inline
            float degrees(float radians) {
            return radians * 180.0f / 3.14159265f;
        }

    } // namespace Math
} // namespace EU