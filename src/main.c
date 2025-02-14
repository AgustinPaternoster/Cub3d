/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:44:10 by apaterno          #+#    #+#             */
/*   Updated: 2025/02/14 12:03:47 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void init_game(t_game *game)
{
	game->mlx_connection = mlx_init();
	// linea para imprimir el mapa
	//game->mlx_window = mlx_new_window(game->mlx_connection, GRIDSIZE * game->map->sizex , GRIDSIZE * game->map->sizey, "cub3D");
	game->mlx_window = mlx_new_window(game->mlx_connection, SCREEN_WITH , SCREEN_HIGH, "cub3D");
	// linea para imprimir la imagen del mapa	
	// game->img->img = mlx_new_image(game->mlx_connection, GRIDSIZE * game->map->sizex, GRIDSIZE * game->map->sizey);
	game->img->img = mlx_new_image(game->mlx_connection, SCREEN_WITH, SCREEN_HIGH);
	game->img->addr = mlx_get_data_addr(game->img->img, &game->img->bits_per_pixel, &game->img->line_length, & game->img->endian);
	init_texture(game, TEXTURE_SIZE);
	parse_texture(game, "./textura/NO.xpm", 'N');
	parse_texture(game, "./textura/SO.xpm", 'S');
	parse_texture(game, "./textura/EA.xpm", 'E');
	parse_texture(game, "./textura/WE.xpm", 'W');
}

static void	start_game(t_game *game)
{
	render_frame(game);
	mlx_hook(game->mlx_window, 17, 0, handle_close, game);
	mlx_hook(game->mlx_window, 2, 1L<<0, handle_key,game);
	mlx_loop(game->mlx_connection);
}

void player_pos(t_game *game, int posx, int posy, char dir)
{
	game->player->pos_x = (float)posx + 0.5;
	game->player->pos_y = (float)posy + 0.5;
	//game->player->direction = direction;
	init_player_dir(game, dir);
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_imgdata img;
	t_map	map;
	t_player player;
	t_ray	ray;
	t_texture texture;
	
	char *mapa[6];
	mapa[0] = ft_strdup("1111111");
	mapa[1] = ft_strdup("1000001");
	mapa[2] = ft_strdup("1111111");
	mapa[3] = ft_strdup("100N001");
	mapa[4] = ft_strdup("1000001");
	mapa[5] = ft_strdup("1111111");
	(void)argc;
	(void)argv;
	game.img = &img;
	game.map = &map;
	game.player = &player;
	game.ray = &ray;
	map.textures = &texture;
	map.map = mapa;
	map.sizey =  6;
	map.sizex = 7;
	player_pos(&game, 3 , 3, 'N');
	init_game(&game);
	start_game(&game);
	clean_close(&game, &img);
	for (int i = 0; i < 6; i++)
		free(map.map[i]);
	return (0);
}
