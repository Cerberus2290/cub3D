/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycaster_02_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:17:16 by tstrassb          #+#    #+#             */
/*   Updated: 2023/08/25 15:18:55 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d_bonus.h"

void	dda_calcu(t_data *data)
{
	data->dda->cam_x = 2 * (double)data->dda->screen_x / (double)WINDOW_W - 1;
	data->dda->ray_dir_x = data->player->dir_x
		+ data->player->player_x * data->dda->cam_x;
	data->dda->ray_dir_y = data->player->dir_y
		+ data->player->player_y * data->dda->cam_x;
	data->dda->map_x = (int)data->player->pos_x;
	data->dda->map_y = (int)data->player->pos_y;
	data->dda->delta_dist_x = fabs(1 / data->dda->ray_dir_x);
	data->dda->delta_dist_y = fabs(1 / data->dda->ray_dir_y);
	check_side(data);
	check_dist(data);
}

void	ft_raycaster(t_data *data)
{
	data->dda->screen_x = 0;
	while (data->dda->screen_x < WINDOW_W)
	{
		dda_calcu(data);
		ft_render(data);
		data->sprites->buffer[data->dda->screen_x] = data->dda->wall_dist;
		data->dda->screen_x++;
	}
	render_sprites(data);
}
