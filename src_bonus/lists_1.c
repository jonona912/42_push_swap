/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:12:38 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/01/27 20:15:32 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_ps_lst	*ps_lstnew(int val)
{
	t_ps_lst	*ret;

	ret = (t_ps_lst *)malloc(sizeof(int));
	if (!ret)
		return (NULL);
	ret->value = val;
	ret->next = NULL;
	return (ret);
}

t_ps_lst	*ps_lst_last(t_ps_lst *lst)
{
	while (lst && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ps_lst_add_back(t_ps_lst **lst, t_ps_lst *new)
{
	t_ps_lst	*temp;

	if (!*lst)
		*lst = new;
	else
	{
		temp = ps_lst_last(*lst);
		temp->next = new;
	}
}

void	ps_lst_add_front(t_ps_lst **lst, t_ps_lst *new)
{
	if (!*lst)
		*lst = new;
	else
	{
		new->next = *lst;
		*lst = new;
	}
}

void	ps_lst_clear(t_ps_lst **lst)
{
	t_ps_lst	*nxt;

	while (*lst)
	{
		nxt = (*lst)->next;
		free(*lst);
		*lst = nxt;
	}
}
