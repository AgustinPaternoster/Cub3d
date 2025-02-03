/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:44:10 by apaterno          #+#    #+#             */
/*   Updated: 2025/02/03 19:07:56 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int handle_key(int keycode, t_tmap *map)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(map->mlx_connection, map->mlx_window);
		mlx_destroy_display(map->mlx_connection);
		free(map->mlx_connection);
		exit(1);
	}
	if (keycode == XK_x)
	{
	printf("int:%d\n", map->txt->texture[1][10]);
	printf("int:%d\n", map->txt->texture[100][103]);
	}	
	return (0);
}

void	clean_close(t_tmap *map, t_imgdata *img)
{
	(void)img;
	mlx_destroy_window(map->mlx_connection, map->mlx_window);
	mlx_destroy_display(map->mlx_connection);
	mlx_destroy_image(map->mlx_connection, img->img);
	free(map->mlx_connection);	
}


static void	start_game(t_tmap *map)
{

	// int h = 800;
	// int w = 800;

	map->mlx_connection = mlx_init();
	map->mlx_window = mlx_new_window(map->mlx_connection, WIDTH , HIGH, "cub3D");
	map->img_base->img = mlx_new_image(map->mlx_connection, WIDTH,HIGH);
	map->img_base->addr = mlx_get_data_addr(map->img_base->img, &map->img_base->bits_per_pixel, &map->img_base->line_length, &map->img_base->endian);
	paint_img(map->img_base, RED,WIDTH , HIGH);
	xmp_to_int(map, "./txt.xpm");
	int_to_img_rescaled(map, 500);
	//int_to_img(map);
	mlx_put_image_to_window(map->mlx_connection, map->mlx_window,map->img_base->img, 0, 0);
	mlx_key_hook(map->mlx_window,handle_key,map);
	mlx_loop(map->mlx_connection);
}

int	main(int argc, char **argv)
{
	t_tmap	map;
	t_imgdata img_base;
	t_texture txt;
	
	(void)argc;
	(void)argv;
	txt.texture = create_txt_array(TXT_W, TXT_W);
	txt.heigh = TXT_W;
	txt.width = TXT_W;
	map.txt = &txt;  
	map.img_base = &img_base;
	start_game(&map);
	// clean_close(&map, &img_base);
	
	for (int i = 0; i < 5; i++)
		free(map.map[i]);
	return (0);
}
