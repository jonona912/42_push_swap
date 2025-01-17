/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operands_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:46:07 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/01/15 21:05:06 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ss(int_lst	**lst_a, int_lst **lst_b)
{
	if (!lst_a || !lst_b || !*lst_a
		|| !*lst_b || !(*lst_a)->next || !(*lst_b)->next)
		return (0);
	swap_x(lst_a, 's', PRINT);
	swap_x(lst_b, 'b', NOTPRINT);
	return (0);
}

int	rr(int_lst	**lst_a, int_lst **lst_b)
{
	if (!lst_a || !lst_b || !*lst_a
		|| !*lst_b || !(*lst_a)->next || !(*lst_b)->next)
		return (0);
	rotate_x(lst_a, 'r', PRINT);
	rotate_x(lst_b, 'b', NOTPRINT);
	return (1);
}

int	rrr(int_lst	**lst_a, int_lst **lst_b)
{
	if (!lst_a || !lst_b || !*lst_a
		|| !*lst_b || !(*lst_a)->next || !(*lst_b)->next)
		return (0);
	rev_rotate_x(lst_a, 'r', PRINT);
	rev_rotate_x(lst_b, 'b', NOTPRINT);
	return (1);
}
