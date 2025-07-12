#pragma once

/**
 * @file Vector4.h
 * @brief Declara la estructura Vector4 para representar vectores en 4 dimensiones y operaciones básicas.
 */

#include <cmath>
#include <string>
#include <sstream>

namespace EngineUtilities {

    /**
     * @struct Vector4
     * @brief Representa un vector en espacio 4D con componentes X, Y, Z y W.
     */
    struct Vector4 {
        float x, y, z, w; ///< Componentes del vector en las dimensiones X, Y, Z y W.

        /**
         * @brief Constructor que inicializa los componentes del vector.
         * @param x Componente X (por defecto 0.0f).
         * @param y Componente Y (por defecto 0.0f).
         * @param z Componente Z (por defecto 0.0f).
         * @param w Componente W (por defecto 0.0f).
         */
        Vector4(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 0.0f)
            : x(x), y(y), z(z), w(w) {
        }

        /**
         * @brief Calcula la magnitud (norma) del vector.
         * @return Magnitud como valor flotante.
         */
        float magnitude() const {
            return std::sqrt(x * x + y * y + z * z + w * w);
        }

        /**
         * @brief Devuelve una versión normalizada del vector.
         *
         * Si la magnitud es cero, devuelve un vector con componentes cero.
         *
         * @return Vector normalizado.
         */
        Vector4 normalized() const {
            float mag = magnitude();
            return mag > 0.0f ? Vector4(x / mag, y / mag, z / mag, w / mag) : Vector4();
        }

        /**
         * @brief Calcula el producto punto con otro vector 4D.
         * @param other Vector con el que se realiza el producto punto.
         * @return Resultado del producto punto.
         */
        float dot(const Vector4& other) const {
            return x * other.x + y * other.y + z * other.z + w * other.w;
        }

        /**
         * @brief Convierte el vector a una cadena de texto con formato "(x, y, z, w)".
         * @return Cadena representativa del vector.
         */
        std::string toString() const {
            std::ostringstream ss;
            ss << "(" << x << ", " << y << ", " << z << ", " << w << ")";
            return ss.str();
        }

        // TODO: Añadir operadores aritméticos para facilitar cálculos vectoriales.
    };

} // namespace EngineUtilities