/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites_02_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:00:52 by tstrassb          #+#    #+#             */
/*   Updated: 2023/08/29 11:04:58 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d_bonus.h"

void	sprites_calc(t_data *data, double x, double y)
{
	calculate_sprite_screen_coords(data, x, y);
	set_sprite_stripe(data);
}

void	draw_sprites_calc(t_data *data)
{
	data->sprites->texture_x = (int)(256 * (data->sprites->stripe - \
			(-data->sprites->sprite_width / 2 + data->sprites->spritescreen_x)) \
				* data->imgs[data->time->n_frame]->width / \
		data->sprites->sprite_width) / 256;
}

void	draw_sprites(t_data *data, double x, double y)
{
	int	i;

	frame_timer(data, x, y);
	sprites_calc(data, x, y);
	while (++data->sprites->stripe < data->sprites->draw_end_x)
	{
		draw_sprites_calc(data);
		if (data->sprites->transf_y > 0 && data->sprites->stripe > 0 && \
			data->sprites->stripe < WINDOW_W && data->sprites->transf_y \
			< data->sprites->buffer[data->sprites->stripe])
		{
			y = data->sprites->draw_start_y;
			while (++y < data->sprites->draw_end_y)
			{
				i = (y - data->sprites->v_movescreen) * 256 - WINDOW_H \
					* 128 + data->sprites->sprite_height * 128;
				data->sprites->texture_y = ((i * \
					data->imgs[data->time->n_frame]->height) / \
						data->sprites->sprite_height) / 256;
				create_sprite(data, y);
			}
		}
	}
}

void	render_sprites(t_data *data)
{
	t_list	*temp;
	t_items	*content;

	temp = data->map->item;
	while (temp)
	{
		content = (t_items *)temp->content;
		if (content->pos_y == (int)data->player->pos_x && \
			content->pos_x == (int)data->player->pos_y)
		{
			data->n_taken++;
			content->pos_x = -1;
			content->pos_y = -1;
			data->map->map[(int)data->player->pos_x] \
			[(int)data->player->pos_y] = '0';
		}
		if (!(content->pos_x == -1 && content->pos_y == -1))
			draw_sprites(data, ((double)(content)->pos_y) + \
				0.5, (double)(content)->pos_x + 0.5);
		temp = temp->next;
	}
}
