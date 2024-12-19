/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:44:10 by apaterno          #+#    #+#             */
/*   Updated: 2024/12/19 16:49:27 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int handle_key(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(game->mlx_connection, game->mlx_window);
		mlx_destroy_display(game->mlx_connection);
		free(game->mlx_connection);
		exit(1);
	}	
	return (0);
}

void draw_player(t_game *game)
{
	int x;
	int y;
	int posx;
	int posy;
	
	posx = (game->player->pos_x * GRIDSIZE) + (GRIDSIZE / 2) - PLAYERSIZE / 2;
	posy = (game->player->pos_y * GRIDSIZE) + (GRIDSIZE / 2) - PLAYERSIZE / 2;
	x = 0;
	while (x < PLAYERSIZE)
	{
		y = 0;
		while (y < PLAYERSIZE)
		{
			mlx_pixel_put(game->mlx_connection, game->mlx_window, posx + x , posy + y , GREEN);
			y++;
		}
		x++;
	}	
}

void draw_map(t_game *game)
{
	int x;
	int y;
	int offset;

	y = 0;
	offset = 0;
	while (y < game->map->sizey)
	{
		x = 0;
		while(game->map->map[y][x])
		{
			if (game->map->map[y][x] == '1')
			{
				draw_pixels(game, RED, GRIDSIZE, GRIDSIZE * x, GRIDSIZE * y);
				x++;
			}
			else
			{
				draw_pixels(game, BLUE, GRIDSIZE, GRIDSIZE * x, GRIDSIZE * y);
				x++;
			}
		}
		y++;
	}
	
	
}


static void	start_game(t_game *game)
{
	
	game->mlx_connection = mlx_init();
	game->mlx_window = mlx_new_window(game->mlx_connection, GRIDSIZE * game->map->sizex , GRIDSIZE * game->map->sizey, "cub3D");
	draw_map(game);
	draw_player(game);
	game->img->img = mlx_new_image(game->mlx_connection, GRIDSIZE * game->map->sizex, GRIDSIZE * game->map->sizey);
	//mlx_pixel_put(map->mlx_connection,map->mlx_window,)
	game->img->addr = mlx_get_data_addr(game->img->img, &game->img->bits_per_pixel, &game->img->line_length, & game->img->endian);
	// screen(map,2303,1000,0);
	//mlx_put_image_to_window(map->mlx_connection, map->mlx_window,map->img->img, 0, 0);
	mlx_key_hook(game->mlx_window,handle_key,game);
	mlx_loop(game->mlx_connection);
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_imgdata img;
	t_map	map;
	t_player player;
	
	char *mapa[6];
	mapa[0] = ft_strdup("1111111");
	mapa[1] = ft_strdup("1000001");
	mapa[2] = ft_strdup("1011001");
	mapa[3] = ft_strdup("1000001");
	mapa[4] = ft_strdup("1000001");
	mapa[5] = ft_strdup("1111111");
	(void)argc;
	(void)argv;
	game.img = &img;
	game.map = &map;
	game.player = &player;
	map.map = mapa;
	map.sizey =  6;
	map.sizex = 7;
	player.pos_x = 4;
	player.pos_y = 4;
	start_game(&game);
	clean_close(&game, &img);
	for (int i = 0; i < 5; i++)
		free(map.map[i]);
	return (0);
}
