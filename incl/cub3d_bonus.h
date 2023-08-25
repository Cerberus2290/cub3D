/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:38:32 by tstrassb          #+#    #+#             */
/*   Updated: 2023/08/25 15:18:44 by tstrassb         ###   ########.fr       */
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

#endif