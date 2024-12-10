/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 03:11:12 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/12/10 17:17:46 by apaterno         ###   ########.fr       */
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

typedef struct s_tmap
{
	char	**matrix;
	void 	*mlx_connection;
	void	*mlx_window;
}			t_tmap;

// prints.c
void    printline_fd(int fd, char *str);
void    printmatrix_fd(int fd, char **str);

// frees.c
void    clean_close(t_tmap map);

// get_map.c
void    get_map(t_tmap *tmap, char *filename);

#endif