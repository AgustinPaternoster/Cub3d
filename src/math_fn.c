/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_fn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:25:55 by apaterno          #+#    #+#             */
/*   Updated: 2025/02/21 12:02:04 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"


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
	game->player->scr_dx = game->player->dy;
	game->player->scr_dy = game->player->dx * - 1;
}

int  end_point(float distance, float start, float dir)
{
	int value;
	
	value = round(start * GRIDSIZE + (distance * dir * GRIDSIZE));
	return(value);
}