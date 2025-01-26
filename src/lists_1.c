/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:12:38 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/01/25 22:54:11 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int_lst	*ps_lstnew(int val)
{
	int_lst	*ret;

	ret = (int_lst *)malloc(sizeof(int));
	if (!ret)
		return (NULL);
	ret->value = val;
	ret->next = NULL;
	return (ret);
}

int_lst	*ps_lst_last(int_lst *lst)
{
	while (lst && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ps_lst_add_back(int_lst **lst, int_lst *new)
{
	int_lst	*temp;

	if (!*lst)
		*lst = new;
	else
	{
		temp = ps_lst_last(*lst);
		temp->next = new;
	}
}

void	ps_lst_add_front(int_lst **lst, int_lst *new)
{
	if (!*lst)
		*lst = new;
	else
	{
		new->next = *lst;
		*lst = new;
	}
}

void	ps_lst_clear(int_lst **lst)
{
	int_lst	*nxt;

	while (*lst)
	{
		nxt = (*lst)->next;
		free(*lst);
		*lst = nxt;
	}
}
