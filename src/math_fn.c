/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_fn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:25:55 by apaterno          #+#    #+#             */
/*   Updated: 2025/02/12 18:24:51 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

float to_radians(int degrees)
{
	return ((M_PI * degrees) / 180);
}

void init_player_dir(t_game *game, char dir)
{
	if (dir == 'N')
	{
		game->player->dx = 0;
		game->player->dy = -1 * 1;	
	}
	if (dir == 'S')
	{
		game->player->dx = 0;
		game->player->dy = -1 * -1;	
	}
	if (dir == 'E')
	{
		game->player->dx = 1;
		game->player->dy = -1 * 0;	
	}
	if (dir == 'W')
	{
		game->player->dx = -1;
		game->player->dy = -1 * 0;	
	}
	game->player->scr_dx = game->player->dy ;
	game->player->scr_dy = game->player->dx * - 1;
}

float calculate_sx(float dx , float dy)
{
	float x;	
	// corregir division por 0
	x = pow((dy / dx) ,2);
	return(sqrt(1 + x));
}

float calculate_sy(float dx , float dy)
{
	float x;
		// corregir division por 0
	x = pow((dx / dy ), 2);
	return(sqrt(1 + x));
}

float end_point(float distance, float start, float dir)
{
	return(start * GRIDSIZE + (distance * dir * GRIDSIZE));
}

void update_delta(t_game *game, int dir)
{
	float tmp_dirx;
	float tmp_scrdx;
	t_player *player;
	
	player = game->player;
	tmp_dirx = player->dx;
	player->dx = player->dx * cos(RADIAN * VELO_ROT  * dir) - 
				player->dy * sin(RADIAN * VELO_ROT  * dir);
	player->dy = tmp_dirx * sin(RADIAN * VELO_ROT  * dir) + 
				player->dy * cos(RADIAN * VELO_ROT  * dir);
	tmp_scrdx = player->scr_dx;
	player->scr_dx = player->scr_dx * cos(RADIAN * VELO_ROT  * dir) -
					player->scr_dy * sin(RADIAN * VELO_ROT  * dir);
	player->scr_dy = tmp_scrdx * sin(RADIAN * VELO_ROT  * dir) +
					player->scr_dy * cos(RADIAN * VELO_ROT  * dir);
}