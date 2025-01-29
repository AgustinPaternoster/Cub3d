/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:18:50 by apaterno          #+#    #+#             */
/*   Updated: 2025/01/28 19:39:55 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"


void paint_img(t_imgdata *img, int color , int width , int heigh)
{
	int x;
	int y;
	
	x = 0;
	
	while (x < width)
	{
		y = 0;
		while (y < heigh)
		{
			img_pixel_put(img, x, y , color);
			y++;
		}
		x++;
	}
}
void img_pixel_put(t_imgdata *img, int x, int y, int color)
{
	char *pixel;
	int  test_color;

	pixel = img->addr + y * img->line_length + x * (img->bits_per_pixel / 8);
	test_color = *(int*)pixel;
	*(int*)pixel = color;
}

void pixel_color(t_imgdata *img , int x , int y)
{
	char *pixel;
	int color;

	pixel = img->addr + y * img->line_length + x * (img->bits_per_pixel / 8);
	
}






