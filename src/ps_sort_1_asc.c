/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_1_asc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:14:48 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/01/24 11:24:32 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	double_swapped(int_lst **st_a, int_lst **st_b)
{
	int	a1;
	int	a2;
	int	b1;
	int	b2;

	if (*st_b && (*st_a)->next && (*st_b)->next)
	{
		a1 = (*st_a)->value;
		a2 = (*st_a)->next->value;
		b1 = (*st_b)->value;
		b2 = (*st_b)->next->value;
		if ((a1 > a2) && (b1 < b2));
		{
			ss(st_a, st_b, PRINT);
			return (1);
		}
	}
	return (0);
}

int	sort_needed_asc(int_lst **st_a, int_lst **st_b, int len)
{
	if (len == 1)
		return (0);
	if (qs_is_sorted(*st_a, ASC, len)) // 1 2 3
		return (0);
	if (len == 2)
	{
		if ((*st_a)->value > (*st_a)->next->value)
		{
			if (!double_swapped(st_a, st_b))
				swap_x(st_a, 'a', PRINT);
		}
		return (0);
	}
	return (1);
}

int_lst	*sort_3_null_asc(int_lst **st_a, int_lst **st_b)
{
	int		ft;
	int		sd;
	int		td;

	ft = (*st_a)->value;
	sd = (*st_a)->next->value;
	td = (*st_a)->next->next->value;
	if (ft < sd && sd > td && ft > td) // 2 3 1
		rev_rotate_x(st_a, 'a', PRINT);
	else if (ft > sd && sd > td) // 3 2 1 same operations as 1 2 3
	{
		rotate_x(st_a, 'a', PRINT);
		if (!double_swapped(st_a, st_b))
			swap_x(st_a, 'a', PRINT);
	}
	else if (ft > sd && ft < td) // 2 1 3
		return (swap_x(st_a, 's', PRINT));
	else if (ft > sd && ft > td && sd < td) // 3 1 2
		rotate_x(st_a, 'a', PRINT);
	else if (ft < sd && ft < td && sd > td) // 1 3 2
	{
		if (!double_swapped(st_a, st_b))
			swap_x(st_a, 'a', PRINT);
		rotate_x(st_a, 'a', PRINT);
	}
	return (*st_a);
}

int_lst	*sort_3_asc(int_lst **st_a, int_lst **st_b)
{
	int		ft;
	int		sd;
	int		td;

	ft = (*st_a)->value;
	sd = (*st_a)->next->value;
	td = (*st_a)->next->next->value;
	if (ft < sd && sd > td && ft > td) // 2 3 1
	{
		push_x(st_a, st_b, 'b', PRINT);
		swap_x(st_a, 'a', PRINT);
		push_x(st_b, st_a, 'a', PRINT);
		if (!double_swapped(st_a, st_b))
			swap_x(st_a, 'a', PRINT);
	}
	else if (ft > sd && sd > td) // 3 2 1 same operations as 1 2 3
	{
		if (!double_swapped(st_a, st_b))
			swap_x(st_a, 'a', PRINT);
		push_x(st_a, st_b, 'b', PRINT);
		swap_x(st_a, 'a', PRINT);
		push_x(st_b, st_a, 'a', PRINT);
		swap_x(st_b, 'b', PRINT);
	}
	else if (ft > sd && ft < td) // 2 1 3
	{
		if (!double_swapped(st_a, st_b))
			swap_x(st_a, 'a', PRINT);
	}
	else if (ft > sd && ft > td && sd < td) // 3 1 2
	{
		if (!double_swapped(st_a, st_b))
			swap_x(st_a, 'a', PRINT);
		push_x(st_a, st_b, 'b', PRINT);
		swap_x(st_a, 'a', PRINT);
		push_x(st_b, st_a, 'a', PRINT);
	}
	else if (ft < sd && ft < td && sd > td) // 1 3 2
	{
		push_x(st_a, st_b, 'b', PRINT);
		swap_x(st_a, 'a', PRINT);
		push_x(st_b, st_a, 'a', PRINT);
	}
	return (*st_a);
}

int_lst	*sort_asc(int_lst **st_a, int_lst **st_b, int len)
{
	// int_lst	*st_b;

	int		lst_len;
	// st_b = NULL;
	if (!sort_needed_asc(st_a, st_b, len))
		return (*st_a);
	lst_len = ps_lst_len(*st_a);
	if (lst_len == 3)
	{
		sort_3_null_asc(st_a, st_b);
		return (*st_a);
	}
	else
		return (sort_3_asc(st_a, st_b));
}
