/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_qs_partition_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:53:05 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/01/27 20:21:36 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ps_ptn_rot_a(t_ps_lst **st_a, t_ps_lst **st_b, int *n_rotates)
{
	(*n_rotates)++;
	if (is_stack_b_rot(*st_b))
		rr(st_a, st_b, PRINT);
	else
		rotate_x(st_a, 'a', PRINT);
}

int	lst_a_hpr(t_ps_lst **st_a, t_ps_lst **st_b, int len, int *len_b)
{
	int	i;
	int	n_rotates;
	int	median;

	median = qs_find_median(*st_a, len);
	n_rotates = 0;
	i = 0;
	while (i < len && *st_a)
	{
		if (check_for_less(*st_a, median))
		{
			if ((*st_a)->value < median)
			{
				push_x(st_a, st_b, 'b', PRINT);
				(*len_b)++;
			}
			else
				ps_ptn_rot_a(st_a, st_b, &n_rotates);
			i++;
		}
		else
			i = len;
	}
	return (n_rotates);
}

int	lst_partition_a(t_ps_lst **st_a, t_ps_lst **st_b, int len)
{
	int	i;
	int	len_b;
	int	n_rotates;
	int	is_rotate;

	len_b = 0;
	i = 0;
	is_rotate = is_sorted_beyond(*st_a, len);
	n_rotates = lst_a_hpr(st_a, st_b, len, &len_b);
	if (is_rotate)
	{
		i = 0;
		while (i < n_rotates)
		{
			rev_rotate_x(st_a, 'a', PRINT);
			i++;
		}
	}
	return (len_b);
}
