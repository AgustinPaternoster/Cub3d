/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:55:10 by apaterno          #+#    #+#             */
/*   Updated: 2025/01/14 21:59:17 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void img_pixel_put(t_imgdata *img, int x, int y, int color)
{
	char *pixel;

	pixel = img->addr + y * img->line_length + x * (img->bits_per_pixel / 8);
	*(int*)pixel = color;
}

void draw_player(t_game *game)
{
	int x;
	int y;
	int posx;
	int posy;
	
	posx = game->player->pos_x;
	posy = game->player->pos_y;
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

void paint_window(t_game *game, int color)
{
	int x;
	int y;
	int size_x;
	int size_y;	

	size_x = game->map->sizex * GRIDSIZE;
	size_y = game->map->sizey * GRIDSIZE;

	x = 0;
	while(x < size_x)
	{
		y = 0;
		while (y < size_y)
		{
			
			img_pixel_put(game->img, x, y, color);
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
	
	paint_window(game, 0);
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

void render_frame(t_game *game)
{
	//draw_map(game);
	//draw_player(game);
	paint_window(game, 0);
	draw_ray(game,game->player);
	mlx_put_image_to_window(game->mlx_connection, game->mlx_window,game->img->img,0,0);
}