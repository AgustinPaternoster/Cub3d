/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 03:11:12 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/12/12 16:51:30 by apaterno         ###   ########.fr       */
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
typedef struct s_tmap
{
	char	**matrix;
	int 	size_y;
	int 	size_x;
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

// frees.c
void	clean_close(t_game *game);
void	matrix_free(char **str);
void	error_exit(char *msg, int exit_code, t_game *game);

// get_map.c
void    get_map(t_tmap *tmap, char *filename);

// check_map.c
int check_map(char **matrix);

// check_map_utils.c
int get_full_height(char **matrix);
int check_line_ends(char *str);
int get_num_rows(char **matrix);
int even_map(char **matrix);
int validate_holes(char **matrix);

#endif