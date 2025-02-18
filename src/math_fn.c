/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_fn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:25:55 by apaterno          #+#    #+#             */
/*   Updated: 2025/02/18 19:19:07 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

float to_radians(int degrees)
{
	return ((M_PI * degrees) / 180);
}

/// ///////////////************
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
	/// - calcular plano camera // 
	game->player->scr_dx = game->player->dy;
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

int  end_point(float distance, float start, float dir)
{
	int value;
	
	value = round(start * GRIDSIZE + (distance * dir * GRIDSIZE));
	return(value);
}