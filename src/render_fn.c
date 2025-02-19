/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:55:10 by apaterno          #+#    #+#             */
/*   Updated: 2025/02/19 22:38:17 by mgimon-c         ###   ########.fr       */
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

void paint_window(t_game *game, int color)
{
	int x;
	int y;
	int size_x;
	int size_y;	

	size_x = SCREEN_WITH;
	size_y = SCREEN_WITH;

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
	//int offset;

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
	paint_window(game, GREY);
	draw_rays(game);
	mlx_put_image_to_window(game->mlx_connection, game->mlx_window,game->img->img,0,0);
}



void draw_walls(t_game *game, int column)
{
	int heigh;
	int start_y;
	int end;
	t_ray *ray;
	int **texture;
	double step;
	double textPos;
	int texure_y;
	int texture_x;
	int n;

	ray = game->ray;
	texture_x = ray->texture_pixel;
	texture = select_tetxture(game, ray);
	heigh = ((SCREEN_HIGH / ray->distance) * 0.5);
	start_y = (SCREEN_HIGH / 2) - (heigh / 2);
	end = start_y + heigh;
	step = 1.0 * TEXTURE_SIZE / heigh;
	if (start_y < 0)
	start_y = 0;
	if (end > SCREEN_HIGH)
	end = SCREEN_HIGH - 1;
	textPos = (start_y - SCREEN_HIGH / 2 + heigh / 2) * step;

	//cielo
	n = 0;
	while (n < start_y)
	{
		img_pixel_put(game->img, column, n, game->map->ceiling);
		n++;
	}

	while (start_y < end)
	{
		texure_y = (int)textPos;
		textPos += step;	
		img_pixel_put(game->img,column, start_y,texture[texure_y][texture_x]);
		start_y++;
	}
	
	//floor
	while (start_y < SCREEN_HIGH)
	{
		img_pixel_put(game->img, column, start_y, game->map->floor);
		start_y++;
	}
}
