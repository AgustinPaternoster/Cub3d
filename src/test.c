/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:18:50 by apaterno          #+#    #+#             */
/*   Updated: 2025/01/17 18:26:54 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"


int main() {
    // Ángulo inicial en radianes (esto puede ser cualquier valor)
    double x = 0.0;  // Este es un ejemplo con 0, pero puede ser cualquier valor (como 280, 90, etc.)

    // Rango de 45 grados hacia adelante y hacia atrás
    double angle_min = x - M_PI / 4;  // Ángulo mínimo: x - 45° (en radianes)
    double angle_max = x + M_PI / 4;  // Ángulo máximo: x + 45° (en radianes)

    // Número de pasos
    int steps = 600;

    // Incremento en el ángulo por paso
    double increment = (angle_max - angle_min) / steps;

    // Bucle para recorrer los ángulos y calcular seno y coseno
    for (int i = 0; i < steps; i++) {
        // Calcular el ángulo en la posición i
        double current_angle = angle_min + i * increment;

        // Calcular el seno y coseno del ángulo
        double sine = sin(current_angle);
        double cosine = cos(current_angle);

        // Imprimir el resultado
        printf("Ángulo %d: %f radianes, Seno: %f, Coseno: %f\n", i, current_angle, sine, cosine);
    }

    return 0;
}






