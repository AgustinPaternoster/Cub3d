/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:18:32 by apaterno          #+#    #+#             */
/*   Updated: 2025/01/22 18:10:36 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void init_ray(t_game *game, float angle)
{
	t_ray *ray;

	ray = game->ray;
	ray->camera_pos[0] = game->player->pos_x;
	ray->camera_pos[1] = game->player->pos_y;
	ray->delta[0] = cos(angle);
	ray->delta[1] = sin(angle) * -1;
	ray->map_pos[0] = (int)game->player->pos_x;
	ray->map_pos[1] = (int)game->player->pos_y;
	ray->side_dis_x = calculate_sx(angle);
	ray->side_dis_y = calculate_sy(angle);
}

static void setup_ray(t_ray *ray)
{
	if(ray->delta[0] < 0)
	{
		ray->stepx = -1;
		ray->delta_dis_x = (ray->camera_pos[0] - ray->map_pos[0]) * ray->side_dis_x;
	}
	else
	{
		ray->stepx = 1;
		ray->delta_dis_x = (ray->map_pos[0] + 1 - ray->camera_pos[0]) * ray->side_dis_x;
	}
	if(ray->delta[1] < 0)
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
	float start;
	float increment;
	int		count;
	
	ray = game->ray;
	start = to_radians(game->player->direction) - M_PI / 4;
	increment = (M_PI / 2) / (SCREEN_HIGH - 1);
	count = 0;
	while (count < SCREEN_HIGH)
	{
		init_ray(game , start);
		setup_ray(ray);
		run_dda_al(ray, game->map->map);
		print_point(ray, game->img);
		start +=increment;
		count++;
	}
}