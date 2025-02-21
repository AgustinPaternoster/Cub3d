/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 03:52:26 by mgimon-c          #+#    #+#             */
/*   Updated: 2025/02/20 18:16:58 by apaterno         ###   ########.fr       */
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

int	cub_size(int fd)
{
	char	*line;
	int		i;

	i = 0;
	while ((line = read_line(fd)) != NULL)
		i++;
	return (i);
}

int	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '1' || line[i] == '0')
		return (1);
	return (0);
}

int	count_map_lines(int fd)
{
	int		n;
	char	*line;

	n = 0;
	while ((line = read_line(fd)) != NULL)
	{
		if (is_map_line(line))
			n++;
		free(line);
	}
	return (n);
}

int	get_mapsize(char *filename)
{
	int	fd;
	int	map_size;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	map_size = count_map_lines(fd);
	close(fd);
	return (map_size);
}

void	init_map_textures(t_game *game)
{
	game->map->no_texture = malloc(sizeof(t_imgdata));
	game->map->so_texture = malloc(sizeof(t_imgdata));
	game->map->ea_texture = malloc(sizeof(t_imgdata));
	game->map->we_texture = malloc(sizeof(t_imgdata));
}

int	store_map_line(t_game *game, char **result, int *k, char *line)
{
	result[*k] = ft_strdup(line);
	free(line);
	if (!result[*k])
	{
		while (--(*k) >= 0)
			free(result[*k]);
		free(result);
		close(game->map->fd);
		return (1);
	}
	(*k)++;
	return (0);
}

int	process_map_lines(t_game *game, char **result)
{
	int		k;
	char	*line;

	k = 0;
	while ((line = read_line(game->map->fd)) != NULL)
	{
		if (is_map_line(line))
		{
			if (store_map_line(game, result, &k, line))
				return (1);
		}
		else
			free(line);
	}
	result[k] = NULL;
	return (0);
}

int	get_map(t_game *game, char *filename)
{
	char	**result;
	int		map_size;

	map_size = get_mapsize(filename);
	game->map->cub = NULL;
	init_map_textures(game);
	game->map->fd = open(filename, O_RDONLY);
	if (game->map->fd < 0 || map_size <= 0)
	{
		printline_fd(2, "Error: open failed or invalid map size\n");
		return (1);
	}
	result = malloc(sizeof(char *) * (map_size + 1));
	if (!result)
	{
		close(game->map->fd);
		return (1);
	}
	if (process_map_lines(game, result))
		return (1);
	close(game->map->fd);
	game->map->matrix = result;
	return (0);
}
