#pragma once

/**
 * @file Matrix3x3.h
 * @brief Declara la estructura Matrix3x3 para representar transformaciones homogéneas 2D.
 */

#include <cmath>

namespace EngineUtilities {

    /**
     * @struct Matrix3x3
     * @brief Representa una matriz 3x3 utilizada comúnmente para transformaciones en coordenadas homogéneas 2D.
     *
     * Esta estructura permite operaciones básicas como obtener la matriz identidad, transpuesta y determinante.
     */
    struct Matrix3x3 {
        float m[3][3]; ///< Arreglo bidimensional que almacena los valores de la matriz.

        /**
         * @brief Constructor que inicializa la matriz como identidad escalada por un valor dado.
         * @param diag Valor que se asignará a la diagonal principal (por defecto 1.0f).
         */
        Matrix3x3(float diag = 1.0f) {
            for (int i = 0; i < 3; ++i)
                for (int j = 0; j < 3; ++j)
                    m[i][j] = (i == j) ? diag : 0.0f;
        }

        /**
         * @brief Genera y devuelve una matriz identidad.
         * @return Matriz identidad 3x3.
         */
        static Matrix3x3 identity() {
            return Matrix3x3(1.0f);
        }

        /**
         * @brief Calcula la matriz transpuesta.
         * @return Nueva matriz 3x3 transpuesta.
         */
        Matrix3x3 transpose() const {
            Matrix3x3 result;
            for (int i = 0; i < 3; ++i)
                for (int j = 0; j < 3; ++j)
                    result.m[i][j] = m[j][i];
            return result;
        }

        /**
         * @brief Calcula el determinante de la matriz.
         * @return Valor del determinante como número flotante.
         */
        float determinant() const {
            return m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]) -
                m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0]) +
                m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
        }

        // TODO: Implementar método inverse() para inversión de matrices 3x3.
    };

} // namespace EngineUtilities