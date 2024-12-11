/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:44:10 by apaterno          #+#    #+#             */
/*   Updated: 2024/12/11 19:01:37 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int exit_win(int keycode, t_tmap *map)
{
	printf("key :%d\n", keycode);
	mlx_destroy_window(map->mlx_connection, map->mlx_window);
	mlx_destroy_display(map->mlx_connection);
	return (0);
}

void	clean_close(t_tmap *map, t_imgdata *img)
{
	mlx_destroy_window(map->mlx_connection, map->mlx_window);
}
static void	start_game(t_tmap *map, t_imgdata *img)
{
	map->mlx_connection = mlx_init();
	map->mlx_window = mlx_new_window(map->mlx_connection, 1000 , 1000, "cub3D");
	img->img = mlx_new_image(map->mlx_connection,1000, 1000);
	
	mlx_key_hook(map->mlx_window,exit_win,map);
	mlx_loop(map->mlx_connection);
}

int	main(int argc, char **argv)
{
	t_tmap	tmap;
	t_imgdata img;

	(void)argc;
	(void)argv;
	start_game(&tmap, &img);
	clean_close(&tmap, &img);
	return (0);
}
