/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:44:10 by apaterno          #+#    #+#             */
/*   Updated: 2024/12/10 04:59:04 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int main (int argc , char ** argv)
{
	t_tmap	tmap;

	(void)argc;
	(void)argv;
	get_map(&tmap, "maps/test_map.cub");
	printmatrix_fd(2, tmap.matrix);
	matrix_free(tmap.matrix);
	return (0);
}