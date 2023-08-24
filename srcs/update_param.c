/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:45:21 by tstrassb          #+#    #+#             */
/*   Updated: 2023/08/24 10:04:49 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

/* void	update_rotation(t_data *data, double rot)
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
}

void	update_movement(t_data *data)
{
	if (!ft_strchr("1D", data->map->map[(int)(data->player->pos_x
				+ data->player->dir_x * data->player->de_y)]
		[(int)(data->player->pos_y)]))
		data->player->pos_x += data->player->dir_y * data->player->de_y;
	if (!ft_strchr("1D", data->map->map[(int)(data->player->pos_x)]
		[(int)(data->player->pos_y
			+ data->player->dir_y * data->player->de_y)]))
		data->player->pos_y += data->player->dir_y * data->player->de_y;
	if (!ft_strchr("1D", data->map->map[(int)(data->player->pos_x
				+ data->player->player_x * data->player->de_x)]
		[(int)(data->player->pos_y)]))
		data->player->pos_x += data->player->player_x * data->player->de_x;
	if (!ft_strchr("1D", data->map->map[(int)(data->player->pos_x)]
		[(int)(data->player->pos_y
			+ data->player->player_y * data->player->de_x)]))
		data->player->pos_y += data->player->player_y * data->player->de_x;
}

void	update_param(t_data *data, double rot)
{
	update_rotation(data, rot);
	update_movement(data);
} */

/* void	update_param(t_data *data, double rot)
{
	double	olddirx;
	double	oldplanex;

	olddirx = data->player->dir_x;
	data->player->total_rots += rot;
	data->player->dir_x = data->player->dir_x * cos(rot) - data->player->dir_y * sin(rot);
	data->player->dir_y = olddirx * sin(rot) + data->player->dir_y * cos(rot);
	oldplanex = data->player->player_x;
	data->player->player_x = data->player->player_x * cos(rot) - data->player->player_y * sin(rot);
	data->player->player_y = oldplanex * sin(rot) + data->player->player_y * cos(rot);
	if (!ft_strchr("1D", data->map->map[(int)(data->player->pos_x + \
			data->player->dir_x * data->player->de_y)][(int)(data->player->pos_y)]))
		data->player->pos_x += data->player->dir_x * data->player->de_y;
	if (!ft_strchr("1D", data->map->map[(int)(data->player->pos_x)] \
			[(int)(data->player->pos_y + data->player->dir_y * data->player->de_y)]))
		data->player->pos_y += data->player->dir_y * data->player->de_y;
	if (!ft_strchr("1D", data->map->map[(int)(data->player->pos_x + \
			data->player->player_x * data->player->de_x)][(int)data->player->pos_y]))
		data->player->pos_x += data->player->player_x * data->player->de_x;
	if (!ft_strchr("1D", data->map->map[(int)data->player->pos_x] \
			[(int)(data->player->pos_y + data->player->player_y * data->player->de_x)]))
		data->player->pos_y += data->player->player_y * data->player->de_x;
} */

void	update_direction_rotation(t_player *player, double rot)
{
	double olddirx;
	
	olddirx = player->dir_x;
	player->total_rots += rot;
	player->dir_x = player->dir_x * cos(rot) - player->dir_y * sin(rot);
	player->dir_y = olddirx * sin(rot) + player->dir_y * cos(rot);
}

void	update_position_collision(t_data *data)
{
	t_player *player;
	
	player = data->player;
	if (!ft_strchr("1D", data->map->map[(int)(player->pos_x + player->dir_x * player->de_y)][(int)(player->pos_y)]))
		player->pos_x += player->dir_x * player->de_y;

	if (!ft_strchr("1D", data->map->map[(int)(player->pos_x)][(int)(player->pos_y + player->dir_y * player->de_y)]))
		player->pos_y += player->dir_y * player->de_y;

	if (!ft_strchr("1D", data->map->map[(int)(player->pos_x + player->player_x * player->de_x)][(int)(player->pos_y)]))
		player->pos_x += player->player_x * player->de_x;

	if (!ft_strchr("1D", data->map->map[(int)(player->pos_x)][(int)(player->pos_y + player->player_y * player->de_x)]))
		player->pos_y += player->player_y * player->de_x;
}

void	update_plane_position(t_player *player, double rot)
{
	double oldplanex;
	
	oldplanex = player->player_x;
	player->player_x = player->player_x * cos(rot) - player->player_y * sin(rot);
	player->player_y = oldplanex * sin(rot) + player->player_y * cos(rot);
}

void	update_param(t_data *data, double rot)
{
	update_direction_rotation(data->player, rot);
	update_position_collision(data);
	update_plane_position(data->player, rot);
}
