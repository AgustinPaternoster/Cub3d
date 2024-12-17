/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:18:50 by apaterno          #+#    #+#             */
/*   Updated: 2024/12/17 16:24:43 by apaterno         ###   ########.fr       */
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






