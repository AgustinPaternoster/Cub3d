/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 03:11:12 by mgimon-c          #+#    #+#             */
/*   Updated: 2025/02/21 20:17:39 by mgimon-c         ###   ########.fr       */
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
# define VELO_ROT 4
# define GRIDSIZE 100
# define PLAYERSIZE 4
# define RED 16711680
# define GREEN 65280
# define BLUE 255
# define LIGHT_BLUE 13434879
# define GREY 13158600
# define RADIAN 0.01745329252 
# define LINE_SIZE 10
# define TEXTURE_SIZE 64

typedef enum s_bool
{
	FALSE,
	TRUE
}t_bool;

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
	float 	camara_dx;
	int 	texture_pixel;
}t_ray;

typedef struct s_texture
{
	int **texture_NO;
	int **texture_SO;
	int **texture_WE;
	int **texture_EA;
	char *path_NO;
	char *path_SO;
	char *path_WE;
	char *path_EA;
	int size;	
}t_texture;

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
	t_texture *textures;
	t_imgdata	*no_texture;
	t_imgdata	*so_texture;
	t_imgdata	*we_texture;
	t_imgdata	*ea_texture;
}t_map;

typedef struct s_player
{
	char  direction;
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

// test minilibx
void img_pixel_put(t_imgdata *img, int x, int y, int color);
void screen(t_game *game, int color, int size, int offset );
void clean_close(t_game *game);
void draw_pixels(t_game *game, int color, int size, int offset_x, int offset_y);
int handle_key(int keycode, t_game *game);
int handle_close(t_game *game);
//render
void draw_player(t_game *game);
void draw_map(t_game *game);
void print_point(t_ray *ray, t_imgdata *img);
void render_frame(t_game *game);
void draw_walls(t_game *game, int column);

// texture
void int_to_img(t_game *game);
t_bool init_texture(t_game *game, int size);
void parse_texture(t_game *game, char *path, char orientation);
int  **select_tetxture(t_game *game, t_ray *ray);

//DDA_alg
void draw_rays(t_game *game);

// Math
float to_radians(int degrees);
void init_player_dir(t_game *game, char dir);
float calculate_sx(float dx , float dy);
float calculate_sy(float dx , float dy);
void update_delta(t_game *game, int dir);
int  end_point(float distance, float start, float dir);

//DDA
void calculate_x_ray(t_game *game);

// prints.c
void    printline_fd(int fd, char *str);
void    printmatrix_fd(int fd, char **str);
void	print_game_data(t_game *game);

// frees.c
void	free_structs(t_game *game);
void	matrix_free(char **str);
void	free_parsing(t_game *game);

// get_map.c
int	get_map(t_game *game, char *filename);

// check_map.c
int check_map(t_game *game, char **matrix);

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

// events.c
void rotate_r(t_player *player , float tmp_dirx, float tmp_scrdx);
void rotate_l(t_player *player, float tmp_dirx, float tmp_scrdx);

// main.c
void	malloc_err(void);



#endif