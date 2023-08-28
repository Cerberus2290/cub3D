/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:19:17 by tstrassb          #+#    #+#             */
/*   Updated: 2023/08/28 14:58:48 by tstrassb         ###   ########.fr       */
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
	data->sprites->invdent = 1.0 / (data->player->player_x * data->player->dir_y - \
		data->player->dir_x * data->player->player_y);
	data->sprites->transf_x = (1.0 / (data->player->player_x * data->player->dir_y - \
		data->player->dir_x * data->player->player_y)) * (data->player->dir_y * \
			(x - data->player->pos_x) - data->player->dir_x * (y - data->player->pos_y));
}

void	sprites_calc(t_data *data, double x, double y)
{
	data->sprites->transf_y = (1.0 / (data->player->player_x * data->player->dir_y - data->player->dir_x \
		* data->player->player_y)) * (-data->player->player_y * (x - data->player->pos_x) \
			+ data->player->player_x * (y - data->player->pos_y));
	data->sprites->v_movescreen = 120 / data->sprites->transf_y;
	data->sprites->spritescreen_x = (int)((WINDOW_W / 2) * \
		(1 + data->sprites->transf_x / data->sprites->transf_y));
	data->sprites->sprite_height = abs((int)(WINDOW_H / (data->sprites->transf_y))) / 3;
	data->sprites->draw_start_y = -data->sprites->sprite_height / 2 + \
		WINDOW_H / 2 + data->sprites->v_movescreen;
	if (data->sprites->draw_start_y < 0)
		data->sprites->draw_start_y = 0;
	data->sprites->draw_end_y = data->sprites->sprite_height / 2 + \
		WINDOW_H / 2 + data->sprites->v_movescreen;
	if (data->sprites->draw_end_y >= WINDOW_H)
		data->sprites->draw_end_y = WINDOW_H - 1;
	data->sprites->sprite_width = abs((int)(WINDOW_H / (data->sprites->transf_y))) / 3;
	data->sprites->draw_start_x = -data->sprites->sprite_width / 2 + data->sprites->spritescreen_x;
	if (data->sprites->draw_start_x < 0)
		data->sprites->draw_start_x = 0;
	data->sprites->draw_end_x = data->sprites->sprite_width / 2 + data->sprites->spritescreen_x;
	if (data->sprites->draw_end_x >= WINDOW_W)
		data->sprites->draw_end_x = WINDOW_W - 1;
	data->sprites->stripe = data->sprites->draw_start_x;
}

void	draw_sprites(t_data *data, double x, double y)
{
	int	i;

	frame_timer(data, x, y);
	sprites_calc(data, x, y);
	while (++data->sprites->stripe < data->sprites->draw_end_x)
	{
		data->sprites->texture_x = (int)(256 * (data->sprites->stripe - \
			(-data->sprites->sprite_width / 2 + data->sprites->spritescreen_x)) \
				* data->imgs[data->time->n_frame]->width / \
		data->sprites->sprite_width) / 256;
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
			data->map->map[content->pos_x][content->pos_y] = '0';
		}
		if (!(content->pos_x == -1 && content->pos_y == -1))
			draw_sprites(data, ((double)(content)->pos_y) + \
				0.5, (double)(content)->pos_x + 0.5);
		temp = temp->next;
	}
}
