/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:44:10 by apaterno          #+#    #+#             */
/*   Updated: 2024/12/13 20:55:18 by mgimon-c         ###   ########.fr       */
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

	(void)argc;
	(void)argv;
	init_game(&game);
	if (get_map(game.map, "maps/test_map.cub") == 1)
		return (1);
	if (check_map(game.map->matrix) == 0)
		printline_fd(2, "\nThe map is valid\n\n");
	else
		printline_fd(2, "\nError: the map is invalid\n\n");
	printmatrix_fd(2, game.map->matrix);
	clean_close(&game);
	return (0);
}
