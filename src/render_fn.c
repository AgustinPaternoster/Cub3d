/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:55:10 by apaterno          #+#    #+#             */
/*   Updated: 2025/01/21 16:58:30 by apaterno         ###   ########.fr       */
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

void print_point(t_ray *ray, t_imgdata *img)
{
	int x;
	int y;

	x = round(end_point(ray->distance, ray->camera_pos[0], ray->delta[0]));
	y = round(end_point(ray->distance, ray->camera_pos[1], ray->delta[1]));
	img_pixel_put(img, x , y , GREEN);
	
}

void draw_column(t_ray *ray, t_imgdata *img, int count)
{
    int x;
    int height;
    int y_start;
    int y_end;

    x = count;
    height = (int)(SCREEN_HIGH / ray->distance);
    if (height <= 0)
        height = 1;
    y_start = (SCREEN_HIGH - height) / 2;
    y_end = y_start + height;
    if (y_start < 0)
        y_start = 0;
    if (y_end > SCREEN_HIGH)
        y_end = SCREEN_HIGH;
    while (y_start < y_end)
    {
        if (x >= 0 && x < SCREEN_WITH && y_start >= 0 && y_start < SCREEN_HIGH) {
            img_pixel_put(img, x, y_start, WHITE);
        }
        y_start++;
    }
}

void render_frame(t_game *game)
{
	//draw_map(game);
	//draw_player(game);
	paint_window(game, 0);
	draw_rays(game);
	mlx_put_image_to_window(game->mlx_connection, game->mlx_window,game->img->img,0,0);
}