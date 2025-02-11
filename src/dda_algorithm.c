/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:18:32 by apaterno          #+#    #+#             */
/*   Updated: 2025/02/11 17:49:15 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// float fix_distortion(t_ray *ray, float delta_dis
//, float side_dist)
// {
// 	float ray_angle;
// 	float camera_angle;
// 	float distance;
// 	//borrar
// 	float angle;
	
// 	distance = delta_dis - side_dist;
// 	ray_angle = atan2(ray->ray_dir[1], ray->ray_dir[0]);
// 	camera_angle = atan2(ray->camara_dir[1], ray->camara_dir[0]);;
// 	angle = camera_angle - ray_angle;
// 	return(distance * cos(angle)); 
// }

static int is_wall(char **mapa, int x , int y)
{
		if(mapa[y][x] == '1')
			return (1);
		return (0);
}

static void init_ray(t_game *game, int pixel)
{
	t_ray *ray;
	t_player *player;
	
	ray = game->ray;
	player = game->player;
	ray->camera_pos[0] = player->pos_x;
	ray->camera_pos[1] = player->pos_y;
	ray->camera_dx = 2 * pixel / (double)SCREEN_WITH - 1;
	ray->ray_dir[0] = player->dx + player->scr_dx * ray->camera_dx;
	ray->ray_dir[1] = player->dy + player->scr_dy * ray->camera_dx;
	ray->map_pos[0] = (int)game->player->pos_x;
	ray->map_pos[1] = (int)game->player->pos_y;
	ray->side_dis_x = fabs(1 / ray->ray_dir[0]);
	ray->side_dis_y = fabs(1 / ray->ray_dir[1]);
}

static void setup_ray(t_ray *ray)
{
	if(ray->ray_dir[0] < 0)
	{
		
		ray->stepx = -1;
		ray->delta_dis_x = (ray->camera_pos[0] - ray->map_pos[0]) * ray->side_dis_x;
	}
	else
	{
		ray->stepx = 1;
		ray->delta_dis_x = (ray->map_pos[0] + 1 - ray->camera_pos[0]) * ray->side_dis_x;
	}
	if(ray->ray_dir[1] < 0)
	{
		ray->stepy = - 1;
		ray->delta_dis_y = (ray->camera_pos[1] - ray->map_pos[1]) * ray->side_dis_y;
	}
		else
	{
		ray->stepy = 1;
		ray->delta_dis_y = (ray->map_pos[1] + 1 - ray->camera_pos[1]) * ray->side_dis_y;
	}
}

void run_dda_al(t_ray *ray , char **map)
{	
	while (!is_wall(map, ray->map_pos[0],ray->map_pos[1]))
	{
		if (ray->delta_dis_x < ray->delta_dis_y)
		{
			ray->map_pos[0] += ray->stepx;
			ray->delta_dis_x += ray->side_dis_x;
			ray->side = 0;
		}
		else
		{
			ray->map_pos[1] += ray->stepy;
			ray->delta_dis_y += ray->side_dis_y;
			ray->side = 1;
		}
	}
	if (ray->side == 0)
		ray->distance = ray->delta_dis_x - ray->side_dis_x;
	else
		ray->distance = ray->delta_dis_y - ray->side_dis_y;
}

void draw_rays(t_game *game)
{
	t_ray *ray;
	int pixel_w;
	
	ray = game->ray;
	pixel_w = 0;
	while (pixel_w < SCREEN_WITH)
	{
		init_ray(game , pixel_w);
		setup_ray(ray);
		run_dda_al(ray, game->map->map);
		//print_point(ray, game->img);
		draw_walls(game, pixel_w);
		pixel_w++;
	}
}

// 
// funcion para obtener la correcion del efecto ojo de pez
// hay que multiplicar el valor de la distancia obtenida por
// el coseno del angulo formado por el angulo formada por el vector del rayo y el la posicion
// para obtener el angulo a partir de los ray_dir se utiliza
// la funcion atan2.