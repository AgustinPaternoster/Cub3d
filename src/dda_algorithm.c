/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:18:32 by apaterno          #+#    #+#             */
/*   Updated: 2025/01/17 17:41:24 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void init_ray(t_game *game)
{
	t_ray *ray;
	int angle;


	angle = game->player->direction;
	ray = game->ray;
	ray->map_pos[0] = (int)game->player->pos_x;
	ray->map_pos[1] = (int)game->player->pos_y;
	ray->side_dis_x = calculate_sx(to_radians(angle));
	ray->side_dis_y = calculate_sy(to_radians(angle));
}

void setup_ray(t_game *game)
{
	t_ray *ray;

	ray = game->ray;
	if(game->player->dx < 0)
	{
		ray->stepx = -1;
		ray->delta_dis_x = (game->player->pos_x - ray->map_pos[0]) * ray->side_dis_x;
	}
	else
	{
		ray->stepx = 1;
		ray->delta_dis_x = (ray->map_pos[0] + 1 - game->player->pos_x) * ray->side_dis_x;
	}
	if(game->player->dy < 0)
	{
		ray->stepy = - 1;
		ray->delta_dis_y = (game->player->pos_y - ray->map_pos[1]) * ray->side_dis_y;
	}
		else
	{
		ray->stepy = 1;
		ray->delta_dis_y = (ray->map_pos[1] + 1 - game->player->pos_y) * ray->side_dis_y;
	}
}

void run_dda_al(t_game *game)
{
	int hit;
	t_ray *ray;

	hit = 0;
	ray = game->ray;
	while (!is_wall(game, ray->map_pos[0],ray->map_pos[1]))
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
}

void print_point(t_game *game)
{
	float distance;
	t_ray *ray;
	int x;
	int y;
	
	ray = game->ray;
	if(ray->side == 0)
		distance = ray->delta_dis_x - ray->side_dis_x;
	else
		distance = ray->delta_dis_y - ray->side_dis_y;
	x = round(end_point(distance, game->player->pos_x, game->player->dx));
	y = round(end_point(distance, game->player->pos_y, game->player->dy));
	img_pixel_put(game->img, x , y , GREEN);
	
}

void draw_ray(t_game *game)
{
	init_ray(game);
	setup_ray(game);
	run_dda_al(game);
	print_point(game);
}