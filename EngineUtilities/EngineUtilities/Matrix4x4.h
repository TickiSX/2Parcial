#pragma once

/**
 * @file Matrix4x4.h
 * @brief Declara la estructura Matrix4x4 para representar transformaciones 3D en coordenadas homogéneas.
 */

#include <cmath>

namespace EngineUtilities {

    /**
     * @struct Matrix4x4
     * @brief Representa una matriz 4x4 utilizada para transformaciones 3D como traslación, rotación y escala.
     */
    struct Matrix4x4 {
        float m[4][4]; ///< Arreglo que almacena los valores de la matriz en forma [fila][columna].

        /**
         * @brief Constructor que inicializa la matriz como identidad escalada.
         * @param diag Valor asignado a los elementos de la diagonal principal (por defecto 1.0f).
         */
        Matrix4x4(float diag = 1.0f) {
            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 4; ++j)
                    m[i][j] = (i == j) ? diag : 0.0f;
        }

        /**
         * @brief Devuelve una matriz identidad 4x4.
         * @return Matriz identidad.
         */
        static Matrix4x4 identity() {
            return Matrix4x4(1.0f);
        }

        /**
         * @brief Calcula la transpuesta de la matriz.
         * @return Matriz transpuesta.
         */
        Matrix4x4 transpose() const {
            Matrix4x4 result;
            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 4; ++j)
                    result.m[i][j] = m[j][i];
            return result;
        }

        // Determinante e inversa no implementadas por simplicidad inicial.

        /**
         * @brief Crea una matriz de traslación en 3D.
         * @param tx Traslación en eje X.
         * @param ty Traslación en eje Y.
         * @param tz Traslación en eje Z.
         * @return Matriz de traslación.
         */
        static Matrix4x4 translate(float tx, float ty, float tz) {
            Matrix4x4 result = identity();
            result.m[0][3] = tx;
            result.m[1][3] = ty;
            result.m[2][3] = tz;
            return result;
        }

        /**
         * @brief Crea una matriz de escala en 3D.
         * @param sx Escala en eje X.
         * @param sy Escala en eje Y.
         * @param sz Escala en eje Z.
         * @return Matriz de escala.
         */
        static Matrix4x4 scale(float sx, float sy, float sz) {
            Matrix4x4 result = identity();
            result.m[0][0] = sx;
            result.m[1][1] = sy;
            result.m[2][2] = sz;
            return result;
        }

        /**
         * @brief Crea una matriz de rotación en torno al eje X.
         * @param angle Ángulo en radianes.
         * @return Matriz de rotación en X.
         */
        static Matrix4x4 rotateX(float angle) {
            Matrix4x4 result = identity();
            float c = std::cos(angle), s = std::sin(angle);
            result.m[1][1] = c;  result.m[1][2] = -s;
            result.m[2][1] = s;  result.m[2][2] = c;
            return result;
        }

        /**
         * @brief Crea una matriz de rotación en torno al eje Y.
         * @param angle Ángulo en radianes.
         * @return Matriz de rotación en Y.
         */
        static Matrix4x4 rotateY(float angle) {
            Matrix4x4 result = identity();
            float c = std::cos(angle), s = std::sin(angle);
            result.m[0][0] = c;  result.m[0][2] = s;
            result.m[2][0] = -s; result.m[2][2] = c;
            return result;
        }

        /**
         * @brief Crea una matriz de rotación en torno al eje Z.
         * @param angle Ángulo en radianes.
         * @return Matriz de rotación en Z.
         */
        static Matrix4x4 rotateZ(float angle) {
            Matrix4x4 result = identity();
            float c = std::cos(angle), s = std::sin(angle);
            result.m[0][0] = c;  result.m[0][1] = -s;
            result.m[1][0] = s;  result.m[1][1] = c;
            return result;
        }
    };

} // namespace EngineUtilities