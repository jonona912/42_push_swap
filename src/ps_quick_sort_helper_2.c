/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick_sort_helper_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:25:57 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/01/27 20:19:49 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_b_stacks(t_ps_lst **st_a, t_ps_lst **st_b, int len, int is_a)
{
	if (len < 4 && is_a == 1)
	{
		sort_asc(st_a, st_b, len);
		return ;
	}
	else if (len < 4)
	{
		sort_desc(st_a, st_b, len);
		return ;
	}
}

void	ps_set_part_len(int len, int is_a, int *len_a, int *len_b)
{
	if (is_a == 1)
		*len_a = len - *len_b;
	else
		*len_b = len - *len_a;
}
