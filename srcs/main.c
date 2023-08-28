/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 10:02:17 by tstrassb          #+#    #+#             */
/*   Updated: 2023/08/28 15:06:47 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

int	start_game(t_data *data)
{
	update_param(data, data->player->rot);
	ft_raycaster(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->p_img, 0, 0);
	return (0);
}

void	init_map(t_map *map, t_data *data)
{
	map->spawn = 0;
	map->item = 0;
	data->time->start = clock();
	data->time->n_frame = 6;
	data->map = map;
	data->time->tmp = 1;
	data->player->total_rots = 0;
	data->n_taken = 0;
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_map	map;

	if (argc != 2)
		return (write_error("error: syntax:\n use: ./cub3d maps/<map>.cub\n"));
	data = malloc(sizeof(t_data));
	if (!data)
		exit(write_error("error: malloc:\n failed to allocate memory\n"));
	data->mlx = mlx_init();
	if (init_data(data))
		return (1);
	init_map(&map, data);
	if (parsing_map(data, &map, argv))
		free_on_exit(data);
	mlx_mouse_move(data->mlx_win, WINDOW_W / 2, WINDOW_H / 2);
	data->n_sprites = ft_lstsize(data->map->item);
	create_spawn(data);
	create_plane(data, data->map->dir_spawn);
	mlx_mouse_hide();
	mlx_do_key_autorepeaton(data->mlx);
	mlx_hook(data->mlx_win, 2, 0, handle_keys, data);
	mlx_hook(data->mlx_win, 3, 0, exit_keys, data);
	mlx_hook(data->mlx_win, 17, 0, free_on_exit, data);
	mlx_loop_hook(data->mlx, start_game, data);
	mlx_loop(data->mlx);
}
