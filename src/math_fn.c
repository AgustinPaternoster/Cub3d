/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_fn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:25:55 by apaterno          #+#    #+#             */
/*   Updated: 2025/01/23 18:27:24 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

float to_radians(int degrees)
{
	return ((M_PI * degrees) / 180);
}

void calculate_delta(t_game *game)
{
	int direction;
	
	direction = game->player->direction;
	game->player->dx = cos(to_radians(direction));
	game->player->dy = -1 * sin(to_radians(direction));	
}

float calculate_sx(float dx , float dy)
{
	float x;	
	// corregir division por 0
	x = pow((dy / dx) ,2);
	return(sqrt(1 + x));
}

float calculate_sy(float dx , float dy)
{
	float x;
		// corregir division por 0
	x = pow((dx / dy ), 2);
	return(sqrt(1 + x));
}

float end_point(float distance, float start, float dir)
{
	return(start * GRIDSIZE + (distance * dir * GRIDSIZE));
}