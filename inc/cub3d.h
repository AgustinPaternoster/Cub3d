/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 03:11:12 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/12/22 05:51:55 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

//defines
#define MALLOC "Malloc error\n"

typedef struct s_player
{
	int 	x_pos;
	int 	y_pos;
	
}t_player;

typedef struct s_img
{
	int 	width;
	int 	height;
	void	*img_ptr;
	
}t_img;

typedef struct s_tmap
{
	int		fd;
	char	**cub;
	char	**matrix;
	int 	size_y;
	int 	size_x;
	int		ceiling;
	int		floor;
	t_img	*no_texture;
	t_img	*so_texture;
	t_img	*we_texture;
	t_img	*ea_texture;
}			t_tmap;

typedef struct s_game
{
	void 	*mlx_connection;
	void	*mlx_window;
	t_player *player;
	t_tmap 	*map;
}t_game;


// prints.c
void    printline_fd(int fd, char *str);
void    printmatrix_fd(int fd, char **str);
void	print_game_data(t_game *game);

// frees.c
void	clean_close(t_game *game);
void	matrix_free(char **str);
void	error_exit(char *msg, int exit_code, t_game *game);

// get_map.c
int		get_map(t_game *game, char *filename);

// check_map.c
int check_map(char **matrix);

// check_map_utils.c
int get_full_height(char **matrix);
int check_line_ends(char *str);
int get_num_rows(char **matrix);
int even_map(char **matrix);
int validate_holes(char **matrix);
int validate_chars(char **matrix);

// resources.c
void	init_resources(t_game *game, char *filename);

// resources_utils.c
void    set_player_pos(t_game *game);
void    get_texture(char *prefix, t_game *game);

#endif