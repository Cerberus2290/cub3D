/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:45:21 by tstrassb          #+#    #+#             */
/*   Updated: 2023/08/14 13:45:21 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void	update_param(t_data *data, double rot)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player->dir_x;
	data->player->total_rots += rot;
	data->player->dir_x = data->player->dir_x * cos(rot)
		- data->player->dir_y * sin(rot);
	data->player->dir_y = old_dir_x * sin(rot) + data->player->dir_y * cos(rot);
	old_plane_x = data->player->player_x;
	data->player->player_x = data->player->player_x * cos(rot)
		- data->player->player_y * sin(rot);
	data->player->player_y = old_plane_x * sin(rot)
		+ data->player->player_y * cos(rot);
	if (!ft_strchr("1D", data->map->map[(int)(data->player->pos_x +
			data->player->dir_x)]))
}