/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycaster.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 08:54:55 by tstrassb          #+#    #+#             */
/*   Updated: 2023/08/30 10:55:28 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

/* Check which side we hit */
void	is_side(t_data *data)
{
	data->dda->hit = 1;
	if (!data->dda->side)
	{
		if (data->dda->ray_dir_x < 0)
			data->dda->side = 1;
		else if (data->dda->ray_dir_x > 0)
			data->dda->side = 2;
	}
	else if (data->dda->side == 1)
	{
		if (data->dda->ray_dir_y < 0)
			data->dda->side = 3;
		else if (data->dda->ray_dir_y > 0)
			data->dda->side = 4;
	}
}

/* Chechs how far the wall is when we move */
void	check_dist_move(t_data *data)
{
	if (data->dda->side_dist_x < data->dda->side_dist_y)
	{
		data->dda->side_dist_x += data->dda->delta_dist_x;
		data->dda->map_x += data->dda->move_x;
		data->dda->side = 0;
	}
	else
	{
		data->dda->side_dist_y += data->dda->delta_dist_y;
		data->dda->map_y += data->dda->move_y;
		data->dda->side = 1;
	}
	if (data->map->map[data->dda->map_x][data->dda->map_y] == '1')
		is_side(data);
}

/* Checks how far the wall when hit */
void	check_dist(t_data *data)
{
	data->dda->hit = 0;
	data->dda->side = 0;
	while (data->dda->hit == 0)
		check_dist_move(data);
	if (data->dda->side == 1 || data->dda->side == 2 || \
		data->dda->side == 13 || data->dda->side == 14)
		data->dda->wall_dist = (data->dda->map_x - data->player->pos_x + \
			(1 - data->dda->move_x) / 2) / data->dda->ray_dir_x;
	else if (data->dda->side == 3 || data->dda->side == 4 || \
			data->dda->side == 15 || data->dda->side == 16)
		data->dda->wall_dist = (data->dda->map_y - data->player->pos_y + \
			(1 - data->dda->move_y) / 2) / data->dda->ray_dir_y;
}

/* calc side */
void	check_side(t_data *data)
{
	if (data->dda->ray_dir_x < 0)
	{
		data->dda->move_x = -1;
		data->dda->side_dist_x = (data->player->pos_x - \
			data->dda->map_x) * data->dda->delta_dist_x;
	}
	else
	{
		data->dda->move_x = 1;
		data->dda->side_dist_x = (data->dda->map_x + 1.0 - \
			data->player->pos_x) * data->dda->delta_dist_x;
	}
	if (data->dda->ray_dir_y < 0)
	{
		data->dda->move_y = -1;
		data->dda->side_dist_y = (data->player->pos_y - \
			data->dda->map_y) * data->dda->delta_dist_y;
	}
	else
	{
		data->dda->move_y = 1;
		data->dda->side_dist_y = (data->dda->map_y + 1.0 - \
			data->player->pos_y) * data->dda->delta_dist_y;
	}
}

void	dda_calcu(t_data *data)
{
	data->dda->cam_x = 2 * (double)data->dda->screen_x / (double)WINDOW_W - 1;
	data->dda->ray_dir_x = data->player->dir_x
		+ data->player->player_x * data->dda->cam_x;
	data->dda->ray_dir_y = data->player->dir_y
		+ data->player->player_y * data->dda->cam_x;
	data->dda->map_x = (int)data->player->pos_x ;
	data->dda->map_y = (int)data->player->pos_y;
	data->dda->delta_dist_x = fabs(1 / data->dda->ray_dir_x);
	data->dda->delta_dist_y = fabs(1 / data->dda->ray_dir_y);
	check_side(data);
	check_dist(data);
}
