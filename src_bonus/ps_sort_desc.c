/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_desc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:57:14 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/01/27 20:15:32 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	sort_needed_desc(t_ps_lst **st_a, t_ps_lst **st_b, int len)
{
	if (len == 1)
	{
		push_x(st_b, st_a, 'a', PRINT);
		return (0);
	}
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

t_ps_lst	*sort_3_null_desc(t_ps_lst **st_a, t_ps_lst **st_b, int len)
{
	int		ft;
	int		sd;
	int		td;

	ft = set_nums(*st_b, len, &sd, &td);
	while (len)
	{
		if (len == 3 && (td > ft && td > sd))
			rev_rotate_x(st_b, 'b', PRINT);
		else if (len == 3 && (sd > ft && sd > td))
			rotate_x(st_b, 'b', PRINT);
		else if (len > 1 && (ft < sd))
			swap_x(st_b, 'b', PRINT);
		else
		{
			push_x(st_b, st_a, 'a', PRINT);
			len--;
		}
		ft = set_nums(*st_b, len, &sd, &td);
	}
	return (*st_b);
}

t_ps_lst	*sort_3_desc(t_ps_lst **st_a, t_ps_lst **st_b, int len)
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
			swap_x(st_b, 'b', PRINT);
	}
	return (*st_b);
}

t_ps_lst	*sort_desc(t_ps_lst **st_a, t_ps_lst **st_b, int len)
{
	int		lst_len;

	if (!sort_needed_desc(st_a, st_b, len))
		return (*st_b);
	lst_len = ps_lst_len(*st_b);
	if (lst_len == 3)
		return (sort_3_null_desc(st_a, st_b, len));
	return (sort_3_desc(st_a, st_b, len));
}
