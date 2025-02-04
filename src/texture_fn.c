/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_fn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:28:20 by apaterno          #+#    #+#             */
/*   Updated: 2025/02/04 16:39:04 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int get_color(t_imgdata *img, int x , int y)
{
	char *pixel;
	int  color;

	pixel = img->addr + y * img->line_length + x * (img->bits_per_pixel / 8);
	color = *(int*)pixel;
	return(color);
}
void xmp_to_int(t_text_info *text, char *path, t_game *game) 
{
	int i;
	int j;
	t_imgdata img;
	
	img.img = mlx_xpm_file_to_image(game->mlx_connection,path,&text->hight, &text->withd);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,&img.line_length, &img.endian);
	i = 0;
	while (i < text->hight)
	{
		j = 0 ;
		while (j < text->withd)
		{
			text->texture[i][j] = get_color(&img, i, j);
			j++;
		}
		i++;
	}
	mlx_destroy_image(game->mlx_connection,img.img);
}

void init_texture(char *path , t_game *game)
{
	t_text_info *texture;
	int i;
	
	texture = game->texture;
	texture->texture = ft_calloc(TEXTURE_SIZE, sizeof(int*));
	i = 0;
	while (i < TEXTURE_SIZE)
	{
		texture->texture[i] = ft_calloc(TEXTURE_SIZE, sizeof(int));
		i++;		
	}
	texture->hight = TEXTURE_SIZE;
	texture->withd = TEXTURE_SIZE;
	xmp_to_int(texture, path, game);	
}