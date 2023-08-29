/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:19:17 by tstrassb          #+#    #+#             */
/*   Updated: 2023/08/29 08:53:48 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d_bonus.h"

void	create_sprite(t_data *data, int y)
{
	int	i;
	int	j;

	j = data->imgs[data->time->n_frame]->s_line * data->sprites->texture_y
		+ data->sprites->texture_x * data->imgs[data->time->n_frame]->bt / 8;
	if (data->imgs[data->time->n_frame]->p_img[j] == 0 && \
		data->imgs[data->time->n_frame]->p_img[j + 1] == 0 && \
		data->imgs[data->time->n_frame]->p_img[j + 2] == 0)
		return ;
	i = data->sprites->stripe * data->imgs[0]->bt
		/ 8 + data->imgs[0]->s_line * y;
	data->imgs[0]->p_img[i] = data->imgs[data->time->n_frame]->p_img[j];
	data->imgs[0]->p_img[++i] = data->imgs[data->time->n_frame]->p_img[++j];
	data->imgs[0]->p_img[++i] = data->imgs[data->time->n_frame]->p_img[++j];
}

void	frame_timer(t_data *data, double x, double y)
{
	clock_t	end;
	double	time;

	end = clock();
	time = (double)(end - data->time->start) / CLOCKS_PER_SEC;
	if (data->time->n_frame == 12)
		data->time->n_frame = 6;
	if ((int)(ceil(time)) % 1 == 0 && data->time->n_frame != 12)
	{
		if (data->time->tmp != (int)(ceil(time)))
		{
			data->time->n_frame++;
			data->time->tmp = (int)(ceil(time));
		}
	}
	data->sprites->invdent = 1.0 / (data->player->player_x \
		* data->player->dir_y - data->player->dir_x * data->player->player_y);
	data->sprites->transf_x = (1.0 / (data->player->player_x \
		* data->player->dir_y - data->player->dir_x * data->player->player_y)) \
		* (data->player->dir_y * (x - data->player->pos_x) \
		- data->player->dir_x * (y - data->player->pos_y));
}

void	calculate_sprite_dimensions(t_data *data)
{
	data->sprites->sprite_height = \
		abs((int)(WINDOW_H / (data->sprites->transf_y))) / 3;
	data->sprites->draw_start_y = \
		-data->sprites->sprite_height / 2 \
		+ WINDOW_H / 2 + data->sprites->v_movescreen;
	if (data->sprites->draw_start_y < 0)
		data->sprites->draw_start_y = 0;
	data->sprites->draw_end_y = \
		data->sprites->sprite_height / 2 \
		+ WINDOW_H / 2 + data->sprites->v_movescreen;
	if (data->sprites->draw_end_y >= WINDOW_H)
		data->sprites->draw_end_y = WINDOW_H - 1;
	data->sprites->sprite_width = \
		abs((int)(WINDOW_H / (data->sprites->transf_y))) / 3;
	data->sprites->draw_start_x = \
		-data->sprites->sprite_width / 2 + data->sprites->spritescreen_x;
	if (data->sprites->draw_start_x < 0)
		data->sprites->draw_start_x = 0;
	data->sprites->draw_end_x = \
		data->sprites->sprite_width / 2 + data->sprites->spritescreen_x;
	if (data->sprites->draw_end_x >= WINDOW_W)
		data->sprites->draw_end_x = WINDOW_W - 1;
}

void	calculate_sprite_screen_coords(t_data *data, double x, double y)
{
	data->sprites->transf_y = \
		(1.0 / (data->player->player_x * data->player->dir_y - \
			data->player->dir_x * data->player->player_y)) * \
			(-data->player->player_y * (x - data->player->pos_x) + \
				data->player->player_x * (y - data->player->pos_y));
	data->sprites->v_movescreen = 120 / data->sprites->transf_y;
	data->sprites->spritescreen_x = \
		(int)((WINDOW_W / 2) * (1 + data->sprites->transf_x / \
			data->sprites->transf_y));
	calculate_sprite_dimensions(data);
}

void	set_sprite_stripe(t_data *data)
{
	data->sprites->stripe = data->sprites->draw_start_x;
}
