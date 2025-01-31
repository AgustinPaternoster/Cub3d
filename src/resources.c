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

void    get_cub(t_game *game, char *filename)
{
    game->map->fd = open(filename, O_RDONLY);

    char *line = NULL;
    size_t count = 0;
    size_t capacity = 10;
    game->map->cub = malloc(sizeof(char *) * capacity);
    while ((line = get_next_line(game->map->fd)))
    {
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
        game->map->cub[count++] = ft_strdup(line);
        free(line);
    }
    game->map->cub[count] = NULL;
    close(game->map->fd);
}

int get_hex_from_cubline(char *line)
{
    int colors[3] = {0, 0, 0};
    int i;
    int ci;
    
    i = 2;
    ci = 0;
    if ((line[0] != 'C' && line[0] != 'F') || line[1] != ' ')
        return (0xFFFFFF);
    while (line[i] && ci < 3)
    {
        if (!ft_isdigit(line[i]))
            return (0xFFFFFF);
        colors[ci] = 0;
        while (ft_isdigit(line[i]))
        {
            colors[ci] = colors[ci] * 10 + (line[i] - '0');
            i++;
        }
        if (colors[ci] < 0 || colors[ci] > 255)
            return (0xFFFFFF);
        if (ci < 2) {
            if (line[i] != ',')
                return (0xFFFFFF);
            i++;
        }
        ci++;
    }
    while (line[i] == '\n' || line[i] == '\r' || line[i] == ' ') 
        i++;
    if (line[i] != '\0')
        return (0xFFFFFF);
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

void	init_resources(t_game *game, char *filename)
{
    game->map->ceiling = 0xFFFFFF;
    game->map->floor = 0xFFFFFF;
    get_cub(game, filename);
    if (game->map->cub[5] != NULL)
        game->map->ceiling = get_hex_from_cubline(game->map->cub[5]);
    if (game->map->cub[6] != NULL)
        game->map->floor = get_hex_from_cubline(game->map->cub[6]);
    game->map->sizey = get_full_height(game->map->matrix);
    game->map->sizex = get_full_width(game->map->matrix);
    set_player_pos(game);
    get_texture("NO", game);
    get_texture("EA", game);
    get_texture("WE", game);
    get_texture("SO", game);
}