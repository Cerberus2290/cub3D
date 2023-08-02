/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublelst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:15:32 by tstrassb          #+#    #+#             */
/*   Updated: 2023/08/02 17:15:32 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

t_list	*ft_lstnew(void *cont)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (0);
	lst->content = cont;
	lst->next = NULL;
	return (lst);
}

t_doublell	*doublelst_new(void *cont)
{
	t_doublell	*lst;

	lst = malloc(sizeof(t_doublell));
	if (!lst)
		return (0);
	lst->next = lst;
	lst->prev = lst;
	lst->content = cont;
	return (lst);
}

void	doublelst_addback(t_doublell **lst, t_doublell *new)
{
	t_doublell	*temp;

	if (!(*lst))
		*lst = new;
	else
	{
		temp = (*lst)->prev;
		temp->next = new;
		new->prev = temp;
		new->next = (*lst);
		(*lst)->prev = new;
	}
}
