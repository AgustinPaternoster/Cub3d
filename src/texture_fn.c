/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_fn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:28:20 by apaterno          #+#    #+#             */
/*   Updated: 2025/02/12 12:47:49 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int **create_txt_array(int size)
{
	int i;
	int **arra_txt;

	i = 0;
	arra_txt = ft_calloc(size , sizeof(int*));
	if (!arra_txt)
		return (NULL);
	while (i < size)
	{
		arra_txt[i] = ft_calloc(size, sizeof(int));
	if (!arra_txt)
			return (NULL);
		i++;
	}
	return (arra_txt);
}


static int get_color(t_imgdata *img, int x , int y)
{
	char *pixel;
	int  color;

	pixel = img->addr + y * img->line_length + x * (img->bits_per_pixel / 8);
	color = *(int*)pixel;
	return(color);
}
// static void xmp_to_int(t_text_info *text, char *path, t_game *game) 
// {
// 	int i;
// 	int j;
// 	t_imgdata img;
	
// 	img.img = mlx_xpm_file_to_image(game->mlx_connection,path,&text->hight, &text->withd);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,&img.line_length, &img.endian);
// 	i = 0;
// 	while (i < text->hight)
// 	{
// 		j = 0 ;
// 		while (j < text->withd)
// 		{
// 			text->texture[i][j] = get_color(&img, i, j);
// 			j++;
// 		}
// 		i++;
// 	}
// mlx_destroy_image(game->mlx_connection,img.img);
// }

t_bool init_texture(t_game *game, int size)
{
	t_texture *txt;
	int i;
	
	txt = game->map->textures;
	txt->texture_NO = create_txt_array(size);
	if(!txt->texture_NO)
		return (FALSE);
	txt->texture_SO = create_txt_array(size);
	if(!txt->texture_SO)
		return (FALSE);
	txt->texture_EA = create_txt_array(size);
	if(!txt->texture_EA)
		return (FALSE);
	txt->texture_WE = create_txt_array(size);
	if(!txt->texture_WE)
		return (FALSE);
	txt->size = size;
}