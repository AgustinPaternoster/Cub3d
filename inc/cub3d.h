/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 03:11:12 by mgimon-c          #+#    #+#             */
/*   Updated: 2025/02/03 19:07:24 by apaterno         ###   ########.fr       */
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

# define BLUE 4735733 
# define RED 16073282
# define HIGH 1000
# define WIDTH 1000
# define TXT_H 256
# define TXT_W 256

typedef struct s_texture
{
	int **texture;
	int width;
	int heigh;
}t_texture;


typedef struct  s_imgdata
{
	void *img;
	char *addr;
	int  bits_per_pixel;
	int line_length;
	int endian; 
}t_imgdata;

typedef struct s_tmap
{
	void 	*mlx_connection;
	void	*mlx_window;
	char 	**map;
	int 	sizex;
	int 	sizey;
	t_imgdata *img_base;
	t_texture *txt;
}			t_tmap;

//// test minilibx
void img_pixel_put(t_imgdata *img, int x, int y, int color);
void paint_img(t_imgdata *img, int color , int width , int heigh);
void pixel_color(t_imgdata *img , int x , int y);

//utilities
int **create_txt_array(int with , int heigh);
void clean_txt(int **txt, int heigh , int width);
int get_color(t_imgdata *img, int x , int y);
void xmp_to_int(t_tmap *map, char *path);
void int_to_img(t_tmap *map);
void int_to_img_rescaled(t_tmap *map, int distance);

// prints.c
void    printline_fd(int fd, char *str);
void    printmatrix_fd(int fd, char **str);

// frees.c
void	clean_close(t_tmap *map, t_imgdata *img);
void	matrix_free(char **str);

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