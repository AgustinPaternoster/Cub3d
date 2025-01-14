/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_fn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:39:59 by apaterno          #+#    #+#             */
/*   Updated: 2025/01/14 20:20:44 by mgimon-c         ###   ########.fr       */
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

/*void draw_ray(t_game *game, t_player *player)
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
}*/

void draw_ray(t_game *game, t_player *player)
{
    int i;
    float ray_angle;
    float step_angle = to_radians(V_ANGLE) / (1000 - 1);  // 1000 rays
    float x, y;
    int x_i, y_i;

    ray_angle = to_radians(player->direction) - (to_radians(V_ANGLE) / 2);
	i = 0;
    while (i < 1000)
    {
        x = (float)player->pos_x;
        y = (float)player->pos_y;
        while (check_wall(game, x, y)) 
        {
            x += cos(ray_angle);
            y -= sin(ray_angle);
            x_i = round(x);
            y_i = round(y);
            img_pixel_put(game->img, x_i, y_i, GREEN);
        }
        ray_angle += step_angle;
		i++;
    }
}