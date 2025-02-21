/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:13:35 by apaterno          #+#    #+#             */
/*   Updated: 2025/02/21 12:24:10 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void draw_player(t_game *game)
{
	int x;
	int y;
	int posx;
	int posy;
	
	posx = round(game->player->pos_x * GRIDSIZE);
	posy = round(game->player->pos_y * GRIDSIZE);
	x = posx - PLAYERSIZE;
	while (x <= posx + PLAYERSIZE)
	{
		y = posy - PLAYERSIZE;
		while (y <= posy + PLAYERSIZE)
		{
			img_pixel_put(game->img, x ,y,GREEN);
			y++;
		}
		x++;
	}
}

void draw_map(t_game *game)
{
	int x;
	int y;
	//int offset;

	y = 0;
	
	paint_window(game, 0);
	while (y < game->map->sizey)
	{
		x = 0;
		while(game->map->matrix[y][x])
		{
			if (game->map->matrix[y][x] == '1')
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

void draw_pixels(t_game *game, int color, int size, int offset_x, int offset_y)
{
	int x;
	int y;

	x = offset_x + 1;
	while(x < size + offset_x - 1)
	{
		y = offset_y + 1;
		while(y < size + offset_y - 1)
		{
			img_pixel_put(game->img, x, y, color);
			y++;
		}
		x++;
	}		
}