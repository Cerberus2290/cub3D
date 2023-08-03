/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:33:24 by tstrassb          #+#    #+#             */
/*   Updated: 2023/08/03 15:07:37 by tstrassb         ###   ########.fr       */
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
# include <math.h>						//collection of mathematical functions
# include <stdio.h>						//printf, perror, strerror
# include <fcntl.h>						//open
# include <unistd.h>					//close
# include <stdlib.h>					//malloc, free
# include <time.h>
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

typedef struct l_sprites
{
	int		texture_x;
	int		texture_y;
	int		stripe;
	double	*buffer;
	double	invdent;
	double	transf_x;
	double	transf_y;
	int		v_movescreen;
	int		spritescreen_x;
	int		draw_start_y;
	int		draw_end_y;
	int		sprite_width;
	int		draw_start_x;
	int		draw_end_x;
}	t_sprites;

typedef struct l_time
{
	clock_t	start;
	int		n_frame;
	int		tmp;
}	t_time;

typedef struct l_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	player_x;
	double	player_y;
	double	rot;
	double	de_x;
	double	de_y;
	double	total_rots;
}	t_player;

typedef struct l_dda
{
	int		screen_x;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		text_x;
	int		text_y;
	double	cam_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	wall_dist;
	double	wall_x;
	double	step;
	double	text_pos;
}	t_dda;

typedef struct l_imgs
{
	int		width;
	int		height;
	int		bt;
	int		s_line;
	int		endian;
	char	*p_img;
}	t_imgs;

typedef struct l_map
{
	void		*north;
	void		*south;
	void		*east;
	void		*west;

	size_t		map_len;
	char		**map;

	int			f;
	int			c;
	t_doublell	*spawn;
	t_list		*item;

	char		dir_spawn;
}	t_map;

typedef struct l_data_mlx
{
	void		*mlx;
	void		*mlx_win;
	void		*p_img;
	float		x_0;
	float		x_1;
	float		y_0;
	float		y_1;
	int			n_taken;
	int			n_sprites;
	t_sprites	*sprites;
	t_time		*time;
	t_imgs		*imgs;
	t_map		*map;
	t_player	*player;
	t_dda		*dda;
}	t_data;

/* Functions of cub3d */

//check_map

int			get_cub(int fd, char ***tab);
int			write_error(char *str);
int			is_printable(char *str);
int			is_spawn(char c);
int			within_map(char c);
int			is_map(char c);
int			element_map(t_files *files, char **tab);
int			check_cub(t_map *map);

//

char		*ft_free_join(char const *s1, char const *s2, int i);
char		**split01(char const *str, char c);
int			free_tab(char **tab, int ret);
int			ft_free(void *s1, void *s2, void *s3, void *s4);
t_list		*ft_lstnew(void *cont);
t_doublell	*doublelst_new(void *cont);
void		doublelst_addback(t_doublell **lst, t_doublell *new);
void		init_struct(t_files *files, t_map *map);

#endif