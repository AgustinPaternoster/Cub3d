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

static void	init_game(t_game *game)
{
	game->mlx_connection = mlx_init();
	game->mlx_window = mlx_new_window(game->mlx_connection, 500, 500, "cub3D");
	game->map = malloc(sizeof(t_tmap));
	if (!game->map)
		error_exit(MALLOC, 1, game);
	game->player = malloc(sizeof(t_player));
	if (!game->player)
		error_exit(MALLOC, 1, game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (printline_fd(2, "\nError: invalid arguments\n"),
			printline_fd(2, "You must provide a .cub map route as "),
			printline_fd(2, "only argument to the program\n\n"), 1);
	init_game(&game);
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
	clean_close(&game);
	return (0);
}
