/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 10:02:17 by tstrassb          #+#    #+#             */
/*   Updated: 2023/08/09 10:02:17 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	t_map	*map;

	if (argc != 2)
		return (write_error("error: syntax: use: ./cub3d [maps/<map>.cub]\n"));
	data = malloc(sizeof(t_data));
	if (!data)
		exit(write_error("error: malloc: failed to allocate memory\n"));
	data->mlx = mlx_init();
	-init_data-;
	-init_map-;
	if (parsing_map(data, &map, argv))
		-free_on_exit(data)-;
}
