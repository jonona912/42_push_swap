/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick_sort_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:29:32 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/01/27 11:36:57 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	qs_copy_lst(int_lst **new_lst, int_lst *lst, int len)
{
	int_lst	*new_node;
	int		i;

	i = 0;
	if (!lst)
		return (0);
	while (i < len && lst)
	{
		new_node = ps_lstnew(lst->value);
		ps_lst_add_back(new_lst, new_node);
		lst = lst->next;
		i++;
	}
	return (1);
}

int	qs_find_median(int_lst *head, int len)
{
	int_lst	*median;
	int_lst	*lst_copy;
	int_lst	*sorted;
	int		ret;

	lst_copy = NULL;
	if (!head)
		return (0);
	qs_copy_lst(&lst_copy, head, len);
	sorted = merge_sort_lst(lst_copy);
	median = split_lst(sorted);
	ret = median->value;
	ps_lst_clear(&sorted);
	ps_lst_clear(&median);
	return (ret);
}

int_lst	*ps_merge(int_lst **lst_b, int_lst **lst_a, int len, char c)
{
	int	i;

	i = 0;
	while (i < len && *lst_b)
	{
		push_x(lst_b, lst_a, c, PRINT);
		i++;
	}
	return (*lst_a);
}

int	is_stack_b_rot(int_lst *lst)
{
	int		first;
	int_lst	*last_nd;

	if (!lst || !lst->next)
		return (0);
	first = lst->value;
	last_nd = ps_lst_last(lst);
	if (first < last_nd->value)
		return (1);
	return (0);
}
