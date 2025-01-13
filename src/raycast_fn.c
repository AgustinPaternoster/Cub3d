/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_fn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:39:59 by apaterno          #+#    #+#             */
/*   Updated: 2025/01/13 17:15:10 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"


int check_wall(t_game *game, float x , float y)
{
		t_map *mapa;
		int x1 = x / 100;
		int y1 = y / 100;
		mapa = game->map;
		if(mapa->map[y1][x1] == '1')
			return (0);
		return (1);
}

void draw_ray(t_game *game, t_player *player)
{
	int i;
	float y;
	float x;
	int x_i;
	int y_i;
	
	i = 0;
	x = (float)player->pos_x;
	y = (float)player->pos_y;
	while(check_wall(game, x, y))
	{
		x += player->dx;
		y -= player->dy;
		x_i = round(x);
		y_i = round(y);
		img_pixel_put(game->img, x_i, y_i,GREEN);
	}
}