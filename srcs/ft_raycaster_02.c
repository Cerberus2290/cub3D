/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycaster_02.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:28:42 by aputiev           #+#    #+#             */
/*   Updated: 2023/08/30 10:47:59 by aputiev          ###   ########.fr       */
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
