/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 01:37:48 by mgimon            #+#    #+#             */
/*   Updated: 2025/03/03 18:40:42 by mgimon-c         ###   ########.fr       */
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
	if (matrix[i][j] == ' ' || matrix[i][j - 1] == ' ' || matrix[i][j
		+ 1] == ' ' || matrix[i - 1][j] == ' ' || matrix[i + 1][j] == ' '
		|| matrix[i - 1][j - 1] == ' ' || matrix[i - 1][j + 1] == ' '
		|| matrix[i + 1][j - 1] == ' ' || matrix[i + 1][j + 1] == ' ')
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

void	ft_bspace(void *s, size_t n)
{
	size_t			i;
	unsigned char	*byte_s;

	byte_s = (unsigned char *)s;
	i = 0;
	while (i < n && n != 0)
	{
		byte_s[i] = 32;
		i++;
	}
}

void	fix_line(char **matrix, int i, int max_len)
{
	char	*new_line;
	int		j;
	int		size;

	size = ft_strlen(matrix[i]);
	new_line = malloc(sizeof(char) * max_len + 1);
	ft_bspace(new_line, max_len);
	j = 0;
	while (j < size)
	{
		new_line[j] = matrix[i][j];
		j++;
	}
	free(matrix[i]);
	new_line[max_len] = '\0';
	matrix[i] = new_line;
}

int	length(char **matrix)
{
	int	i;
	int	row;
	int	max_value;

	i = 0;
	row = 0;
	while (matrix[row])
		row++;
	max_value = 0;
	while (i < row)
	{
		if ((int)ft_strlen(matrix[i]) > max_value)
			max_value = (int)ft_strlen(matrix[i]);
		i++;
	}
	return (max_value);
}
