/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:53:14 by tstrassb          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/08/29 17:17:31 by aputiev          ###   ########.fr       */
=======
/*   Updated: 2023/08/29 14:20:19 by tstrassb         ###   ########.fr       */
>>>>>>> 07c3aa1cded6422bcd7216a0c68d176777a86d17
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

static int	ft_count_words(const char *str, char c)
{
	int	count;
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c && flag == 0)
			flag = 1;
		else if (str[i] == c && flag == 1)
			count++;
		else if (str[i] != c && flag == 1)
		{
			count++;
			flag = 0;
		}
		i++;
	}
	return (count);
}

void	init(int *i, int *count, int *start, int *flag)
{
	*i = 0;
	*count = 0;
	*start = 0;
	*flag = 0;
}

static void	create02(const char *s, char c, int *i, int *flag)
{
	if (s[*i] == c)
		(*i)++;
	else if (s[*i] && s[*i] != c)
	{
		while (s[*i] && s[*i] != c)
			(*i)++;
		*flag = 0;
	}
}

static char	**ft_create_tab(char **tab, const char *str, char c)
{
	int	count;
	int	i;
	int	start;
	int	flag;

	init(&count, &i, &start, &flag);
	while (str[i])
	{
		if (str[i] == c && flag == 0 && ++flag)
			start = ++i;
		else if (str[i] && (flag || str[i] != c))
		{
			create02(str, c, &i, &flag);
			tab[count] = ft_substr(str, start, i - start);
			if (!tab[count++])
			{
				free_tab(tab, 0);
				return (0);
			}
			start = i;
		}
	}
	tab[count] = NULL;
	return (tab);
}

char	**split01(char const *str, char c)
{
	char	**tab;

	if (!str)
		return (0);
	tab = malloc(sizeof(char *) * (ft_count_words(str, c) + 2));
	if (!tab)
		return (NULL);
	return (ft_create_tab(tab, str, c));
}
