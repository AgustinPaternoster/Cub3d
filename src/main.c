/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:44:10 by apaterno          #+#    #+#             */
/*   Updated: 2025/01/28 14:14:45 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int handle_key(int keycode, t_tmap *map)
{
	(void)map;
	if (keycode == XK_c)
	{
		screen(map, 16716032 , 500 , 0 );
		mlx_put_image_to_window(map->mlx_connection, map->mlx_window,map->img->img,100,100);
	}
	if (keycode == XK_d)
	{
		screen(map, 2303 , 500 , 0 );
		mlx_put_image_to_window(map->mlx_connection, map->mlx_window,map->img->img,200,200);
	}
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
	map->mlx_window = mlx_new_window(map->mlx_connection, 1000 , 1000, "cub3D");
	map->img->img = mlx_xpm_file_to_image(map->mlx_connection,"./image.xpm",&h,&w);
	map->img->addr = mlx_get_data_addr(map->img->img, &map->img->bits_per_pixel, &map->img->line_length, &map->img->endian);
	// screen(map,2303,1000,0);
	mlx_put_image_to_window(map->mlx_connection, map->mlx_window,map->img->img, 0, 0);
	mlx_key_hook(map->mlx_window,handle_key,map);
	mlx_loop(map->mlx_connection);
}

int	main(int argc, char **argv)
{
	t_tmap	map;
	t_imgdata img_base;
	t_imgdata img_text;
	
	char *mapa[5];
	mapa[0] = ft_strdup("111111");
	mapa[1] = ft_strdup("100001");
	mapa[2] = ft_strdup("100001");
	mapa[3] = ft_strdup("100001");
	mapa[4] = ft_strdup("111111");
	(void)argc;
	(void)argv;
	map.img = &img;
	map.map = mapa;
	map.sizey =  5;
	map.sizex = 6;
	for (int i = 0; i < 5; i++)
		printf("%s\n", map.map[i]);
	start_game(&map);
	clean_close(&map, &img);
	for (int i = 0; i < 5; i++)
		free(map.map[i]);
	return (0);
}
