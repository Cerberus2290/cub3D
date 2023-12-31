/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:04:31 by tstrassb          #+#    #+#             */
/*   Updated: 2023/08/24 11:33:39 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void	spawn_changer(int key, t_data *data)
{
	if (key == UP_KEY)
	{
		data->map->spawn = data->map->spawn->next;
		create_spawn(data);
		create_plane(data, data->map->dir_spawn);
	}
	if (key == DOWN_KEY)
	{
		data->map->spawn = data->map->spawn->prev;
		create_spawn(data);
		create_plane(data, data->map->dir_spawn);
	}
}

int	exit_keys(int key, t_data *data)
{
	if (key == LEFT_KEY)
		data->player->rot = 0;
	if (key == RIGHT_KEY)
		data->player->rot = 0;
	if (key == LEFT_KEY)
		data->player->rot = 0;
	if (key == RIGHT_KEY)
		data->player->rot = 0;
	if (key == W_KEY)
		data->player->de_y = 0;
	if (key == S_KEY)
		data->player->de_y = 0;
	if (key == D_KEY)
		data->player->de_x = 0;
	if (key == A_KEY)
		data->player->de_x = 0;
	return (0);
}

int	handle_keys(int key, t_data *data)
{
	if (key == ESC)
		free_on_exit(data);
	if (key == W_KEY)
		data->player->de_y = 0.07;
	if (key == S_KEY)
		data->player->de_y = -0.07;
	if (key == D_KEY)
		data->player->de_x = 0.07;
	if (key == A_KEY)
		data->player->de_x = -0.07;
	if (key == LEFT_KEY)
		data->player->rot = 0.07;
	if (key == RIGHT_KEY)
		data->player->rot = -0.07;
	spawn_changer(key, data);
	return (0);
}
