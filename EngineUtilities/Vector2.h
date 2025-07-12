#pragma once

/**
 * @file Vector2.h
 * @brief Declara la estructura Vector2 para representar vectores 2D y realizar operaciones b�sicas.
 */

#include <cmath>
#include <string>
#include <sstream>

namespace EngineUtilities {

    /**
     * @struct Vector2
     * @brief Representa un vector bidimensional con componentes X y Y.
     */
    struct Vector2 {
        float x, y; ///< Componentes del vector en los ejes X e Y.

        /**
         * @brief Constructor que inicializa los componentes del vector.
         * @param x Valor inicial del eje X (por defecto 0.0f).
         * @param y Valor inicial del eje Y (por defecto 0.0f).
         */
        Vector2(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}

        /**
         * @brief Calcula la magnitud (longitud) del vector.
         * @return Magnitud del vector como n�mero flotante.
         */
        float magnitude() const {
            return std::sqrt(x * x + y * y);
        }

        /**
         * @brief Devuelve una versi�n normalizada del vector.
         *
         * El vector normalizado tiene magnitud 1, pero mantiene su direcci�n.
         * Si la magnitud es cero, se devuelve el vector (0, 0).
         *
         * @return Vector normalizado.
         */
        Vector2 normalized() const {
            float mag = magnitude();
            return mag > 0.0f ? Vector2(x / mag, y / mag) : Vector2();
        }

        /**
         * @brief Calcula el producto punto entre este vector y otro.
         * @param other Otro vector con el que se calcular� el producto punto.
         * @return Resultado del producto escalar.
         */
        float dot(const Vector2& other) const {
            return x * other.x + y * other.y;
        }

        /**
         * @brief Convierte el vector a una representaci�n en cadena.
         * @return Cadena con el formato "(x, y)".
         */
        std::string toString() const {
            std::ostringstream ss;
            ss << "(" << x << ", " << y << ")";
            return ss.str();
        }

        // TODO: Agregar operadores +, -, *, / para facilitar operaciones vectoriales.
    };

} // namespace EngineUtilities