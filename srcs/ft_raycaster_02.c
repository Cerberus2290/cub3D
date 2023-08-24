/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycaster_02.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:17:16 by tstrassb          #+#    #+#             */
/*   Updated: 2023/08/23 10:30:13 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void	ft_raycaster(t_data *data)
{
	data->dda->screen_x = 0;
	while (data->dda->screen_x < WINDOW_W)
	{
		dda_calcu(data);
		ft_render(data);
		data->dda->screen_x++;
	}
}
