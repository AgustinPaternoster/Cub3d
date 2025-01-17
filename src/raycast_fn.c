/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_fn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:39:59 by apaterno          #+#    #+#             */
/*   Updated: 2025/01/16 18:43:16 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"


int is_wall(t_game *game, int x , int y)
{
		char **mapa = game->map->map;

		if(mapa[y][x] == '1')
			return (1);
		return (0);
}

// void draw_ray(t_game *game, t_player *player)
// {
// 	int i;
// 	float y;
// 	float x;
// 	int x_i;
// 	int y_i;
	
// 	i = 0;
// 	x = (float)player->pos_x;
// 	y = (float)player->pos_y;
// 	while(is_wall(game->map->map, x, y))
// 	{
// 		x += player->dx;
// 		y -= player->dy;
// 		x_i = round(x);
// 		y_i = round(y);
// 		img_pixel_put(game->img, x_i, y_i,GREEN);
// 	}
// }

