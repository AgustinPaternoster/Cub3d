/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:44:10 by apaterno          #+#    #+#             */
/*   Updated: 2024/12/19 19:01:58 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void init_game(t_game *game)
{
	game->mlx_connection = mlx_init();
	game->mlx_window = mlx_new_window(game->mlx_connection, GRIDSIZE * game->map->sizex , GRIDSIZE * game->map->sizey, "cub3D");
	game->img->img = mlx_new_image(game->mlx_connection, GRIDSIZE * game->map->sizex, GRIDSIZE * game->map->sizey);
	game->img->addr = mlx_get_data_addr(game->img->img, &game->img->bits_per_pixel, &game->img->line_length, & game->img->endian);
}

static void	start_game(t_game *game)
{
	draw_map(game);
	draw_player(game);
	mlx_put_image_to_window(game->mlx_connection, game->mlx_window,game->img->img, 0, 0);
	mlx_key_hook(game->mlx_window,handle_key,game);
	mlx_loop(game->mlx_connection);
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_imgdata img;
	t_map	map;
	t_player player;
	
	char *mapa[6];
	mapa[0] = ft_strdup("1111111");
	mapa[1] = ft_strdup("1000001");
	mapa[2] = ft_strdup("1011001");
	mapa[3] = ft_strdup("1000001");
	mapa[4] = ft_strdup("1000001");
	mapa[5] = ft_strdup("1111111");
	(void)argc;
	(void)argv;
	game.img = &img;
	game.map = &map;
	game.player = &player;
	map.map = mapa;
	map.sizey =  6;
	map.sizex = 7;
	player.pos_x = 4;
	player.pos_y = 4;
	init_game(&game);
	start_game(&game);
	clean_close(&game, &img);
	for (int i = 0; i < 5; i++)
		free(map.map[i]);
	return (0);
}
