/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:49:18 by aputiev           #+#    #+#             */
/*   Updated: 2023/08/28 13:47:22 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d_bonus.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void draw_back_layer(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < 200)
	{
		j = 0;
		while (j < 200)
		{
			if(i < 20 || j < 20 || i > 179 || j > 179)
				ft_mlx_pixel_put(data->imgs[0], i, j, create_trgb(255, 255, 255, 255));
			else
				ft_mlx_pixel_put(data->imgs[0], i, j, create_trgb(0, 255, 255, 255));
			j++;
		}
		i++;
	}
}

int	draw_square(t_data *data, int x, int y, uint32_t color)
{
	int i;
	int j;

	i = 0;
	while (i < 20)
	{
		j = 0;
		while (j < 20)
		{
			ft_mlx_pixel_put(data->imgs[0], x + i, y + j, color);
			j++;
		}
		i++;
	}
	return (0);
}

size_t	ft_strstrlen(char **str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

void ft_minimap(t_data *data)
{
	int	i = 0;
	int j;

	draw_back_layer(data);
	draw_square(data, 90, 90, create_trgb(0, 0, 255, 0));
	
	//while (i < (int)ft_strstrlen(data->map->map))
	
	//////////////////////////////
	// while (data->map->map[i])
	// {
	// 	j = 0;
	// 	while (data->map->map[i][j])
	// 	{
	// 		printf("%c", data->map->map[i][j]);
	// 		j++;			
	// 	}
	// 	printf("\n");
	// 	i++;	
	// }
	// printf("========================================\n");
	///////////////////////////////////

	
	while (data->map->map[i])
	{
		j = 0;
		//while (j < (int)ft_strlen(data->map->map[i]) - 1)
		while (data->map->map[i][j])
		{
			//printf("========1\n");
			if(data->player->pos_x - j < 5 && (int)data->player->pos_x - j > -4 && (int)data->player->pos_y - i< 5 && (int)data->player->pos_y - i > -4)
			{
				//printf("========2\n");
				//printf("data->map->map[%d][%d]\n", j, i);
				if(data->map->map[j][i] == '1' || data->map->map[j][i] == 'D' || data->map->map[j][i] == 'B')
				{
					//printf("========3\n");                   
					//printf("Are we here?\n");
					draw_square(data, 100 - ((int)data->player->pos_y - i) * 20, 100 - ((int)data->player->pos_x - j) * 20, (create_trgb(0,255,0,0)));
				}
			}
			j++;
		}
		i++;
	}

}