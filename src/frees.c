/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 04:56:51 by mgimon-c          #+#    #+#             */
/*   Updated: 2025/01/02 03:46:08 by mgimon-c         ###   ########.fr       */
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
	i = 0;
	if (game->map->cub)
	{
		while (game->map->cub[i])
		{
			free(game->map->cub[i]);
			i++;
		}
	}
	mlx_destroy_image(game->mlx_connection, game->map->no_texture->img_ptr);
	mlx_destroy_image(game->mlx_connection, game->map->so_texture->img_ptr);
	mlx_destroy_image(game->mlx_connection, game->map->we_texture->img_ptr);
	mlx_destroy_image(game->mlx_connection, game->map->ea_texture->img_ptr);
	free(game->map->cub);
	free(game->map->no_texture);
	free(game->map->ea_texture);
	free(game->map->we_texture);
	free(game->map->so_texture);
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
