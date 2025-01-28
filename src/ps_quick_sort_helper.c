/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick_sort_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:00:03 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/01/27 20:27:35 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_for_less(t_ps_lst *lst, int num)
{
	while (lst)
	{
		if (lst->value < num)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	check_for_great_eq(t_ps_lst *lst, int num)
{
	while (lst)
	{
		if (lst->value >= num)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	is_sorted_beyond(t_ps_lst *lst, int len)
{
	int	i;

	i = 0;
	while (i < len && lst)
	{
		i++;
		lst = lst->next;
	}
	if (!lst)
		return (0);
	if (is_sorted(lst, ASC))
		return (1);
	return (0);
}

t_ps_lst	*find_max_beyond_len(t_ps_lst *lst, int len)
{
	int			i;
	t_ps_lst	*max_nd;

	i = 0;
	while (i < len && lst)
	{
		lst = lst->next;
		i++;
	}
	if (!lst)
		return (NULL);
	max_nd = lst;
	while (lst)
	{
		if (lst->value > max_nd->value)
			max_nd = lst;
		lst = lst->next;
	}
	return (max_nd);
}

int	find_bigger_num(t_ps_lst *lst, int len, t_ps_lst *max_nd)
{
	int	i;
	int	max;

	i = 0;
	max = max_nd->value;
	while (i < len && lst)
	{
		lst = lst->next;
		i++;
	}
	if (!lst)
		return (0);
	while (lst)
	{
		if (lst->value > max)
			return (1);
		lst = lst->next;
	}
	return (0);
}
