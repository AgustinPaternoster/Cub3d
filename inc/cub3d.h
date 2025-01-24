/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 03:11:12 by mgimon-c          #+#    #+#             */
/*   Updated: 2025/01/24 17:10:28 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>


# define SCREEN_WITH 800
# define SCREEN_HIGH 600
# define VELO_MOV 0.01
# define VELO_ROT 5
# define GRIDSIZE 100
# define PLAYERSIZE 4
# define RED 16711680
# define GREEN 65280
# define BLUE 255
# define LIGHT_BLUE 13434879
# define GREY 13158600
# define PI 3.141592
# define LINE_SIZE 10

typedef struct s_ray
{
	float delta_dis_x;
	float delta_dis_y;
	float side_dis_x;
	float side_dis_y;
	int 	map_pos[2];
	float	camera_pos[2];
	float	delta[2];
	int 	side;
	int 	stepx;
	int 	stepy;
	float	distance;
}t_ray;

typedef struct  s_imgdata
{
	void *img;
	char *addr;
	int  bits_per_pixel;
	int line_length;
	int endian; 
}t_imgdata;

typedef struct s_map
{
	char 	**map;
	int 	sizex;
	int 	sizey;
}t_map;

typedef struct s_player
{
	float pos_x;
	float pos_y;
	int direction;
	float dx;
	float dy;
}t_player;

typedef struct s_game
{
	void 	*mlx_connection;
	void	*mlx_window;
	void 	*mlx_window_map;
	t_map	*map;
	t_player *player;
	t_imgdata *img;
	t_imgdata *img_map;
	t_ray		*ray;
}			t_game;

//// test minilibx
void img_pixel_put(t_imgdata *img, int x, int y, int color);
void screen(t_game *game, int color, int size, int offset );
void clean_close(t_game *game, t_imgdata *img);
void draw_pixels(t_game *game, int color, int size, int offset_x, int offset_y);
int handle_key(int keycode, t_game *game);
int handle_close(t_game *game);
///render
void draw_player(t_game *game);
void draw_map(t_game *game);
void print_point(t_ray *ray, t_imgdata *img);
void render_frame(t_game *game);
void draw_walls(t_game *game, int column);

//DDA_alg
void draw_rays(t_game *game);
// Math
float to_radians(int degrees);
void calculate_delta(t_game *game);
float calculate_sx(float dx , float dy);
float calculate_sy(float dx , float dy);

// float calculate_sx(t_game *game);
// float calculate_sy(t_game *game);
float end_point(float distance, float start, float dir);

//DDA
void calculate_x_ray(t_game *game);

// prints.c
void    printline_fd(int fd, char *str);
void    printmatrix_fd(int fd, char **str);

// frees.c
//void	clean_close(t_tmap *map, t_imgdata *img);
void	matrix_free(char **str);

// get_map.c
//void    get_map(t_tmap *tmap, char *filename);

// check_map.c
int check_map(char **matrix);

// check_map_utils.c
int get_full_height(char **matrix);
int check_line_ends(char *str);
int get_num_rows(char **matrix);
int even_map(char **matrix);
int validate_holes(char **matrix);

#endif