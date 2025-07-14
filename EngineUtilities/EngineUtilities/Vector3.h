#pragma once

/**
 * @file Vector3.h
 * @brief Declara la estructura Vector3 para representar vectores tridimensionales y operaciones básicas.
 */

#include <cmath>
#include <string>
#include <sstream>

namespace EngineUtilities {

    /**
     * @struct Vector3
     * @brief Representa un vector tridimensional con componentes X, Y y Z.
     */
    struct Vector3 {
        float x, y, z; ///< Componentes del vector en los ejes X, Y y Z.

        /**
         * @brief Constructor que inicializa las componentes del vector.
         * @param x Componente X (por defecto 0.0f).
         * @param y Componente Y (por defecto 0.0f).
         * @param z Componente Z (por defecto 0.0f).
         */
        Vector3(float x = 0.0f, float y = 0.0f, float z = 0.0f) : x(x), y(y), z(z) {}

        /**
         * @brief Calcula la magnitud (longitud) del vector.
         * @return Magnitud como valor flotante.
         */
        float magnitude() const {
            return std::sqrt(x * x + y * y + z * z);
        }

        /**
         * @brief Devuelve una versión normalizada del vector.
         *
         * Si la magnitud es cero, devuelve el vector (0, 0, 0).
         *
         * @return Vector normalizado.
         */
        Vector3 normalized() const {
            float mag = magnitude();
            return mag > 0.0f ? Vector3(x / mag, y / mag, z / mag) : Vector3();
        }

        /**
         * @brief Calcula el producto punto (escalares) con otro vector.
         * @param other Vector con el que se realiza el producto punto.
         * @return Resultado del producto punto.
         */
        float dot(const Vector3& other) const {
            return x * other.x + y * other.y + z * other.z;
        }

        /**
         * @brief Calcula el producto cruz (vectorial) con otro vector.
         * @param other Vector con el que se realiza el producto cruz.
         * @return Vector resultante del producto cruz.
         */
        Vector3 cross(const Vector3& other) const {
            return Vector3(
                y * other.z - z * other.y,
                z * other.x - x * other.z,
                x * other.y - y * other.x
            );
        }

        /**
         * @brief Convierte el vector a una representación en cadena.
         * @return Cadena con el formato "(x, y, z)".
         */
        std::string toString() const {
            std::ostringstream ss;
            ss << "(" << x << ", " << y << ", " << z << ")";
            return ss.str();
        }

        // TODO: Agregar operadores aritméticos para facilitar cálculos vectoriales.
    };

} // namespace EngineUtilities