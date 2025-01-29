/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:44:10 by apaterno          #+#    #+#             */
/*   Updated: 2025/01/28 19:43:22 by apaterno         ###   ########.fr       */
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

	int h = 700;
	int w = 525;

	map->mlx_connection = mlx_init();
	map->mlx_window = mlx_new_window(map->mlx_connection, WIDTH , HIGH, "cub3D");
	//imagen xmp
	map->img_tex->img = mlx_xpm_file_to_image(map->mlx_connection,"./image.xpm",&h,&w);
	map->img_tex->addr = mlx_get_data_addr(map->img_tex->img, &map->img_tex->bits_per_pixel, &map->img_tex->line_length, &map->img_tex->endian);
	//imagen color listo
	map->img_base->img = mlx_new_image(map->mlx_connection, WIDTH,HIGH);
	map->img_base->addr = mlx_get_data_addr(map->img_base->img, &map->img_base->bits_per_pixel, &map->img_base->line_length, &map->img_base->endian);
	paint_img(map->img_tex, RED, 100, 100);
	
	//mlx_put_image_to_window(map->mlx_connection, map->mlx_window,map->img_base->img, 0, 0);
	//mlx_put_image_to_window(map->mlx_connection, map->mlx_window, map->img_tex->img, 100, 100);
	//pixel_color(map->img_tex->img, 40, 40);
	mlx_key_hook(map->mlx_window,handle_key,map);
	mlx_loop(map->mlx_connection);
}

int	main(int argc, char **argv)
{
	t_tmap	map;
	t_imgdata img_base;
	t_imgdata img_text;
	
	(void)argc;
	(void)argv;
	map.img_base = &img_base;
	map.img_tex = &img_text;
	start_game(&map);
	clean_close(&map, &img_base);
	for (int i = 0; i < 5; i++)
		free(map.map[i]);
	return (0);
}
