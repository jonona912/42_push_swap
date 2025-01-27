/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_asc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:14:48 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/01/27 12:24:58 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	sort_needed_asc(int_lst **st_a, int_lst **st_b, int len)
{
	if (len == 1)
		return (0);
	if (qs_is_sorted(*st_a, ASC, len))
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

void	rev_rot_sor_helper(int_lst **st_a, int_lst **st_b)
{
	if (is_stack_b_rot(*st_b))
		rrr(st_a, st_b, PRINT);
	else
		rev_rotate_x(st_a, 'a', PRINT);
}

int_lst	*sort_3_null_asc(int_lst **st_a, int_lst **st_b, int len)
{
	int		ft;
	int		sd;
	int		td;

	ft = set_nums(*st_a, len, &sd, &td);
	while (!(ft < sd && sd < td))
	{
		if (ft < sd && sd > td && ft > td)
			rev_rot_sor_helper(st_a, st_b);
		else if (ft > sd && ft > td)
		{
			if (is_stack_b_rot(*st_b))
				rr(st_a, st_b, PRINT);
			else
				rotate_x(st_a, 'a', PRINT);
		}
		else if ((ft < sd && ft < td) || (ft > sd && ft < td))
		{
			if (!double_swapped(st_a, st_b))
				swap_x(st_a, 'a', PRINT);
		}
		ft = set_nums(*st_a, len, &sd, &td);
	}
	return (*st_a);
}

int_lst	*sort_3_asc(int_lst **st_a, int_lst **st_b, int len)
{
	int		ft;
	int		sd;
	int		td;

	ft = set_nums(*st_a, len, &sd, &td);
	while (len != 3 || !(ft < sd && sd < td))
	{
		if (ft > sd)
		{
			if (!double_swapped(st_a, st_b))
				swap_x(st_a, 'a', PRINT);
		}
		else if (len == 3 && ft < sd)
		{
			push_x(st_a, st_b, 'b', PRINT);
			len--;
		}
		else if (len == 2)
		{
			push_x(st_b, st_a, 'a', PRINT);
			len++;
		}
		ft = set_nums(*st_a, len, &sd, &td);
	}
	return (*st_a);
}

int_lst	*sort_asc(int_lst **st_a, int_lst **st_b, int len)
{
	int		lst_len;

	if (!sort_needed_asc(st_a, st_b, len))
		return (*st_a);
	lst_len = ps_lst_len(*st_a);
	if (lst_len == 3)
	{
		sort_3_null_asc(st_a, st_b, len);
		return (*st_a);
	}
	else
		return (sort_3_asc(st_a, st_b, len));
}
