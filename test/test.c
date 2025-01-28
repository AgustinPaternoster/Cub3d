# include <math.h>
# include <stdio.h>

double radianes_a_grados(double radianes) {
    return radianes * (180.0 / M_PI);
}
float to_radians(int degrees)
{
	return ((M_PI * degrees) / 180);
}

int main(void) {
    float delta_ini[2];
    float delta_check[2];
	float start;

	delta_ini[0] = cos(to_radians(45));
	delta_ini[1] = sin(to_radians(45));

	delta_check[0] = cos(to_radians(80));
	delta_check[1] = sin(to_radians(80));

	printf("ata:%f\n", atan2(delta_ini[1],delta_ini[0]) - atan2(delta_check[1],delta_check[0]));
	printf("gra:%f\n", radianes_a_grados(atan2(delta_ini[1],delta_ini[0]) - atan2(delta_check[1],delta_check[0])));

    return (0);	
}