/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_fn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:39:59 by apaterno          #+#    #+#             */
/*   Updated: 2025/01/14 22:10:41 by mgimon-c         ###   ########.fr       */
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
    float ray_angle;
    float step_angle = to_radians(V_ANGLE) / (1000 - 1);  // 1000 rays
    float x, y;
    int x_i, y_i;
    float distance;

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
        }
        if (x < 0 || x >= game->map->sizex * GRIDSIZE || y < 0 || y >= game->map->sizey * GRIDSIZE)
            distance = -1;
        else
            distance = sqrt(pow(x - player->pos_x, 2) + pow(y - player->pos_y, 2));
        int line_height = (distance == -1) ? game->map->sizey * GRIDSIZE : (int)((game->map->sizey * GRIDSIZE) / ((distance + 0.0001) * WALL_SIZE));
        int center_x = (i * (game->map->sizex * GRIDSIZE)) / 1000;
        int start_y = ((game->map->sizey * GRIDSIZE) - line_height) / 2;
        int end_y = start_y + line_height;
        
        for (int y = 0; y < game->map->sizey * GRIDSIZE; y++)
        {
            if (y < start_y || y >= end_y)
            {
                img_pixel_put(game->img, center_x, y, BLUE);
            }
        }
        ray_angle += step_angle;
        i++;
    }
}*/

void draw_ray(t_game *game, t_player *player)
{
    int i;
    float ray_angle;
    float step_angle = to_radians(V_ANGLE) / (1000 - 1);  // 1000 rays
    float x, y;
    int x_i, y_i;
    float distance;

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
        }
        if (x < 0 || x >= game->map->sizex * GRIDSIZE || y < 0 || y >= game->map->sizey * GRIDSIZE)
            distance = -1;
        else
            distance = sqrt(pow(x - player->pos_x, 2) + pow(y - player->pos_y, 2));

        int line_height = (distance == -1) ? game->map->sizey * GRIDSIZE : (int)((game->map->sizey * GRIDSIZE) / ((distance + 0.0001) * WALL_SIZE));
        int center_x = (i * (game->map->sizex * GRIDSIZE)) / 1000;
        int start_y = ((game->map->sizey * GRIDSIZE) - line_height) / 2;
        int end_y = start_y + line_height;
        
        for (int y = 0; y < start_y && y < game->map->sizey * GRIDSIZE; y++)
            if (center_x >= 0 && center_x < game->map->sizex * GRIDSIZE && y >= 0 && y < game->map->sizey * GRIDSIZE)
                img_pixel_put(game->img, center_x, y, BLUE);
        for (int y = start_y; y < end_y && y < game->map->sizey * GRIDSIZE; y++)
        {
            if (center_x >= 0 && center_x < game->map->sizex * GRIDSIZE && y >= 0 && y < game->map->sizey * GRIDSIZE)
                img_pixel_put(game->img, center_x, y, WHITE);
            else
                break;
        }
        for (int y = end_y; y < game->map->sizey * GRIDSIZE && y < game->map->sizey * GRIDSIZE; y++)
            if (center_x >= 0 && center_x < game->map->sizex * GRIDSIZE && y >= 0 && y < game->map->sizey * GRIDSIZE)
                img_pixel_put(game->img, center_x, y, RED);
        ray_angle += step_angle;
        i++;
    }
}