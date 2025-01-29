/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:41:53 by apaterno          #+#    #+#             */
/*   Updated: 2025/01/29 18:09:14 by apaterno         ###   ########.fr       */
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
	t_textures *txt;
	int i;
	int j;
	
	txt = map->texture;
	img.img = mlx_xpm_file_to_image(map->mlx_connection,path,&txt->heigh,&txt->width);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,&img.line_length, &img.endian);
	i = 0;
	while (i < txt->heigh)
	{
		j = 0 ;
		while (j = txt->width)
		{
			txt->texture[i][j] = get_color(&img, j, i);
			j++;
		}
		i++;
	}
	mlx_destroy_image(map->mlx_connection,img.img);
}