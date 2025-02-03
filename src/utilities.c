/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:41:53 by apaterno          #+#    #+#             */
/*   Updated: 2025/02/03 19:05:35 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int **create_txt_array(int with , int heigh)
{
	int i;
	int **arra_txt;

	arra_txt = ft_calloc(heigh , sizeof(int*));
	i = 0;
	while (i < heigh)
	{
		arra_txt[i] = ft_calloc(with, sizeof(int));
		i++;
	}
	return (arra_txt);
}

void clean_txt(int **txt, int heigh , int width)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while(i < heigh)
	{
		free(txt[i]);
		i++;
	}
	free(txt);
}

int get_color(t_imgdata *img, int x , int y)
{
	char *pixel;
	int  color;

	pixel = img->addr + y * img->line_length + x * (img->bits_per_pixel / 8);
	color = *(int*)pixel;
	return(color);
}

void xmp_to_int(t_tmap *map, char *path) 
{
	t_imgdata img;
	t_texture *txt;
	int i;
	int j;
	
	txt = map->txt;
	img.img = mlx_xpm_file_to_image(map->mlx_connection,path,&txt->heigh,&txt->width);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,&img.line_length, &img.endian);
	i = 0;
	while (i < txt->heigh)
	{
		j = 0 ;
		while (j < txt->width)
		{
			txt->texture[i][j] = get_color(&img, i, j);
			j++;
		}
		i++;
	}
	mlx_destroy_image(map->mlx_connection,img.img);
}

void int_to_img(t_tmap *map)
{
	t_texture *txt;
	t_imgdata *img;
	int i;
	int j;
	
	txt = map->txt;
	img = map->img_base;
	i = 0;
	while (i < txt->heigh)
	{
		j = 0;
		while (j < txt->width)
		{
			img_pixel_put(img, i, j, txt->texture[i][j]);
			j++;
		}
		i++;
	}
}
void int_to_img_rescaled(t_tmap *map, int distance)
{
	t_texture *txt;
	t_imgdata *img;
	float index;
	int new_h;
	int new_w;
	int new_i;
	int new_j;
	int i;
	int j;
	
	
	img = map->img_base;
	txt = map->txt;
	index = (float)distance / (float)txt->width;
	new_h = distance;
	new_w = distance;
	i = 0;
	while (i < new_h)
	{
		j = 0;
		new_i = round(i / index);
		if (new_i >= txt->heigh)
				new_i = txt->heigh - 1;
		while (j < new_w)
		{
			new_j = round(j / index);
			if (new_j >= txt->width)
				new_j = txt->width - 1;
			img_pixel_put(img, i, j, txt->texture[new_i][new_j]);
			j++;
		}
		i++;
	}
}