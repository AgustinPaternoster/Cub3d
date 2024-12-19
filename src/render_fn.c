/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:55:10 by apaterno          #+#    #+#             */
/*   Updated: 2024/12/19 19:00:05 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void draw_player(t_game *game)
{
	int x;
	int y;
	int posx;
	int posy;
	
	posx = (game->player->pos_x * GRIDSIZE) + (GRIDSIZE / 2) - PLAYERSIZE / 2;
	posy = (game->player->pos_y * GRIDSIZE) + (GRIDSIZE / 2) - PLAYERSIZE / 2;
	x = 0;
	while (x < PLAYERSIZE)
	{
		y = 0;
		while (y < PLAYERSIZE)
		{
			img_pixel_put(game->img,posx + x ,posy + y,GREEN);
			//mlx_pixel_put(game->mlx_connection, game->mlx_window, posx + x , posy + y , GREEN);
			y++;
		}
		x++;
	}	
}

void draw_map(t_game *game)
{
	int x;
	int y;
	int offset;

	y = 0;
	offset = 0;
	while (y < game->map->sizey)
	{
		x = 0;
		while(game->map->map[y][x])
		{
			if (game->map->map[y][x] == '1')
			{
				draw_pixels(game, RED, GRIDSIZE, GRIDSIZE * x, GRIDSIZE * y);
				x++;
			}
			else
			{
				draw_pixels(game, BLUE, GRIDSIZE, GRIDSIZE * x, GRIDSIZE * y);
				x++;
			}
		}
		y++;
	}
}