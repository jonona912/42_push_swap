/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_2_desc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:57:14 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/01/21 21:27:31 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	sort_needed_desc(int_lst **st_a, int_lst **st_b, int len)
{
	if (len == 1)
	{
		push_x(st_b, st_a, 'a', PRINT);
		return (0);
	}
	// if (qs_is_sorted(*st_b, DESC, len))
	// {
	// 	push_x(st_b, st_a, 'a', PRINT);
	// 	push_x(st_b, st_a, 'a', PRINT);
	// 	push_x(st_b, st_a, 'a', PRINT);
	// 	return (0);
	// }
	if (len == 2)
	{
		if ((*st_b)->value < (*st_b)->next->value)
			swap_x(st_b, 'b', PRINT);
		push_x(st_b, st_a, 'a', PRINT);
		push_x(st_b, st_a, 'a', PRINT);
		return (0);
	}
	return (1);
}

int_lst	*sort_3_null_desc(int_lst **st_a, int_lst **st_b)
{
	int		ft;
	int		sd;
	int		td;

	ft = (*st_b)->value;
	sd = (*st_b)->next->value;
	td = (*st_b)->next->next->value;
	if (ft < sd && sd < td) // 1 2 3
	{
		rotate_x(st_b, 'b', PRINT);
		swap_x(st_b, 'b', PRINT);
		push_x(st_b, st_a, 'a', PRINT);
		push_x(st_b, st_a, 'a', PRINT);
		push_x(st_b, st_a, 'a', PRINT);
	}
	else if (ft < sd && sd > td && ft > td) // 2 3 1
	{
		swap_x(st_b, 'b', PRINT);
		push_x(st_b, st_a, 'a', PRINT);
		push_x(st_b, st_a, 'a', PRINT);
		push_x(st_b, st_a, 'a', PRINT);
	}
	else if (ft > sd && ft < td) // 2 1 3
	{
		rev_rotate_x(st_b, 'b', PRINT);
		push_x(st_b, st_a, 'a', PRINT);
		push_x(st_b, st_a, 'a', PRINT);
		push_x(st_b, st_a, 'a', PRINT);
	}
	else if (ft > sd && ft > td && sd < td) // 3 1 2
	{
		push_x(st_b, st_a, 'a', PRINT);
		swap_x(st_b, 'b', PRINT);
		push_x(st_b, st_a, 'a', PRINT);
		push_x(st_b, st_a, 'a', PRINT);
	}
	else if (ft < sd && ft < td && sd > td) // 1 3 2
	{
		rotate_x(&st_b, 'b', PRINT);
		push_x(st_b, st_a, 'a', PRINT);
		push_x(st_b, st_a, 'a', PRINT);
		push_x(st_b, st_a, 'a', PRINT);
	}
	else
	{
		push_x(st_b, st_a, 'a', PRINT);
		push_x(st_b, st_a, 'a', PRINT);
		push_x(st_b, st_a, 'a', PRINT);
	}
	return (*st_b);
}

// int_lst	*sort_3_desc(int_lst *st_b, int_lst *st_a)
// {
// 	int		ft;
// 	int		sd;
// 	int		td;

// 	ft = st_b->value;
// 	sd = st_b->next->value;
// 	td = st_b->next->next->value;
// 	if (ft < sd && ft < td && sd < td) // 1 2 3
// 	{
// 		push_x(&st_b, &st_a, 'a', PRINT);
// 		push_x(&st_b, &st_a, 'a', PRINT);
// 		swap_x(&st_a, 'a', PRINT);
// 		push_x(&st_b, &st_a, 'a', PRINT);
// 		swap_x(&st_a, 'a', PRINT);
// 		push_x(&st_a, &st_b, 'b', PRINT);
// 		swap_x(&st_a, 'a', PRINT);
// 		push_x(&st_a, &st_b, 'b', PRINT);
// 		push_x(&st_a, &st_b, 'b', PRINT);
// 	}
// 	else if (ft < sd && sd > td && ft > td) // 2 3 1
// 		swap_x(&st_b, 'b', PRINT);
// 	else if (ft > sd && ft < td) // 2 1 3
// 	{
// 		push_x(&st_b, &st_a, 'a', PRINT);
// 		swap_x(&st_b, 'b', PRINT);
// 		push_x(&st_b, &st_a, 'a', PRINT);
// 		swap_x(&st_a, 'a', PRINT);
// 		push_x(&st_a, &st_b, 'b', PRINT);
// 		push_x(&st_a, &st_b, 'b', PRINT);
// 	}
// 	else if (ft > sd && ft > td && sd < td) // 3 1 2
// 	{
// 		push_x(&st_b, &st_a, 'a', PRINT);
// 		swap_x(&st_b, 'b', PRINT);
// 		push_x(&st_a, &st_b, 'b', PRINT);
// 	}
// 	else if (ft < sd && ft < td && sd > td) // 1 3 2
// 	{
// 		push_x(&st_b, &st_a, 'a', PRINT);
// 		push_x(&st_b, &st_a, 'a', PRINT);
// 		swap_x(&st_a, 'a', PRINT);
// 		push_x(&st_b, &st_a, 'a', PRINT);
// 		swap_x(&st_a, 'a', PRINT);
// 		push_x(&st_a, &st_b, 'b', PRINT);
// 		push_x(&st_a, &st_b, 'b', PRINT);
// 		push_x(&st_a, &st_b, 'b', PRINT);
// 	}
// 	return (st_b);
// }

int_lst	*sort_3_desc(int_lst **st_a, int_lst **st_b, int len)
{
	int	ft;
	int	sd;

	while (len)
	{
		ft = (*st_a)->value;
		sd = (*st_a)->next->value;
		if (ft > sd)
			swap_x(st_a, 'a', PRINT);
		else if (len == 1)
		{
			push_x(st_b, st_a, 'a', PRINT);
			len--;
		}
		ft = (*st_b)->value;
		sd = (*st_b)->next->value;
		if (len && ft > sd)
		{
			push_x(st_b, st_a, 'a', PRINT);
			len--;
		}
		else if (len && ft < sd)
		{
			swap_x(st_b, 'b', PRINT);
		}
	}
	return (*st_b);
}

int_lst	*sort_desc(int_lst **st_a, int_lst **st_b, int len)
{
	// int_lst	*st_a;
	int		lst_len;

	// st_a = NULL;
	if (!sort_needed_desc(st_a, st_b, len))
		return (*st_b);
	lst_len = ps_lst_len(*st_b);
	if (lst_len == 3)
		return (sort_3_null_desc(st_a, st_b));
	return (sort_3_desc(st_a, st_b, len));
}
