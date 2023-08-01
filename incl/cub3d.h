/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:33:24 by tstrassb          #+#    #+#             */
/*   Updated: 2023/08/01 13:37:21 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//Definition - includes / standard libs
# ifdef __APPLE__
#  include "../mlx/mlx.h"
# else
#  include "../mlx_linux/mlx.h"
# endif
# include <mlx.h>						//mlx - Library
# include <math.h>					//collection of mathematical functions
# include <stdio.h>					//printf, perror, strerror
# include <unistd.h>					//close
# include <stdlib.h>					//malloc, free
# include "../libft/include/libft.h"	//all functions of libft

# define WINDOW_W 900
# define WINDOW_H 680

typedef struct s_doublell
{
	void				*content;
	struct s_doublell	*next;
	struct s_doublell	*prev;
}	t_doublell;

typedef struct s_items
{
	char	type;
	int		pos_x;
	int		pos_y;
}	t_items;

typedef struct s_files
{
	int		f1;
	int		f2;
	int		f3;
	int		f4;
	int		f5;
	int		f6;
	char	*north;
	char	*east;
	char	*south;
	char	*west;
	char	*f;
	char	*c;
	size_t	map_begin;
	size_t	tab_len;
}	t_files;



#endif