/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:57:14 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/01/15 21:15:07 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int_lst	*sort_desc(int_lst *st_a, int len)
{
	int_lst	*st_b;
	int		ft;
	int		sd;
	int		td;

	st_b = NULL;
	if (len == 1)
		return (st_a);
	if (len == 2)
	{
		if (st_a->value < st_a->next->value)
			swap_x(&st_a, 'b', PRINT);
		return (st_a);
	}
	if (qs_is_sorted(st_a, DESC, len))
		return (st_a);
	ft = st_a->value;
	sd = st_a->next->value;
	td = st_a->next->next->value;
	if (ft < sd && ft < td && sd < td) // 1 2 3
	{
		push_x(&st_a, &st_b, 'a', PRINT);
		push_x(&st_a, &st_b, 'a', PRINT);
		swap_x(&st_b, 'b', PRINT);
		push_x(&st_a, &st_b, 'a', PRINT);
		swap_x(&st_b, 'b', PRINT);
		push_x(&st_b, &st_a, 'b', PRINT);
		swap_x(&st_b, 'b', PRINT);
		push_x(&st_b, &st_a, 'b', PRINT);
		push_x(&st_b, &st_a, 'b', PRINT);
		return (st_a);
	}
	if (ft < sd && sd > td && ft > td) // 2 3 1
	{
		swap_x(&st_a, 'b', PRINT);
		return (st_a);
	}
	if (ft > sd && sd > td) // 3 2 1
	{
		return (st_a);
	}
	if (ft > sd && ft < td) // 2 1 3
	{
		push_x(&st_a, &st_b, 'a', PRINT);
		swap_x(&st_a, 'b', PRINT);
		push_x(&st_a, &st_b, 'a', PRINT);
		swap_x(&st_b, 'b', PRINT);
		push_x(&st_b, &st_a, 'b', PRINT);
		push_x(&st_b, &st_a, 'b', PRINT);
		return (st_a);
	}
	if (ft > sd && ft > td && sd < td) // 3 1 2
	{
		push_x(&st_a, &st_b, 'b', PRINT);
		swap_x(&st_a, 'a', PRINT);
		push_x(&st_b, &st_a, 'a', PRINT);
		return (st_a);
	}
	if (ft < sd && ft < td && sd > td) // 1 3 2
	{
		push_x(&st_a, &st_b, 'b', PRINT);
		push_x(&st_a, &st_b, 'b', PRINT);
		swap_x(&st_b, 'a', PRINT);
		push_x(&st_a, &st_b, 'b', PRINT);
		swap_x(&st_b, 'a', PRINT);
		push_x(&st_b, &st_a, 'a', PRINT);
		push_x(&st_b, &st_a, 'a', PRINT);
		push_x(&st_b, &st_a, 'a', PRINT);
		return (st_a);
	}
	return (NULL);
}
