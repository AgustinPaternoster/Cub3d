/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 04:56:51 by mgimon-c          #+#    #+#             */
/*   Updated: 2025/02/04 17:37:17 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void free_texture(t_text_info *text)
{
	int i;

	i = 0;
	while(i < text->hight)
	{
		free(text->texture[i]);
		i++; 
	}
	free(text->texture);
}

void	clean_close(t_game *game, t_imgdata *img)
{	
	free_texture(game->texture);
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
