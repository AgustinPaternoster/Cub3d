/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:18:50 by apaterno          #+#    #+#             */
/*   Updated: 2024/12/19 16:57:13 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void img_pixel_put(t_imgdata *img, int x, int y, int color)
{
	char *pixel;

	pixel = img->addr + y * img->line_length + x * (img->bits_per_pixel / 8);
	*(int*)pixel = color;
}

void screen(t_game *game, int color, int size, int offset )
{
	int x;
	int y;

	x = offset;
	y = offset;
	size += offset;
	while (x < size)
	{
		y = offset;
		while (y < size)
		{
			img_pixel_put(game->img, x, y , color);
			y++;
		}
		x++;
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
			//mlx_pixel_put(game->mlx_connection,game->mlx_window,x,y,color);
			y++;
		}
		x++;
	}		
}
void	clean_close(t_game *game, t_imgdata *img)
{
	
	mlx_destroy_window(game->mlx_connection, game->mlx_window);
	mlx_destroy_display(game->mlx_connection);
	mlx_destroy_image(game->mlx_connection, img->img);
	free(game->mlx_connection);
	
}






