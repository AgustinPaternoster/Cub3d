/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:44:10 by apaterno          #+#    #+#             */
/*   Updated: 2024/12/10 17:32:15 by apaterno         ###   ########.fr       */
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
	printmatrix_fd(2, tmap.matrix);
	start_game(&tmap);
	clean_close(tmap);
	return (0);
}
