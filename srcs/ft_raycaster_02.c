/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycaster_02.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:17:16 by tstrassb          #+#    #+#             */
/*   Updated: 2023/08/28 15:14:27 by aputiev          ###   ########.fr       */
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
