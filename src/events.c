/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:05:57 by apaterno          #+#    #+#             */
/*   Updated: 2024/12/20 18:53:56 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
//&& game->player->pos_y < game->map->sizey * GRIDSIZE
static void move_player_f(t_game *game)
{
		if (game->player->pos_y > PLAYERSIZE + 1)
		{
			game->player->pos_y -= VELOCITY;
			draw_map(game);
			draw_player(game);
			mlx_put_image_to_window(game->mlx_connection, game->mlx_window,game->img->img, 0, 0);
		}	
}


static void move_player_b(t_game *game)
{
		if (game->player->pos_y < (game->map->sizey * GRIDSIZE) - PLAYERSIZE * 2)
		{
			game->player->pos_y += VELOCITY;
			draw_map(game);
			draw_player(game);
			mlx_put_image_to_window(game->mlx_connection, game->mlx_window,game->img->img, 0, 0);
		}	
}
static void rotate_player(t_game *game, int direction)
{
		if (game->player->pos_x > 5)
		{
			game->player->pos_y += direction;
			draw_map(game);
			draw_player(game);
			mlx_put_image_to_window(game->mlx_connection, game->mlx_window,game->img->img, 0, 0);
		}	
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
		move_player_f(game);
	if (keycode == XK_s)
		move_player_b(game);		
	return (0);
}
