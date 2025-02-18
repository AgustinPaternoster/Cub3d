/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:05:57 by apaterno          #+#    #+#             */
/*   Updated: 2025/02/18 19:19:03 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void move_player(t_game *game, int keycode)
{
		if (keycode == XK_w && round(game->player->pos_y * 100) > PLAYERSIZE + 1)
		{	
			//if (game->player->pos_y > PLAYERSIZE + 1)
				game->player->pos_y += game->player->dy * VELO_MOV;
				game->player->pos_x += game->player->dx * VELO_MOV;
		}
		if (keycode == XK_s &&
			game->player->pos_y < (game->map->sizey * GRIDSIZE) - PLAYERSIZE * 2) 
		{
				game->player->pos_y -= game->player->dy * VELO_MOV;
				game->player->pos_x -= game->player->dx * VELO_MOV;
		}
		render_frame(game);
}

static void rotate_player(t_game *game, int keycode)
{
	float tmp_dirx;
	float tmp_scrdx;
	t_player *player;
	
	player = game->player;
	if (keycode == XK_d)
	{
		//if (game->player->direction == 0)
		//	game->player->direction = 360 - (M_PI / 180);
		//else
		//	game->player->direction -= (M_PI / 180);
		tmp_dirx = player->dx;
		player->dx = player->dx * cos((M_PI / 180)) - player->dy * sin((M_PI / 180));
		player->dy = tmp_dirx * sin((M_PI / 180)) + player->dy * cos((M_PI / 180));
		tmp_scrdx = player->scr_dx;
		player->scr_dx = player->scr_dx * cos((M_PI / 180)) - player->scr_dy * sin((M_PI / 180));
		player->scr_dy = tmp_scrdx * sin((M_PI / 180)) + player->scr_dy * cos((M_PI / 180));
	} 
	if (keycode == XK_a)
	{
		tmp_dirx = player->dx;
		player->dx = player->dx * cos((M_PI / 180) * -1) - player->dy * sin((M_PI / 180) * -1);
		player->dy = tmp_dirx * sin((M_PI / 180) * -1) + player->dy * cos((M_PI / 180) * -1);
		tmp_scrdx = player->scr_dx;
		player->scr_dx = player->scr_dx * cos((M_PI / 180) * -1) - player->scr_dy * sin((M_PI / 180) * -1);
		player->scr_dy = tmp_scrdx * sin((M_PI / 180) * -1) + player->scr_dy * cos((M_PI / 180) * -1);
	}
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