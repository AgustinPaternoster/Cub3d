/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_fn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:25:55 by apaterno          #+#    #+#             */
/*   Updated: 2025/01/14 17:30:17 by apaterno         ###   ########.fr       */
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
	game->player->dy = sin(to_radians(direction));	
}

// float calculate_sx(t_game *game)
// {
// 	float x;
	
// 	x = (game->player->dy / game->player->dx) * 2;
// 	return(sqrt(1 + x));
// }

// float calculate_sy(t_game *game)
// {
// 	float x;
// 	x = (game->player->dx / game->player->dy ) * 2;
// 	return(sqrt(1 + x));
// }

float calculate_sx(t_game *game)
{
	float x;
	
	x = pow((game->player->dy / game->player->dx) ,2);
	return(sqrt(1 + x));
}

float calculate_sy(t_game *game)
{
	float x;
	x = pow((game->player->dx / game->player->dy ), 2);
	return(sqrt(1 + x));
}