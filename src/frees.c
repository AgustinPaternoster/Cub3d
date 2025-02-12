/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 04:56:51 by mgimon-c          #+#    #+#             */
/*   Updated: 2025/02/12 12:45:24 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void free_texture(int  **text, int size)
{
	int i;

	i = 0;
	while(i < size)
	{
		free(text[i]);
		i++; 
	}
	free(text);
}

void	clean_close(t_game *game, t_imgdata *img)
{	
	free_texture(game->map->textures->texture_NO, TEXTURE_SIZE);
	free_texture(game->map->textures->texture_SO, TEXTURE_SIZE);
	free_texture(game->map->textures->texture_EA, TEXTURE_SIZE);
	free_texture(game->map->textures->texture_WE, TEXTURE_SIZE);
	mlx_destroy_window(game->mlx_connection, game->mlx_window);
	mlx_destroy_display(game->mlx_connection);
	mlx_destroy_image(game->mlx_connection, img->img);
	free(game->mlx_connection);
	
}

void	matrix_free(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
