/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:44:10 by apaterno          #+#    #+#             */
/*   Updated: 2025/01/14 20:33:43 by mgimon-c         ###   ########.fr       */
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
	render_frame(game);
	mlx_hook(game->mlx_window, 17, 0, handle_close, game);
	mlx_hook(game->mlx_window, 2, 1L<<0, handle_key,game);
	mlx_loop(game->mlx_connection);
}

void player_pos(t_game *game, int posx, int posy, int direction)
{
	game->player->pos_x = (posx * GRIDSIZE) + (GRIDSIZE / 2);
	game->player->pos_y = (posy * GRIDSIZE) + (GRIDSIZE / 2);
	game->player->accum_x = (float)game->player->pos_x;
	game->player->accum_y= (float)game->player->pos_y;
	game->player->direction = direction;
	calculate_delta(game);
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_imgdata img;
	t_map	map;
	t_player player;
	
	char *mapa[6];
	mapa[0] = ft_strdup("1111111");
	mapa[1] = ft_strdup("1N00001");
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
	player_pos(&game, 1 , 1, 45);
	init_game(&game);
	start_game(&game);
	clean_close(&game, &img);
	for (int i = 0; i < 6; i++)
		free(map.map[i]);
	return (0);
}

/*

int	main(int argc, char **argv)
{
	t_game	game;
	t_imgdata img;
	t_map	map;
	t_player player;
	
	char *mapa[13];
	 mapa[0] = ft_strdup("11111111111111111");
	 mapa[1] = ft_strdup("1N000000000000001");
	 mapa[2] = ft_strdup("10111000001000101");
	 mapa[3] = ft_strdup("10101000001000101");
	 mapa[4] = ft_strdup("10101000001000101");
	 mapa[5] = ft_strdup("10101000001000101");
	 mapa[6] = ft_strdup("10101000001000101");
	 mapa[7] = ft_strdup("10101000001000101");
	 mapa[8] = ft_strdup("10101111111000101");
	 mapa[9] = ft_strdup("10100000000000101");
	mapa[10] = ft_strdup("10111111111111101");
	mapa[11] = ft_strdup("10000000000000001");
	mapa[12] = ft_strdup("11111111111111111");
	(void)argc;
	(void)argv;
	game.img = &img;
	game.map = &map;
	game.player = &player;
	map.map = mapa;
	map.sizey =  13;
	map.sizex = 20;
	player_pos(&game, 1 , 1, 45);
	init_game(&game);
	start_game(&game);
	clean_close(&game, &img);
	for (int i = 0; i < 13; i++)
		free(map.map[i]);
	return (0);
}
*/