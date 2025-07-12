#pragma once

/**
 * @file Quaternion.h
 * @brief Declara la estructura Quaternion para representar rotaciones en 3D.
 */

#include <cmath>

namespace EngineUtilities {

    /**
     * @struct Quaternion
     * @brief Representa una rotación en 3D utilizando cuaterniones.
     *
     * Los cuaterniones se usan ampliamente en gráficos 3D por su eficiencia y estabilidad al representar rotaciones sin problemas de gimbal lock.
     */
    struct Quaternion {
        float w, x, y, z; ///< Componentes del cuaternión: escalar (w) y vectorial (x, y, z).

        /**
         * @brief Constructor con componentes personalizados.
         * @param w Parte escalar (por defecto 1.0f).
         * @param x Componente X.
         * @param y Componente Y.
         * @param z Componente Z.
         */
        Quaternion(float w = 1.0f, float x = 0.0f, float y = 0.0f, float z = 0.0f)
            : w(w), x(x), y(y), z(z) {
        }

        /**
         * @brief Calcula la magnitud (norma) del cuaternión.
         * @return Valor de la magnitud.
         */
        float magnitude() const {
            return std::sqrt(w * w + x * x + y * y + z * z);
        }

        /**
         * @brief Devuelve una copia normalizada del cuaternión.
         *
         * Si la magnitud es cero, se devuelve un cuaternión por defecto (identidad).
         * @return Cuaternión normalizado.
         */
        Quaternion normalized() const {
            float mag = magnitude();
            return mag > 0.0f ? Quaternion(w / mag, x / mag, y / mag, z / mag) : Quaternion();
        }

        /**
         * @brief Devuelve el conjugado del cuaternión.
         *
         * El conjugado invierte el vector (x, y, z) y deja intacta la parte escalar (w).
         * @return Cuaternión conjugado.
         */
        Quaternion conjugate() const {
            return Quaternion(w, -x, -y, -z);
        }

        // TODO: Implementar multiplicación entre cuaterniones y rotación de vectores.
    };

} // namespace EngineUtilities