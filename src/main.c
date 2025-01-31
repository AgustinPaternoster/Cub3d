/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:44:10 by apaterno          #+#    #+#             */
/*   Updated: 2024/12/22 05:52:29 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/*static void	init_game(t_game *game)
{
	game->mlx_connection = mlx_init();
	game->mlx_window = mlx_new_window(game->mlx_connection, 500, 500, "cub3D");
	game->map = malloc(sizeof(t_tmap));
	if (!game->map)
		error_exit(MALLOC, 1, game);
	game->player = malloc(sizeof(t_player));
	if (!game->player)
		error_exit(MALLOC, 1, game);
}*/

static void init_game(t_game *game)
{
	game->mlx_connection = mlx_init();
	// linea para imprimir el mapa
	//game->mlx_window = mlx_new_window(game->mlx_connection, GRIDSIZE * game->map->sizex , GRIDSIZE * game->map->sizey, "cub3D");
	game->mlx_window = mlx_new_window(game->mlx_connection, SCREEN_WITH , SCREEN_HIGH, "cub3D");
	// linea para imprimir la imagen del mapa	
	// game->img->img = mlx_new_image(game->mlx_connection, GRIDSIZE * game->map->sizex, GRIDSIZE * game->map->sizey);
	game->img->img = mlx_new_image(game->mlx_connection, SCREEN_WITH, SCREEN_HIGH);
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
	game->player->pos_x = (float)posx + 0.5;
	game->player->pos_y = (float)posy + 0.5;
	game->player->direction = direction;
	calculate_delta(game);
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_imgdata img;
	//t_map	map;
	t_player player;
	t_ray	ray;


	if (argc != 2)
		return (printline_fd(2, "\nError: invalid arguments\n"),
			printline_fd(2, "You must provide a .cub map route as "),
			printline_fd(2, "only argument to the program\n\n"), 1);
	//init_game(&game);
	game.map = malloc(sizeof(t_map));
	game.player = malloc(sizeof(t_player));
	if (get_map(&game, argv[1]) == 1)
		return (1);
	if (check_map(game.map->matrix) == 0)
	{
		printline_fd(2, "\nThe map is valid\n\n");
		init_resources(&game, argv[1]);
		print_game_data(&game);
	}
	else
		printline_fd(2, "\nError: the map is invalid\n\n");
	game.img = &img;
	//game.map = &map;
	game.player = &player;
	game.ray = &ray;
	game.map->map = game.map->cub;
	game.map->sizey =  6;
	game.map->sizex = 7;
	player_pos(&game, 1 , 4, 130);
	init_game(&game);
	start_game(&game);
	clean_close(&game);
	return (0);
}
