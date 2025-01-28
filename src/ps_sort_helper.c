/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:47:29 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/01/27 20:15:32 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	double_swapped(t_ps_lst **st_a, t_ps_lst **st_b)
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
		if ((a1 > a2) && (b1 < b2))
		{
			ss(st_a, st_b, PRINT);
			return (1);
		}
	}
	return (0);
}

int	set_nums(t_ps_lst *lst, int len, int *sd, int *td)
{
	if (!lst)
		return (0);
	if (len == 3)
	{
		*sd = lst->next->value;
		*td = lst->next->next->value;
		return (lst->value);
	}
	else if (len == 2)
	{
		*sd = lst->next->value;
		return (lst->value);
	}
	else
		return (lst->value);
}
