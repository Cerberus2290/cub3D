/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:37:07 by tstrassb          #+#    #+#             */
/*   Updated: 2023/08/09 11:37:07 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

/*initializes the t_player structure within the t_data structure*/
void	init_player(t_data *data)
{
	data->player->de_x = 0;
	data->player->de_y = 0;
	data->player->dir_x = 0;
	data->player->dir_y = 0;
	data->player->player_x = 0;
	data->player->player_y = 0;
	data->player->rot = 0;
	data->player->total_rots = 0;
}

/*initializes various components and structures within t_data structure*/
int	init_data(t_data *data)
{
	int	i;

	i = 0;
	data->mlx_win = mlx_new_window(data->mlx, WINDOW_W, WINDOW_H, "cub3d");
	data->p_img = mlx_new_image(data->mlx, WINDOW_W, WINDOW_H);
	data->player = malloc(sizeof(t_player));
	data->dda = malloc(sizeof(t_dda));
	data->time = malloc(sizeof(t_time));
	data->imgs = malloc(sizeof(t_imgs));
	if (!data->mlx || !data->mlx_win || !data->player
		|| !data->dda || !data->time || !data->imgs)
		return (1);
	while (i <= 16)
	{
		data->imgs[i] = malloc(sizeof(t_imgs));
		if (!data->imgs[i])
			return (1);
		i++;
	}
	data->sprites = malloc(sizeof(t_sprites));
	data->sprites->buffer = malloc(sizeof(double) * (WINDOW_W) + 1);
	data->imgs[0]->p_img = mlx_get_data_addr(data->p_img, &data->imgs[0]->bt, \
		&data->imgs[0]->s_line, &data->imgs[0]->endian);
	return (0);
}
