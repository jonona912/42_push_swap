/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick_sort_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:03:41 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/01/18 21:20:22 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	lst_partition_a(int_lst **st_a, int_lst **st_b, int len)
{
	int		i;
	int		len_b;
	int		median;

	len_b = 0;
	i = 0;
	median = qs_find_median(*st_a, len);
	while (i < len && *st_a)
	{
		if ((*st_a)->value < median)
		{
			push_x(st_a, st_b, 'b', PRINT);
			len_b++;
		}
		else
			rotate_x(st_a, 'a', PRINT);
		i++;
	}
	len = len - len_b;
	i = 0;
	while (i < len)
	{
		rev_rotate_x(st_a, 'a', PRINT);
		i++;
	}
	return (len_b);
}

int	lst_partition_b(int_lst **st_b, int_lst **st_a, int len)
{
	int		i;
	int		len_a;
	int		median;

	len_a = 0;
	i = 0;
	median = qs_find_median(*st_b, len);
	while (i < len && *st_b)
	{
		if ((*st_b)->value > median)
		{
			push_x(st_b, st_a, 'b', PRINT);
			len_a++;
		}
		else
			rotate_x(st_b, 'a', PRINT);
		i++;
	}
	len = len - len_a;
	i = 0;
	while (i < len)
	{
		rev_rotate_x(st_b, 'a', PRINT);
		i++;
	}
	return (len_a);
}

int_lst	*ps_qs_helper(int_lst **st_a, int_lst **st_b, int len, int is_a)
{
	int		len_a;
	int		len_b;
	int_lst	*temp;

	if (len < 4 && is_a == 1)
	{
		temp = sort_asc(*st_a, len);
		return (temp);
	}
	else if (len < 4)
	{
		temp = sort_desc(*st_b, len);
		return (temp);
	}
	if (is_a == 1)
	{
		len_b = lst_partition_a(st_a, st_b, len);
		len_a = len - len_b;
	}
	else
	{
		len_a = lst_partition_b(st_b, st_a, len);
		len_b = len - len_a;
	}
	*st_a = ps_qs_helper(st_a, st_b, len_a, 1);
	*st_b = ps_qs_helper(st_a, st_b, len_b, 0);
	if (is_a == 1)
		return (ps_merge(st_b, st_a, len_b, 'a'));
	else
		return (ps_merge(st_a, st_b, len_a, 'b'));
}

int_lst	*ps_quick_sort(int_lst **st_a)
{
	int_lst	*st_b;
	int		len;
	int		len_b;

	st_b = NULL;
	if (!st_a)
		return (NULL);
	if (!*st_a || !(*st_a)->next)
		return (*st_a);
	if (is_sorted(*st_a, ASC))
		return (*st_a);
	len = ps_lst_len(*st_a);
	
	// len_b = lst_partition_a(st_a, len, &st_b);
	// len = len - len_b;
	*st_a = ps_qs_helper(st_a, &st_b, len, 1);
	// st_b = ps_qs_helper_b(&st_b, len_b, 0, st_a);
	// ps_merge(st_a, &st_b, len_b, 'a');
	return (*st_a);
}














// int_lst	*ps_qs_helper_a(int_lst **st_a, int len, int is_a, int_lst **st_b)
// {
// 	int		len_a;
// 	int		len_b;
// 	int_lst	*temp;
// 	if (len < 4 && is_a == 1)
// 	{
// 		temp = sort_asc(*st_a, len);
// 		return (temp);
// 	}
// 	else if (len < 4)
// 	{
// 		temp = sort_desc(*st_a, len);
// 		return (temp);
// 	}
// 	if (is_a == 1)
// 	{
// 		len_b = lst_partition_a(st_a, len, st_b);
// 		len_a = len - len_b;
// 	}
// 	else
// 	{
// 		len_a = lst_partition_b(st_a, len, st_b);
// 		len_b = len - len_a;
// 	}
// 	*st_a = ps_qs_helper_a(st_a, len_a, 1, st_b);
// 	*st_b = ps_qs_helper_a(st_b, len_b, 0, st_a);
// 	if (is_a == 1)
// 	{
// 		return (ps_merge(st_a, st_b, len_b, 'a'));
// 	}
// 	else
// 	{
// 		return (ps_merge(st_a, st_b, len_a, 'b'));
// 	}
// }

// int_lst	*ps_qs_helper_b(int_lst **st_b, int len, int is_a, int_lst **st_a)
// {
// 	int		len_a;
// 	int		len_b;

// 	if (len < 4 && is_a == 1)
// 	{
// 		return (sort_asc(*st_b, len));
// 	}
// 	else if (len < 4)
// 		return (sort_desc(*st_b, len));
// 	// len_b = lst_partition_b(st_b, len, st_a);
// 	// len_a = len - len_b;
// 	if (is_a == 1)
// 	{
// 		len_b = lst_partition_a(st_b, len, st_a);
// 		len_a = len - len_b;
// 		// *st_a = ps_qs_helper_a(st_a, len_a, 1, st_b);
// 	}
// 	else
// 	{
// 		len_a = lst_partition_b(st_b, len, st_a);
// 		len_b = len - len_a;
// 	}
// 	*st_b = ps_qs_helper_b(st_b, len_a, 0, st_a);
// 	*st_a = ps_qs_helper_b(st_a, len_b, 1, st_b);
// 	if (is_a == 0)
// 	{
// 		return (ps_merge(st_b, st_a, len_b, 'a'));
// 	}
// 	else
// 	{
// 		return (ps_merge(st_b, st_a, len_a, 'b'));
// 	}
// }