/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:05:57 by apaterno          #+#    #+#             */
/*   Updated: 2025/01/07 03:54:34 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"



static void move_player(t_game *game, int keycode)
{
		if (keycode == XK_w && game->player->pos_y > PLAYERSIZE + 1)
		{	
			//if (game->player->pos_y > PLAYERSIZE + 1)
				game->player->accum_y -= game->player->dy;
				game->player->accum_x += game->player->dx;
				game->player->pos_x = round(game->player->accum_x);
				game->player->pos_y = round(game->player->accum_y);	
		}
		if (keycode == XK_s &&
			game->player->pos_y < (game->map->sizey * GRIDSIZE) - PLAYERSIZE * 2) 
		{
				game->player->accum_y += game->player->dy;
				game->player->accum_x -= game->player->dx;
				game->player->pos_x = round(game->player->accum_x);
				game->player->pos_y = round(game->player->accum_y);	
		}
		render_frame(game);
}

static void rotate_player(t_game *game, int keycode)
{
	if (keycode == XK_d)
	{
		if (game->player->direction == 0)
			game->player->direction = 360 - 1;
		else
			game->player->direction--;
	}
	if (keycode == XK_a)
	{
		if (game->player->direction == 360)
			game->player->direction = 0;
		else
			game->player->direction++;
	}
	calculate_delta(game);	
	render_frame(game);
}


int handle_key(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(game->mlx_connection, game->mlx_window);
		mlx_destroy_display(game->mlx_connection);
		free(game->mlx_connection);
		exit(1);
	}
	if (keycode == XK_w)
		move_player(game, keycode);
	if (keycode == XK_s)
		move_player(game, keycode);
	if (keycode == XK_d)
		rotate_player(game, keycode);
	if (keycode == XK_a)
		rotate_player(game, keycode);
	return (0);
}

int handle_close(t_game *game)
{
    mlx_destroy_window(game->mlx_connection, game->mlx_window);
    mlx_destroy_display(game->mlx_connection);
    free(game->mlx_connection);
    exit(0);
    return (0);
}