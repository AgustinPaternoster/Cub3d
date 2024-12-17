/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:44:10 by apaterno          #+#    #+#             */
/*   Updated: 2024/12/17 19:26:25 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int handle_key(int keycode, t_tmap *map)
{
	(void)map;
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(map->mlx_connection, map->mlx_window);
		mlx_destroy_display(map->mlx_connection);
		free(map->mlx_connection);
		exit(1);
	}	
	return (0);
}

void draw_map(t_tmap *map)
{
	int x;
	int y;
	int offset;

	y = 0;
	offset = 0;
	while (y < map->sizey)
	{
		x = 0;
		while(map->map[y][x])
		{
			if (map->map[y][x] == '1')
			{
				draw_pixels(map, RED, GRIDSIZE, GRIDSIZE * x, GRIDSIZE * y);
				x++;
			}
			else
			{
				draw_pixels(map, BLUE, GRIDSIZE, GRIDSIZE * x, GRIDSIZE * y);
				x++;
			}
		}
		y++;
	}
	
	
}


static void	start_game(t_tmap *map)
{
	
	map->mlx_connection = mlx_init();
	map->mlx_window = mlx_new_window(map->mlx_connection, GRIDSIZE * map->sizex , GRIDSIZE * map->sizey, "cub3D");
	draw_map(map);
	//map->img->img = mlx_new_image(map->mlx_connection, GRIDSIZE * map->sizex, GRIDSIZE * map->sizey);
	//mlx_pixel_put(map->mlx_connection,map->mlx_window,)
	//map->img->addr = mlx_get_data_addr(map->img->img, &map->img->bits_per_pixel, &map->img->line_length, &map->img->endian);
	// screen(map,2303,1000,0);
	//mlx_put_image_to_window(map->mlx_connection, map->mlx_window,map->img->img, 0, 0);
	mlx_key_hook(map->mlx_window,handle_key,map);
	mlx_loop(map->mlx_connection);
}

int	main(int argc, char **argv)
{
	t_tmap	map;
	t_imgdata img;
	
	char *mapa[5];
	mapa[0] = ft_strdup("111111");
	mapa[1] = ft_strdup("100001");
	mapa[2] = ft_strdup("100001");
	mapa[3] = ft_strdup("100001");
	mapa[4] = ft_strdup("111111");
	(void)argc;
	(void)argv;
	//map.img = &img;
	map.map = mapa;
	map.sizey =  5;
	map.sizex = 6;
	start_game(&map);
	clean_close(&map, &img);
	for (int i = 0; i < 5; i++)
		free(map.map[i]);
	return (0);
}
