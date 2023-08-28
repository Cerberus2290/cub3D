/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util02_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:44:30 by tstrassb          #+#    #+#             */
/*   Updated: 2023/08/28 15:13:28 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void	create_spawn(t_data *data)
{
	init_player(data);
	data->map->dir_spawn = ((t_items *)(data->map->spawn->content))->type;
	data->player->pos_x = ((t_items *)(data->map->spawn->content))->pos_y + 0.5;
	data->player->pos_y = ((t_items *)(data->map->spawn->content))->pos_x + 0.5;
}

void	create_plane(t_data *data, char flag)
{
	if (flag == 'W')
	{
		data->player->player_x = -0.66;
		data->player->dir_y = -1;
	}
	else if (flag == 'E')
	{
		data->player->player_x = 0.66;
		data->player->dir_y = 1;
	}
	else if (flag == 'N')
	{
		data->player->player_y = 0.66;
		data->player->dir_x = -1;
	}
	else if (flag == 'S')
	{
		data->player->player_y = -0.66;
		data->player->dir_x = 1;
	}
}

void	ft_mlx_pixel_put(t_imgs *imgs, int x, int y, int color)
{
	int	*dest;

	dest = (void *)imgs->p_img + (y * imgs->s_line + x * (imgs->bt / 8));
	*(int *)dest = color;
}
