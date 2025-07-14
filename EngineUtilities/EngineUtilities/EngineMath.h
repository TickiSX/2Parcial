#pragma once

/**
 * @file MathUtils.h
 * @brief Funciones matemáticas básicas y utilidades para uso general en el motor.
 */

#include <cmath>

namespace EngineUtilities {

    /**
     * @name Funciones matemáticas básicas
     * @{
     */
    inline float square(float x) { return x * x; }
    inline float cube(float x) { return x * x * x; }
    inline float power(float base, float exp) { return std::pow(base, exp); }
    inline float abs(float x) { return std::fabs(x); }
    inline float round(float x) { return std::round(x); }
    inline float floor(float x) { return std::floor(x); }
    inline float ceil(float x) { return std::ceil(x); }
    inline float mod(float x, float y) { return std::fmod(x, y); }
    inline float exp(float x) { return std::exp(x); }
    inline float log(float x) { return std::log(x); }
    inline float log10(float x) { return std::log10(x); }
    inline float sqrt(float x) { return std::sqrt(x); }
    /** @} */

    /**
     * @name Funciones trigonométricas
     * @{
     */
    inline float sin(float x) { return std::sin(x); }
    inline float cos(float x) { return std::cos(x); }
    inline float tan(float x) { return std::tan(x); }
    inline float asin(float x) { return std::asin(x); }
    inline float acos(float x) { return std::acos(x); }
    inline float atan(float x) { return std::atan(x); }
    inline float sinh(float x) { return std::sinh(x); }
    inline float cosh(float x) { return std::cosh(x); }
    inline float tanh(float x) { return std::tanh(x); }
    /** @} */

    /**
     * @name Conversión angular
     * @{
     */
    inline float radians(float degrees) { return degrees * (3.14159265f / 180.0f); }
    inline float degrees(float radians) { return radians * (180.0f / 3.14159265f); }
    /** @} */

    /**
     * @name Funciones geométricas
     * @{
     */
    inline float circleArea(float r) { return 3.14159265f * r * r; }
    inline float circleCircumference(float r) { return 2 * 3.14159265f * r; }
    inline float rectangleArea(float w, float h) { return w * h; }
    inline float rectanglePerimeter(float w, float h) { return 2 * (w + h); }
    inline float triangleArea(float b, float h) { return 0.5f * b * h; }
    inline float distance(float x1, float y1, float x2, float y2) {
        return sqrt(square(x2 - x1) + square(y2 - y1));
    }
    /** @} */

    /**
     * @name Otras utilidades
     * @{
     */
    inline float lerp(float a, float b, float t) { return a + t * (b - a); }

    /**
     * @brief Calcula el factorial de un número entero no negativo.
     * @param n Número entero.
     * @return Factorial de n.
     */
    inline int factorial(int n) { return (n <= 1) ? 1 : n * factorial(n - 1); }

    /**
     * @brief Compara dos números flotantes con un margen de error.
     * @param a Primer número.
     * @param b Segundo número.
     * @param epsilon Margen de error permitido (por defecto 1e-5).
     * @return true si los números son aproximadamente iguales.
     */
    inline bool approxEqual(float a, float b, float epsilon = 1e-5f) {
        return abs(a - b) < epsilon;
    }
    /** @} */

} // namespace EngineUtilities