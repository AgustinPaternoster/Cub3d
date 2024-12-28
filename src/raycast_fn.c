/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_fn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:39:59 by apaterno          #+#    #+#             */
/*   Updated: 2024/12/28 18:18:56 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int set_increment(int v0, int v1)
{
	if (v0 < v1)
		return(1);
	else
		return(-1);
}

void calculate_delta(t_player *player, int *x1, int *y1)
{
	*x1 = round(player->pos_x + 30 *cos(to_radians(player->direction)));
	*y1 = round(player->pos_y + 30 *sin(to_radians(player->direction)));
	player->dx = *x1 - player->pos_x;
	player->dy = *y1 - player->pos_y;		
}
void draw_ray(t_game *game, t_player *player)
{
	int 	x;
	int 	y;
	int 	x1;
	int 	y1;
	float 	m;

	x = player->pos_x;
	y = player->pos_y;
	calculate_delta(player,&x1,&y1);
	if (abs(player->dx) >=abs(player->dy))
	{
		m = (float) player->dy / player->dx;
		while(x != x1)
		{
			img_pixel_put(game->img, x,y,GREEN);
			x += set_increment(player->pos_x, x1);
			y = round(m*(x - player->pos_x) + player->pos_y);
		}
	}
	else
	{
		m = (float) player->dx / player->dy;
		while(y != y1)
		{
			img_pixel_put(game->img, x,y,GREEN);
			y += set_increment(player->pos_y,y1);
			x = round(m*(y - player->pos_y) + player->pos_x);
		}
	}
}
