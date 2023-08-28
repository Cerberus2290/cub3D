/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:45:21 by tstrassb          #+#    #+#             */
/*   Updated: 2023/08/28 15:14:50 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void	update_direction_rotation(t_player *player, double rot)
{
	double	olddirx;

	olddirx = player->dir_x;
	player->total_rots += rot;
	player->dir_x = player->dir_x * cos(rot) - player->dir_y * sin(rot);
	player->dir_y = olddirx * sin(rot) + player->dir_y * cos(rot);
}

void	update_position_collision(t_data *data)
{
	t_player	*player;

	player = data->player;
	if (!ft_strchr("1D", data->map->map[(int)(player->pos_x
				+ player->dir_x * player->de_y)][(int)(player->pos_y)]))
		player->pos_x += player->dir_x * player->de_y;
	if (!ft_strchr("1D", data->map->map[(int)(player->pos_x)]
		[(int)(player->pos_y + player->dir_y * player->de_y)]))
		player->pos_y += player->dir_y * player->de_y;
	if (!ft_strchr("1D", data->map->map[(int)(player->pos_x
				+ player->player_x * player->de_x)][(int)(player->pos_y)]))
		player->pos_x += player->player_x * player->de_x;
	if (!ft_strchr("1D", data->map->map[(int)(player->pos_x)]
		[(int)(player->pos_y + player->player_y * player->de_x)]))
		player->pos_y += player->player_y * player->de_x;
}

void	update_plane_position(t_player *player, double rot)
{
	double	oldplanex;

	oldplanex = player->player_x;
	player->player_x = player->player_x
		* cos(rot) - player->player_y * sin(rot);
	player->player_y = oldplanex * sin(rot) + player->player_y * cos(rot);
}

void	update_param(t_data *data, double rot)
{
	update_direction_rotation(data->player, rot);
	update_position_collision(data);
	update_plane_position(data->player, rot);
}
