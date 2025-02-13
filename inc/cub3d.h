/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 03:11:12 by mgimon-c          #+#    #+#             */
/*   Updated: 2025/02/11 17:14:15 by apaterno         ###   ########.fr       */
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
# define VELO_MOV 0.04
# define VELO_ROT 5
# define GRIDSIZE 100
# define PLAYERSIZE 4
# define RED 16711680
# define GREEN 65280
# define BLUE 255
# define LIGHT_BLUE 13434879
# define GREY 13158600
# define RADIAN 0.01745329252 
# define LINE_SIZE 10

typedef struct s_ray
{
	float delta_dis_x;
	float delta_dis_y;
	float side_dis_x;
	float side_dis_y;
	int 	map_pos[2];
	float	camera_pos[2];
	float	ray_dir[2];
	int 	side;
	int 	stepx;
	int 	stepy;
	float	distance;
	float 	camera_dx;
}t_ray;

typedef struct  s_imgdata
{
	void *img;
	char *addr;
	int  bits_per_pixel;
	int line_length;
	int endian;
	int 	width;
	int 	height; 
}t_imgdata;

typedef struct s_map
{
	char 	**map;
	int		fd;
	char	**cub;
	char	**matrix;
	int 	sizex;
	int 	sizey;
	int		ceiling;
	int		floor;
	t_imgdata	*no_texture;
	t_imgdata	*so_texture;
	t_imgdata	*we_texture;
	t_imgdata	*ea_texture;
}t_map;

typedef struct s_player
{
	float pos_x;
	float pos_y;
	float dx;
	float dy;
	float scr_dx;
	float scr_dy;
}t_player;

typedef struct s_game
{
	void 	*mlx_connection;
	void	*mlx_window;
	t_map	*map;
	t_player *player;
	t_imgdata *img;
	t_ray		*ray;
}			t_game;

//// test minilibx
void img_pixel_put(t_imgdata *img, int x, int y, int color);
void screen(t_game *game, int color, int size, int offset );
void clean_close(t_game *game);
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
void init_player_dir(t_game *game, char dir);
float calculate_sx(float dx , float dy);
float calculate_sy(float dx , float dy);
void update_delta(t_game *game, int dir);

float end_point(float distance, float start, float dir);

//DDA
void calculate_x_ray(t_game *game);

// prints.c
void    printline_fd(int fd, char *str);
void    printmatrix_fd(int fd, char **str);
void	print_game_data(t_game *game);

// frees.c
//void	clean_close(t_tmap *map, t_imgdata *img);
void	free_structs(t_game *game);
void	matrix_free(char **str);
void	free_parsing(t_game *game);

// get_map.c
int	get_map(t_game *game, char *filename);

// check_map.c
int check_map(char **matrix);

// check_map_utils.c
int get_full_height(char **matrix);
int check_line_ends(char *str);
int get_num_rows(char **matrix);
int even_map(char **matrix);
int validate_holes(char **matrix);
int validate_chars(char **matrix);
int map_full_to_bottom(char **matrix);

// resources.c
void	init_resources(t_game *game, char *filename);

//resources_utils.c
void    get_texture(char *prefix, t_game *game);
void    set_player_pos(t_game *game);

#endif