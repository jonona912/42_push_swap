/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_lst_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 23:59:27 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/01/27 20:23:13 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	divide_list(t_ps_lst **lst, t_ps_lst **half2, int mid)
{
	t_ps_lst	*current;
	int			i;

	if (mid < 2)
		return (0);
	if (!lst || !*lst || !(*lst)->next)
		return (0);
	current = *lst;
	i = 1;
	while (i < mid && current && current->next)
	{
		current = current->next;
		i++;
	}
	*half2 = current->next;
	current->next = NULL;
	return (1);
}

int	copy_lst(t_ps_lst **new_lst, t_ps_lst *lst)
{
	t_ps_lst	*new_node;

	if (!lst)
		return (0);
	while (lst)
	{
		new_node = ps_lstnew(lst->value);
		ps_lst_add_back(new_lst, new_node);
		lst = lst->next;
	}
	return (1);
}

int	copy_values(t_ps_lst	**sorted, t_ps_lst **cp1)
{
	t_ps_lst	*node1;

	node1 = *cp1;
	*cp1 = (*cp1)->next;
	node1->next = NULL;
	ps_lst_add_back(sorted, node1);
	return (1);
}

int	ft_merge(t_ps_lst **half1, t_ps_lst **half2)
{
	t_ps_lst	*sorted;

	sorted = NULL;
	while ((*half1) && (*half2))
	{
		if ((*half1)->value <= (*half2)->value)
			copy_values(&sorted, half1);
		else
			copy_values(&sorted, half2);
	}
	while (*half1)
		copy_values(&sorted, half1);
	while (*half2)
		copy_values(&sorted, half2);
	*half1 = sorted;
	return (1);
}
