#pragma once

/**
 * @file Matrix2x2.h
 * @brief Declara la estructura Matrix2x2 para operaciones matriciales básicas en 2D.
 */

#include <cmath>

namespace EngineUtilities {

    /**
     * @struct Matrix2x2
     * @brief Representa una matriz 2x2 con operaciones comunes como determinante, transposición e inversa.
     */
    struct Matrix2x2 {
        float m[2][2]; ///< Arreglo que almacena los elementos de la matriz en forma [fila][columna].

        /**
         * @brief Constructor con valores personalizados.
         *
         * Por defecto crea la matriz identidad:
         *
         * ```
         * | 1 0 |
         * | 0 1 |
         * ```
         *
         * @param a Elemento en posición (0,0).
         * @param b Elemento en posición (0,1).
         * @param c Elemento en posición (1,0).
         * @param d Elemento en posición (1,1).
         */
        Matrix2x2(float a = 1.0f, float b = 0.0f, float c = 0.0f, float d = 1.0f) {
            m[0][0] = a; m[0][1] = b;
            m[1][0] = c; m[1][1] = d;
        }

        /**
         * @brief Calcula el determinante de la matriz.
         * @return Determinante como un número flotante.
         */
        float determinant() const {
            return m[0][0] * m[1][1] - m[0][1] * m[1][0];
        }

        /**
         * @brief Devuelve la matriz transpuesta.
         *
         * Intercambia filas por columnas:
         * ```
         * | a b |     | a c |
         * | c d | --> | b d |
         * ```
         *
         * @return Nueva matriz transpuesta.
         */
        Matrix2x2 transpose() const {
            return Matrix2x2(
                m[0][0], m[1][0],
                m[0][1], m[1][1]
            );
        }

        /**
         * @brief Calcula la inversa de la matriz si existe.
         *
         * En caso de que el determinante sea cero, devuelve la matriz identidad como fallback.
         *
         * @return Matriz inversa o identidad si no es invertible.
         */
        Matrix2x2 inverse() const {
            float det = determinant();
            if (det == 0.0f) return Matrix2x2(); // No invertible, retorna identidad
            float invDet = 1.0f / det;
            return Matrix2x2(
                m[1][1] * invDet, -m[0][1] * invDet,
                -m[1][0] * invDet, m[0][0] * invDet
            );
        }
    };

} // namespace EngineUtilities