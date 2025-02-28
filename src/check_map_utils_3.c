/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon <mgimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 01:37:48 by mgimon            #+#    #+#             */
/*   Updated: 2025/02/28 02:44:33 by mgimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// segfaults don't happen -
// this function is never called for first or last lines
// (previously checked for no '0's)

int	any_space_around(char **matrix, int i, int j)
{
	if (matrix[i][j] == ' ')
		return (1);
	if (matrix[i][j] == ' ' || matrix[i][j - 1] == ' ' || matrix[i][j + 1]
		== ' ' || matrix[i - 1][j] == ' ' || matrix[i + 1][j] == ' ' ||
		matrix[i - 1][j - 1] == ' ' || matrix[i - 1][j + 1] == ' ' ||
		matrix[i + 1][j - 1] == ' ' || matrix[i + 1][j + 1] == ' ')
		return (1);
	return (0);
}

int	check_corners(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->matrix[i])
	{
		j = 0;
		while (game->map->matrix[i][j])
		{
			if (game->map->matrix[i][j] == '0' || game->map->matrix[i][j] == 'N'
				|| game->map->matrix[i][j] == 'S'
				|| game->map->matrix[i][j] == 'E'
				|| game->map->matrix[i][j] == 'W')
			{
				if (any_space_around(game->map->matrix, i, j))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
