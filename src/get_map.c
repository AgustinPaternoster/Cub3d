/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 03:52:26 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/12/22 05:54:06 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

char	*read_line(int fd)
{
	char	*line;
	int		i;
	int		bytes_read;

	line = malloc(256);
	if (!line)
		return (NULL);
	i = 0;
	while ((bytes_read = read(fd, &line[i], 1)) > 0)
	{
		if (line[i] == '\n')
			break ;
		i++;
	}
	if (bytes_read <= 0 && i == 0)
	{
		free(line);
		return (NULL);
	}
	line[i] = '\0';
	return (line);
}

int	get_mapsize(char *filename)
{
	int		fd;
	int		n;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	n = 0;
	while ((line = read_line(fd)) != NULL)
	{
		free(line);
		n++;
	}
	close(fd);
	if (n > 8)
		return (n - 8);
	return (0);
}

int	cub_size(int fd)
{
	char	*line;
	int		i;

	i = 0;
	while ((line = read_line(fd)) != NULL)
		i++;
	return (i);
}

int	get_map(t_game *game, char *filename)
{
	int			i;
	int			k;
	char		*line;
	char		**result;
	int			map_size;

	map_size = get_mapsize(filename);
	game->map->cub = NULL;
	game->map->no_texture = malloc(sizeof(t_img));
	game->map->so_texture = malloc(sizeof(t_img));
	game->map->ea_texture = malloc(sizeof(t_img));
	game->map->we_texture = malloc(sizeof(t_img));
	game->map->fd = open(filename, O_RDONLY);
	if (game->map->fd < 0 || map_size <= 0)
	{
		printline_fd(2, "Open failed or invalid map size\n");
		return (1);
	}
	result = malloc(sizeof(char *) * (map_size + 1));
	i = 0;
	k = 0;
	while ((line = read_line(game->map->fd)) != NULL)
	{
		if (i >= 8)
		{
			result[k] = ft_strdup(line);
			free(line);
			if (!result[k++])
			{
				while (--k >= 0)
					free(result[k]);
				free(result);
				close(game->map->fd);
				return (1);
			}
		}
		else
			free(line);
		i++;
	}
	result[k] = NULL;
	close(game->map->fd);
	game->map->matrix = result;
	return (0);
}
