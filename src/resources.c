/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resources.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 03:04:09 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/12/22 05:16:05 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

char	*get_next_line(int fd)
{
	static char	buffer[1024];
	static int	buffer_read;
	static int	buffer_pos;
	char		*line;
	int			i;

	if (fd < 0 || (line = malloc(70000)) == NULL)
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

void get_cub(t_game *game, char *filename) {
    game->map->fd = open(filename, O_RDONLY);
    if (game->map->fd < 0) {
        perror("Failed to open file");
        return;
    }

    char *line = NULL;
    size_t count = 0;
    size_t capacity = 10;
    game->map->cub = malloc(sizeof(char *) * capacity);
    if (!game->map->cub) {
        perror("Memory allocation failed");
        close(game->map->fd);
        return;
    }

    while ((line = get_next_line(game->map->fd))) {
        if (count >= capacity) {
            capacity *= 2;
            char **new_cub = realloc(game->map->cub, sizeof(char *) * capacity);
            if (!new_cub) {
                perror("Memory allocation failed");
                free(line);
                close(game->map->fd);
                return;
            }
            game->map->cub = new_cub;
        }
        game->map->cub[count++] = line;
    }
    game->map->cub[count] = NULL;
    close(game->map->fd);
}

int get_hex_from_cubline(char *line)
{
    int colors[3] = {0, 0, 0};
    int i = 0;
    int ci = 0;

    while (line[i] == ' ' || line[i] == '\t')
        i++;
    if ((line[i] != 'C' && line[i] != 'F') || line[i + 1] != ' ')
        return 0xFFFFFF;
    i += 2;
    while (line[i] && ci < 3)
    {
        while (line[i] == ' ' || line[i] == '\t')
            i++;
        if (!isdigit(line[i]))
            return 0xFFFFFF;
        colors[ci] = 0;
        while (isdigit(line[i]))
        {
            colors[ci] = colors[ci] * 10 + (line[i] - '0');
            i++;
        }
        if (colors[ci] < 0 || colors[ci] > 255)
            return 0xFFFFFF;
        if (ci < 2)
        {
            while (line[i] == ' ' || line[i] == '\t')
                i++;
            if (line[i] != ',')
                return 0xFFFFFF;
            i++;
        }
        ci++;
    }
    while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n' || line[i] == '\r')
        i++;
    if (line[i] != '\0')
        return 0xFFFFFF;
    return (colors[0] << 16) | (colors[1] << 8) | colors[2];
}

int get_full_width(char **matrix)
{
    int i;
    int j;
    int width;

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

void init_resources(t_game *game, char *filename)
{
    game->map->ceiling = 0xFFFFFF;
    game->map->floor = 0xFFFFFF;
    get_cub(game, filename);
    for (int i = 0; game->map->cub[i] != NULL; i++)
    {
        if (game->map->cub[i][0] == 'C' || game->map->cub[i][0] == 'F')
        {
            int color = get_hex_from_cubline(game->map->cub[i]);
            if (game->map->cub[i][0] == 'C')
                game->map->ceiling = color;
            else
                game->map->floor = color;
        }
    }
    game->map->sizey = get_full_height(game->map->matrix);
    game->map->sizex = get_full_width(game->map->matrix);
    set_player_pos(game);
    get_texture("NO", game);
    get_texture("EA", game);
    get_texture("WE", game);
    get_texture("SO", game);
}