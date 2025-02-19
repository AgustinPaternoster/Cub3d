/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:41:08 by apaterno          #+#    #+#             */
/*   Updated: 2025/02/19 18:48:51 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	rotate_r(t_player *player, float tmp_dirx, float tmp_scrdx)
{
	player->dx = player->dx * cos((M_PI / 180) * VELO_ROT) 
				- player->dy * sin((M_PI / 180) * VELO_ROT);
	player->dy = tmp_dirx * sin((M_PI / 180) * VELO_ROT) +
				player->dy * cos((M_PI / 180) * VELO_ROT);
	player->scr_dx = player->scr_dx * cos((M_PI / 180) * VELO_ROT) -
				player->scr_dy * sin((M_PI / 180) * VELO_ROT);
	player->scr_dy = tmp_scrdx * sin((M_PI / 180) * VELO_ROT) +
				player->scr_dy * cos((M_PI / 180) * VELO_ROT);
}

void	rotate_l(t_player *player, float tmp_dirx, float tmp_scrdx)
{
	player->dx = player->dx * cos((M_PI / 180) * VELO_ROT * -1) -
				player->dy * sin((M_PI / 180) * VELO_ROT * -1);
	player->dy = tmp_dirx * sin((M_PI / 180) * VELO_ROT * -1) +
				player->dy * cos((M_PI / 180) * VELO_ROT * -1);
	player->scr_dx = player->scr_dx * cos((M_PI / 180) * VELO_ROT * -1) -
				player->scr_dy * sin((M_PI / 180) * VELO_ROT * -1);
	player->scr_dy = tmp_scrdx * sin((M_PI / 180) * VELO_ROT * -1) +
				player->scr_dy * cos((M_PI / 180) * VELO_ROT * -1);
}