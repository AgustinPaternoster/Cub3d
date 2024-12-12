/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 04:56:51 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/12/12 17:06:01 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	clean_close(t_game *game)
{
	int	i;

	i = 0;
	while (game->map->matrix[i])
	{
		free(game->map->matrix[i]);
		i++;
	}
	free(game->map->matrix);
	free(game->map);
	free(game->player);
	mlx_destroy_window(game->mlx_connection, game->mlx_window);
	mlx_destroy_display(game->mlx_connection);
	free (game->mlx_connection);
}

void	error_exit(char *msg, int exit_code, t_game *game)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	if (game->map != NULL)
		free(game->map);
	if (game->player != NULL)
		free(game->player);
	mlx_destroy_window(game->mlx_connection, game->mlx_window);
	mlx_destroy_display(game->mlx_connection);
	free (game->mlx_connection);
	exit(exit_code);
}
