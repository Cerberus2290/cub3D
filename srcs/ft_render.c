/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:28:58 by aputiev           #+#    #+#             */
/*   Updated: 2023/08/30 11:05:24 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

/* draw ceiling / floor */
int	render_vertical_l(t_data *data, int y, int color, int i)
{
	while (i < y)
	{
		ft_mlx_pixel_put(data->imgs[0], data->dda->screen_x, i, color);
		i++;
	}
	return (i);
}

/* calculate pos of pxl of texture */
void	set_texture(t_data *data)
{
	if (data->dda->side == 1 || data->dda->side == 2)
	{
		data->dda->wall_x = data->player->pos_y
			+ data->dda->wall_dist * data->dda->ray_dir_y;
		data->dda->wall_x -= floor(data->dda->wall_x);
		data->dda->text_x = (int)(data->dda->wall_x
				* (double)data->imgs[data->dda->side]->width);
		if (data->dda->ray_dir_x > 0)
			data->dda->text_x = data->imgs[data->dda->side]->width
				- data->dda->text_x - 1;
	}
	else if (data->dda->side == 3 || data->dda->side == 4)
	{
		data->dda->wall_x = data->player->pos_x
			+ data->dda->wall_dist * data->dda->ray_dir_x;
		data->dda->wall_x -= floor(data->dda->wall_x);
		data->dda->text_x = (int)(data->dda->wall_x
				* (double)data->imgs[data->dda->side]->width);
		if (data->dda->ray_dir_y < 0)
			data->dda->text_x = data->imgs[data->dda->side]->width
				- data->dda->text_x - 1;
	}
}

/* calculate color of each pxl */
int	get_pixel(t_imgs *imgs, int x, int y)
{
	int	*dest;
	int	color;

	dest = (void *)imgs->p_img + (y * imgs->s_line + x
			* (imgs->bt / 8));
	color = *(int *)dest;
	return (color);
}

/* render texture */
int	render_texture(t_data *data, int y)
{
	int	i;
	int	color;

	i = 0;
	set_texture(data);
	data->dda->move = 1.0 * data->imgs[data->dda->side]->height / \
		data->dda->line_height;
	data->dda->text_pos = (data->dda->draw_start - WINDOW_H / 2 \
		+ data->dda->line_height / 2) * data->dda->move;
	while (y < data->dda->draw_end - 1)
	{
		data->dda->text_y = (int)data->dda->text_pos & \
			(data->imgs[data->dda->side]->height - 1);
		data->dda->text_pos += data->dda->move;
		color = get_pixel(data->imgs[data->dda->side],
				data->dda->text_x, data->dda->text_pos);
		ft_mlx_pixel_put(data->imgs[0], data->dda->screen_x, y, color);
		y++;
		i++;
	}
	return (i);
}

/* render function */
void	ft_render(t_data *data)
{
	int	i;

	i = 0;
	data->dda->line_height = (int)(WINDOW_H / data->dda->wall_dist);
	data->dda->draw_start = -data->dda->line_height / 2 + WINDOW_H / 2;
	if (data->dda->draw_start < 0)
		data->dda->draw_start = 0;
	data->dda->draw_end = data->dda->line_height / 2 + WINDOW_H / 2;
	if (data->dda->draw_end > WINDOW_H)
		data->dda->draw_end = WINDOW_H - 1;
	i += render_vertical_l(data, data->dda->draw_start, data->map->c, 0);
	i += render_texture(data, i);
	render_vertical_l(data, WINDOW_H, data->map->f, i);
}
