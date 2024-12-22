/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resources_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 03:36:00 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/12/22 06:25:13 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void    set_player_pos(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (game->map->matrix[i])
    {
        j = 0;
        while (game->map->matrix[i][j])
        {
            if (game->map->matrix[i][j] == 'N' || game->map->matrix[i][j] == 'S'
                || game->map->matrix[i][j] == 'E' || game->map->matrix[i][j] == 'W')
            {
                game->player->x_pos = j;
                game->player->y_pos = i;
                return ;
            }
            j++;
        }
        i++;
    }
}

void    get_texture(char *prefix, t_game *game)
{
    void    *img_ptr;
    char    *texture_path;
    int     width;
    int     height;

    if (ft_strcmp(prefix, "NO") == 0)
    {
        texture_path = game->map->cub[0] + 3;
        img_ptr = mlx_xpm_file_to_image(game->mlx_connection, texture_path, &width, &height);
        if (!img_ptr)
        {
            printline_fd(2, "Error: mlx couldn't get the texture\n\n");
            return ;
        }
        game->map->no_texture->img_ptr = img_ptr;
        game->map->no_texture->width = width;
        game->map->no_texture->height = height;
    }
    else if (ft_strcmp(prefix, "SO") == 0)
    {
        texture_path = game->map->cub[1] + 3;
        img_ptr = mlx_xpm_file_to_image(game->mlx_connection, texture_path, &width, &height);
        if (!img_ptr)
        {
            printline_fd(2, "Error: mlx couldn't get the texture\n\n");
            return ;
        }
        game->map->so_texture->img_ptr = img_ptr;
        game->map->so_texture->width = width;
        game->map->so_texture->height = height;
    }
    else if (ft_strcmp(prefix, "WE") == 0)
    {
        texture_path = game->map->cub[2] + 3;
        img_ptr = mlx_xpm_file_to_image(game->mlx_connection, texture_path, &width, &height);
        if (!img_ptr)
        {
            printline_fd(2, "Error: mlx couldn't get the texture\n\n");
            return ;
        }
        game->map->we_texture->img_ptr = img_ptr;
        game->map->we_texture->width = width;
        game->map->we_texture->height = height;
    }
    else if (ft_strcmp(prefix, "EA") == 0)
    {
        texture_path = game->map->cub[3] + 3;
        img_ptr = mlx_xpm_file_to_image(game->mlx_connection, texture_path, &width, &height);
        if (!img_ptr)
        {
            printline_fd(2, "Error: mlx couldn't get the texture\n\n");
            return ;
        }
        game->map->ea_texture->img_ptr = img_ptr;
        game->map->ea_texture->width = width;
        game->map->ea_texture->height = height;
    }
}