/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 05:00:30 by mgimon-c          #+#    #+#             */
/*   Updated: 2025/03/03 14:42:57 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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

void fix_line(char **matrix , int i , int max_len)
{
	char *new_line;
	int j;
	int size;
	
	size = ft_strlen(matrix[i]);
	new_line = malloc(sizeof(char) * max_len + 1);
	ft_bspace(new_line, max_len);
	j = 0;
	while(j < size)
	{
		new_line[j] = matrix[i][j];
		j++;
	}
	free(matrix[i]);
	new_line[max_len] = '\0';
	matrix[i] = new_line;
}

int length(char **matrix)
{
	int i;
	int row;
	int max_value;
	
	i = 0;
	row = 0;
	while(matrix[row])
		row++;
	max_value = 0;
	while(i < row)
	{
		if ((int)ft_strlen(matrix[i]) > max_value)
			max_value = (int)ft_strlen(matrix[i]);
		i++;
	}
	return (max_value);
}



int	even_map(char **matrix)
{
	int	i;
	//int	j;
	//int	k;
	int max_length;
	
	max_length = length(matrix);
	i = 0;
	//k = ft_strlen(matrix[i]);
	while (matrix[i])
	{
		if ((int)ft_strlen(matrix[i]) < max_length)
			fix_line(matrix,i,max_length);
		i++;
	}
	(void)max_length;
	return (1);
}

int	validate_holes(char **matrix)
{
	int	i;
	int	j;

	i = 0;
	while (matrix[i] != NULL)
	{
		j = 0;
		while (matrix[i][j] != '\0')
		{
			if (matrix[i][j] == '0')
			{
				if (matrix[i + 1] != NULL && matrix[i + 1][j] == ' ')
					return (0);
				if (i > 0 && matrix[i - 1][j] == ' ')
					return (0);
				if (j > 0 && matrix[i][j - 1] == ' ')
					return (0);
				if (matrix[i][j + 1] == ' ')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	validate_chars(char **matrix)
{
	int	i;
	int	j;

	i = 0;
	if (!matrix)
		return (1);
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] != '1' && matrix[i][j] != '0'
				&& matrix[i][j] != ' ' && matrix[i][j] != 'W'
				&& matrix[i][j] != 'E' && matrix[i][j] != 'S'
				&& matrix[i][j] != 'N')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_line_empty(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (1);
	if (line[i] == '\0')
		return (1);
	if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
		return (0);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '\0')
		return (1);
	return (0);
}

int	map_full_to_bottom(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		if (is_line_empty(matrix[i]))
			return (0);
		i++;
	}
	return (1);
}
