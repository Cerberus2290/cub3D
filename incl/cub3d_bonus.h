/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:38:32 by tstrassb          #+#    #+#             */
/*   Updated: 2023/08/29 09:13:47 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "cub3d.h"

int		ft_isitem(char c);
int		ft_isdoor(char c);
int		ft_mouse_movement(t_data *data);
void	check_dist(t_data *data);
void	check_side(t_data *data);
void	render_sprites(t_data *data);
void	ft_minimap(t_data *data);
int		create_trgb(int t, int r, int g, int b);
int		draw_square(t_data *data, int x, int y, uint32_t color);
void	draw_back_layer(t_data *data);
void	create_sprite(t_data *data, int y);
void	frame_timer(t_data *data, double x, double y);
void	calculate_sprite_screen_coords(t_data *data, double x, double y);
void	set_sprite_stripe(t_data *data);

#endif