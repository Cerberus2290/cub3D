/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:11:39 by tstrassb          #+#    #+#             */
/*   Updated: 2023/08/07 15:11:39 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

int	convert_color(int *color, char *str)
{
	unsigned int	rgb[3];
	size_t			i;
	char			**tab;

	if (check_str_color(str))
		return (1);
	tab = split_color(str);
	if (tab == 0)
		exit(write_error("Error\nmalloc_failed\n"));
	i = -1;
	while (tab[++i])
		rgb[i] = ft_atoi(tab[i]);
	i = 0;
	*color = 0;
	while (i < 3)
		if (ft_rgb(color, rgb, i++))
			return (ft_free(tab[0], tab[1], tab[2], tab));
	ft_free(tab[0], tab[1], tab[2], tab);
	return (0);
}
