/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick_sort_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:03:41 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/01/27 17:17:23 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	lst_part_b_helper(int_lst **st_a, int_lst **st_b, int len, int *len_a)
{
	int	n_rotates;
	int	median;

	median = qs_find_median(*st_b, len);
	n_rotates = 0;
	while (len > 0 && *st_b)
	{
		if (check_for_great_eq(*st_b, median))
		{
			if ((*st_b)->value >= median)
			{
				push_x(st_b, st_a, 'a', PRINT);
				(*len_a)++;
			}
			else
			{
				n_rotates++;
				rotate_x(st_b, 'b', PRINT);
			}
			len--;
		}
		else
			len = 0;
	}
	return (n_rotates);
}

int	lst_partition_b(int_lst **st_b, int_lst **st_a, int len)
{
	int		i;
	int		len_a;
	int		n_rotates;
	int_lst	*max_nd;

	len_a = 0;
	max_nd = find_max_beyond_len(*st_b, len);
	n_rotates = lst_part_b_helper(st_a, st_b, len, &len_a);
	len = len - len_a - n_rotates;
	if (max_nd != NULL && find_bigger_num(*st_b, len, max_nd))
	{
		i = 0;
		while (i < n_rotates)
		{
			rev_rotate_x(st_b, 'b', PRINT);
			i++;
		}
	}
	return (len_a);
}

void	ps_qs_helper(int_lst **st_a, int_lst **st_b, int len, int is_a)
{
	int		len_a;
	int		len_b;

	if (is_a == 1 && qs_is_sorted(*st_a, ASC, len))
		return ;
	else if (is_a == 0 && qs_is_sorted(*st_b, DESC, len))
	{
		while (len--)
			push_x(st_b, st_a, 'a', PRINT);
		return ;
	}
	if (len < 4)
	{
		sort_both_stacks(st_a, st_b, len, is_a);
		return ;
	}
	if (is_a == 1)
		len_b = lst_partition_a(st_a, st_b, len);
	else
		len_a = lst_partition_b(st_b, st_a, len);
	ps_set_part_len(len, is_a, &len_a, &len_b);
	ps_qs_helper(st_a, st_b, len_a, 1);
	ps_qs_helper(st_a, st_b, len_b, 0);
}

int_lst	*ps_quick_sort(int_lst **st_a)
{
	int_lst	*st_b;
	int		len;
	// int		len_b;

	st_b = NULL;
	if (!st_a)
		return (NULL);
	if (!*st_a || !(*st_a)->next)
		return (*st_a);
	if (is_sorted(*st_a, ASC))
		return (*st_a);
	len = ps_lst_len(*st_a);
	ps_qs_helper(st_a, &st_b, len, 1);
	return (*st_a);
}
