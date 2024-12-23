/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:18:50 by apaterno          #+#    #+#             */
/*   Updated: 2024/12/20 17:53:30 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"



void screen(t_game *game, int color, int size, int offset )
{
	int x;
	int y;

	x = offset;
	y = offset;
	size += offset;
	while (x < size)
	{
		y = offset;
		while (y < size)
		{
			img_pixel_put(game->img, x, y , color);
			y++;
		}
		x++;
	}
}

void	clean_close(t_game *game, t_imgdata *img)
{
	
	mlx_destroy_window(game->mlx_connection, game->mlx_window);
	mlx_destroy_display(game->mlx_connection);
	mlx_destroy_image(game->mlx_connection, img->img);
	free(game->mlx_connection);
	
}






