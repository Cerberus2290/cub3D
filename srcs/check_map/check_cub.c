/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:08:32 by tstrassb          #+#    #+#             */
/*   Updated: 2023/08/02 17:08:32 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

int	add_item(t_map *map, int x, int y)
{
	t_items		*item;
	t_doublell	*temp;

	item = malloc(sizeof(t_items));
	if (!item)
		return (1);
	item->type = map->map[y][x];
	item->pos_x = x;
	item->pos_y = y;
	if (is_spawn(map->map[y][x]))
	{
		temp = doublelst_new(item);
		if (!temp)
			return (1);
		doublelst_addback(&map->spawn, temp);
	}
	return (0);
}

int	checking(t_map *map, size_t *map_len)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (within_map(map->map[y][x]) && !(x && is_map(map->map[y][x - 1])
			&& map->map[y][x + 1] && is_map(map->map[y][x + 1])
			&& y && map_len[y - 1] >= x + 1 && is_map(map->map[y - 1][x - 1])
			&& is_map(map->map[y - 1][x]) && is_map(map->map[y - 1][x + 1])
			&& map->map[y + 1] && map_len[y + 1] >= x
			&& is_map(map->map[y + 1][x - 1])
			&& is_map(map->map[y + 1][x]) && is_map(map->map[y + 1][x + 1])))
				return (write_error("Error\nMap is not closed\n"));
			if (is_spawn(map->map[y][x]))
				if (add_item(map, x, y))
					return (1);
			x++;
		}
		y++;
	}
	return (0);
}