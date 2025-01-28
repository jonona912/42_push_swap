/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operands_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:46:07 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/01/27 20:15:32 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ss(t_ps_lst	**lst_a, t_ps_lst **lst_b, t_print status)
{
	if (!lst_a || !lst_b || !*lst_a
		|| !*lst_b || !(*lst_a)->next || !(*lst_b)->next)
		return (0);
	if (status == PRINT)
		swap_x(lst_a, 's', PRINT);
	else
		swap_x(lst_a, 's', NOTPRINT);
	swap_x(lst_b, 'b', NOTPRINT);
	return (1);
}

int	rr(t_ps_lst	**lst_a, t_ps_lst **lst_b, t_print status)
{
	if (!lst_a || !lst_b || !*lst_a
		|| !*lst_b || !(*lst_a)->next || !(*lst_b)->next)
		return (0);
	if (status == PRINT)
		rotate_x(lst_a, 'r', PRINT);
	else
		rotate_x(lst_a, 'r', NOTPRINT);
	rotate_x(lst_b, 'b', NOTPRINT);
	return (1);
}

int	rrr(t_ps_lst	**lst_a, t_ps_lst **lst_b, t_print status)
{
	if (!lst_a || !lst_b || !*lst_a
		|| !*lst_b || !(*lst_a)->next || !(*lst_b)->next)
		return (0);
	if (status == PRINT)
		rev_rotate_x(lst_a, 'r', PRINT);
	else
		rev_rotate_x(lst_a, 'r', NOTPRINT);
	rev_rotate_x(lst_b, 'b', NOTPRINT);
	return (1);
}
