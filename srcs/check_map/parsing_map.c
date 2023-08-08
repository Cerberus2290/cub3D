/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:02:05 by tstrassb          #+#    #+#             */
/*   Updated: 2023/08/08 15:42:58 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

/*goes through the input string until it finds '.'
 * checks if file extension ends in ".cub"*/
int	extension_cub(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	while (i && str[i] != '.')
		i--;
	if (!i || ft_strncmp(".cub", &str[i], 4))
		exit(write_error("Error\nMap file must end in [.cub]\n"));
	return (0);
}

/*confirms that the required texture paths
 * ("NO", "EA", etc.) and color elements ("F", "C") are correctly specified*/
int	all_face(t_files *files)
{
	if (!files->f1 || !files->f2 || !files->f3
		|| !files->f4 || !files->f5 || !files->f6)
	{
		ft_free(files->north, files->east, files-> south, files->west);
		ft_free(files->c, files->f, files, 0);
		return (1);
	}
	return (0);
}

/*main function responsible for parsing the data
 * necessary to create the entire map*/
int	parse_map(t_map *map, t_files *files, char **argv)
{
	char	**tab;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit(write_error("Error\nCould not open map file\n"));
	if (get_cub(fd, &tab))
	{
		ft_free(files->north, files->east, files->south, files->west);
		return (ft_free(files->c, files->f, files, 0));
	}
	close(fd);
	if (element_map(files, tab))
		return (free_tab(tab, 1));
	if (all_face(files))
		return (free_tab(tab, 1));
	if (take_cub(files, map, tab))
		return (free_tab(tab, 1));
	if (check_cub(map))
	{
		ft_free(files->north, files->east, files->south, files->west);
		ft_free(files->c, files->f, files, 0);
		return (free_tab(tab, 1));
	}
	return (free_tab(tab, 0));
}

int	file_convert(t_data *data, t_map *map, t_files *files)
{
	texture_init(data, 1, files->north);
	texture_init(data, 2, files->east);
	texture_init(data, 3, files->south);
	texture_init(data, 4, files->west);
	ft_free(files->north, files->east, files->south, files->west);
	texture_init(data, 5, "./resources/texture1.xpm");
	/*texture_init(data, ..., "./resources/...");*/
	if (convert_color(&map->f, files->f) || convert_color(&map->c, files->c))
		exit(write_error("Error\nColor error\n"));
	ft_free(files->c, files->f, files, 0);
	return (0);
}

/*higher-level function responsible for the parsing and data conversion*/
int	parsing_map(t_data *data, t_map *map, char **argv)
{
	t_files	*files;

	files = malloc(sizeof(t_files));
	if (!files)
		return (1);
	if (extension_cub(argv[1]))
		return (ft_free(files, 0, 0, 0));
	init_struct(files, map);
	if (parse_map(map, files, argv))
		return (1);
	if (file_convert(data, map, files))
		return (1);
	return (0);
}
