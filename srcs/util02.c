/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:44:30 by tstrassb          #+#    #+#             */
/*   Updated: 2023/08/08 11:06:50 by tstrassb         ###   ########.fr       */
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
