/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:18:50 by apaterno          #+#    #+#             */
/*   Updated: 2024/12/18 16:22:46 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void img_pixel_put(t_imgdata *img, int x, int y, int color)
{
	char *pixel;

	pixel = img->addr + y * img->line_length + x * (img->bits_per_pixel / 8);
	*(int*)pixel = color;
}

void screen(t_tmap *map, int color, int size, int offset )
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
			img_pixel_put(map->img, x, y , color);
			y++;
		}
		x++;
	}
}

void draw_pixels(t_tmap *map, int color, int size, int offset_x, int offset_y)
{
	int x;
	int y;

	
	x = offset_x + 1;
	while(x < size + offset_x - 1)
	{
		y = offset_y + 1;
		while(y < size + offset_y - 1)
		{
			mlx_pixel_put(map->mlx_connection,map->mlx_window,x,y,color);
			y++;
		}
		x++;
	}		
}
void	clean_close(t_tmap *map, t_imgdata *img)
{
	(void)img;
	mlx_destroy_window(map->mlx_connection, map->mlx_window);
	mlx_destroy_display(map->mlx_connection);
	//mlx_destroy_image(map->mlx_connection, img->img);
	free(map->mlx_connection);
	
}






