#include <math.h>
#include <stdio.h>

// Estructura para el jugador
typedef struct {
    int x;
    int y;
    float angle; // Ángulo en grados
} Player;

// Función para convertir grados a radianes
float degrees_to_radians(float degrees) {
    return degrees * (M_PI / 180.0);
}

// Función para calcular el vector de movimiento
void calculate_movement_vector(float angle, float *dx, float *dy) {
    float radians = degrees_to_radians(angle);
    *dx = cos(radians);
    *dy = sin(radians);
}

// Función para actualizar la posición del jugador
void update_player_position(Player *player, float dx, float dy) {
    player->x = round(player->x + dx);
    player->y = round(player->y - dy); // SDL usa un sistema de coordenadas donde y aumenta hacia abajo
}

int main() {
    Player player = {0, 0, 20.0}; // Ángulo inicial de 20 grados
    float dx, dy;

    // Calcular el vector de movimiento
    calculate_movement_vector(player.angle, &dx, &dy);

    // Simular la presión de la tecla de espacio
    printf("Posición inicial: (%d, %d)\n", player.x, player.y);
    update_player_position(&player, dx, dy);
    printf("Posición después de moverse: (%d, %d)\n", player.x, player.y);
	update_player_position(&player, dx, dy);
    printf("Posición después de moverse: (%d, %d)\n", player.x, player.y);
    update_player_position(&player, dx, dy);
    printf("Posición después de moverse: (%d, %d)\n", player.x, player.y);
	update_player_position(&player, dx, dy);
    printf("Posición después de moverse: (%d, %d)\n", player.x, player.y);
	update_player_position(&player, dx, dy);
    printf("Posición después de moverse: (%d, %d)\n", player.x, player.y);
	
	return 0;
}
