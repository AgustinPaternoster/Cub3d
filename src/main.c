/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:44:10 by apaterno          #+#    #+#             */
/*   Updated: 2024/12/11 05:08:41 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	start_game(t_tmap *map)
{
	map->mlx_connection = mlx_init();
	map->mlx_window = mlx_new_window(map->mlx_connection, 500 , 500, "cub3D");
	mlx_loop(map->mlx_connection);
}

int	main(int argc, char **argv)
{
	t_tmap	tmap;

	(void)argc;
	(void)argv;
	get_map(&tmap, "maps/test_map.cub");
	if (check_map(tmap.matrix) == 0)
		printline_fd(2, "The map is valid\n");
	else
		printline_fd(2, "The map is invalid\n");
	printmatrix_fd(2, tmap.matrix);
	start_game(&tmap);
	clean_close(tmap);
	return (0);
}
