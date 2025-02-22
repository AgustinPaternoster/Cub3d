/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resources.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 03:04:09 by mgimon-c          #+#    #+#             */
/*   Updated: 2025/02/22 21:57:04 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

char	*get_next_line(int fd)
{
	static char	buffer[1024];
	static int	buffer_read = 0;
	static int	buffer_pos = 0;
	char		*line;
	int			i;

	line = malloc(70000);
	if (fd < 0 || !line)
		return (NULL);
	i = 0;
	while (1)
	{
		if (buffer_pos >= buffer_read)
		{
			buffer_read = read(fd, buffer, 1024);
			buffer_pos = 0;
			if (buffer_read <= 0)
				break ;
		}
		if (buffer[buffer_pos] == '\n')
		{
			line[i++] = buffer[buffer_pos++];
			break ;
		}
		line[i++] = buffer[buffer_pos++];
	}
	line[i] = '\0';
	if (i == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

void	get_cub(t_game *game, char *filename)
{
	char	**new_cub;
	char	*line;
	size_t	count;
	size_t	capacity;

	count = 0;
	capacity = 10;
	game->map->fd = open(filename, O_RDONLY);
	if (game->map->fd < 0)
	{
		printf("Failed to open file\n");
		return ;
	}
	game->map->cub = malloc(sizeof(char *) * capacity);
	if (!game->map->cub)
		malloc_err();
	line = get_next_line(game->map->fd);
	while (line)
	{
		if (count >= capacity - 1)
		{
			capacity *= 2;
			new_cub = realloc(game->map->cub, sizeof(char *) * capacity);
			if (!new_cub)
				malloc_err();
			game->map->cub = new_cub;
		}
		game->map->cub[count++] = line;
		line = get_next_line(game->map->fd);
	}
	game->map->cub[count] = NULL;
	close(game->map->fd);
}

int	get_hex_from_cubline(char *line)
{
	int	i;
	int	ci;
	int	colors[3] = {0, 0, 0};

	i = 0;
	ci = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if ((line[i] != 'C' && line[i] != 'F') || line[i + 1] != ' ')
		return (-1);
	i += 2;
	while (line[i] && ci < 3)
	{
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (!ft_isdigit(line[i]))
			return (-1);
		colors[ci] = 0;
		while (ft_isdigit(line[i]))
		{
			colors[ci] = colors[ci] * 10 + (line[i] - '0');
			i++;
		}
		if (colors[ci] < 0 || colors[ci] > 255)
			return (-1);
		if (ci < 2)
		{
			while (line[i] == ' ' || line[i] == '\t')
				i++;
			if (line[i] != ',')
				return (-1);
			i++;
		}
		ci++;
	}
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'
		|| line[i] == '\r')
		i++;
	if (line[i] != '\0')
		return (-1);
	return ((colors[0] << 16) | (colors[1] << 8) | colors[2]);
}

int	get_full_width(char **matrix)
{
	int	i;
	int	j;
	int	width;

	i = 0;
	width = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
			j++;
		if (j > width)
			width = j;
		i++;
	}
	return (width);
}

void	init_resources(t_game *game, char *filename)
{
	int		i;
	char	*line;
	int		color;

	i = 0;
	game->map->ceiling = -1;
	game->map->floor = -1;
	get_cub(game, filename);
	if (!game->map->cub)
		exit(1);
	while (game->map->cub[i] != NULL)
	{
		line = game->map->cub[i];
		while (*line == ' ' || *line == '\t')
			line++;
		if (line[0] == 'C' || line[0] == 'F')
		{
			color = get_hex_from_cubline(line);
			if (color == -1)
			{
				printf("\nError parsing color on line: %s\n", line);
				exit(1);
			}
			if (line[0] == 'C')
				game->map->ceiling = color;
			else
				game->map->floor = color;
		}
		i++;
	}
	if (game->map->ceiling == -1 || game->map->floor == -1)
	{
		printf("\nError: One or more colors not found\n\n");
		exit(1);
	}
	game->map->textures = malloc(sizeof(t_texture));
	if (!game->map->textures)
		malloc_err();
	game->map->sizey = get_full_height(game->map->matrix);
	game->map->sizex = get_full_width(game->map->matrix);
	set_player_pos(game);
	get_texture("NO", game);
	get_texture("EA", game);
	get_texture("WE", game);
	get_texture("SO", game);
}
