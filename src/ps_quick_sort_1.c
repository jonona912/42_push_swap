/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick_sort_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:03:41 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/01/26 14:26:03 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_for_less(int_lst *lst, int num)
{
	while (lst)
	{
		if (lst->value < num)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	check_for_great_eq(int_lst *lst, int num)
{
	while (lst)
	{
		if (lst->value >= num)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	is_sorted_beyond(int_lst *lst, int len)
{
	int	i;

	i = 0;
	while (i < len && lst)
	{
		i++;
		lst = lst->next;
	}
	if (!lst)
		return (0);
	if (is_sorted(lst, ASC))
		return (1);
	return (0);
}

int	is_stack_b_rot(int_lst *lst)
{
	int	first;
	int_lst	*last_nd;

	if (!lst || !lst->next)
		return (0);
	first = lst->value;
	last_nd = ps_lst_last(lst);
	if (first < last_nd->value)
		return (1);
	return (0);
}

int	lst_partition_a(int_lst **st_a, int_lst **st_b, int len)
{
	int		i;
	int		len_b;
	int		median;
	int		n_rotates;
	int		is_rotate;

	len_b = 0;
	i = 0;
	n_rotates = 0;
	is_rotate = is_sorted_beyond(*st_a, len);
	median = qs_find_median(*st_a, len);
	while (i < len && *st_a)
	{
		if (check_for_less(*st_a, median))
		{
			if ((*st_a)->value < median)
			{
				push_x(st_a, st_b, 'b', PRINT);
				len_b++;
			}
			else
			{
				n_rotates++;
				if (is_stack_b_rot(*st_b))
					rr(st_a, st_b, PRINT);
				else
					rotate_x(st_a, 'a', PRINT);
			}
			i++;
		}
		else
			i = len;
	}
	len = len - len_b;
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

int_lst	*find_max_beyond_len(int_lst *lst, int len)
{
	int	i;
	int_lst	*max_nd;

	i = 0;
	while (i < len && lst)
	{
		lst = lst->next;
		i++;
	}
	if (!lst)
		return (NULL);
	max_nd = lst;
	while (lst)
	{
		if (lst->value > max_nd->value)
			max_nd = lst;
		lst = lst->next;
	}
	return (max_nd);
}

int	find_bigger_num(int_lst *lst, int len, int_lst *max_nd)
{
	int	i;
	int	max;

	i = 0;
	max = max_nd->value;
	while (i < len && lst)
	{
		lst = lst->next;
		i++;
	}

	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->value > max)
			return (1);
		lst = lst->next;
	}
	return (0);
}
int	lst_partition_b(int_lst **st_b, int_lst **st_a, int len)
{
	int	i;
	int	len_a;
	int	median;
	int	n_rotate;
	int_lst	*max_nd;

	len_a = 0;
	i = 0;
	n_rotate = 0;
	max_nd = find_max_beyond_len(*st_b, len);
	median = qs_find_median(*st_b, len);
	while (i < len && *st_b)
	{
		if (check_for_great_eq(*st_b, median))
		{
			if ((*st_b)->value >= median)
			{
				push_x(st_b, st_a, 'a', PRINT);
				len_a++;
			}
			else
			{
				n_rotate++;
				rotate_x(st_b, 'b', PRINT);
			}
			i++;
		}
		else
			i = len;
	}
	len = len - len_a - n_rotate;
	if (max_nd != NULL && find_bigger_num(*st_b, len, max_nd))
	{
		i = 0;
		while (i < n_rotate)
		{
			rev_rotate_x(st_b, 'b', PRINT);
			i++;
		}
	}
	return (len_a);
}

int_lst	*ps_qs_helper(int_lst **st_a, int_lst **st_b, int len, int is_a)
{
	static int	i = 0;

	i++;
	int		len_a;
	int		len_b;
	int_lst	*temp;

	if (is_a == 1 && qs_is_sorted(*st_a, ASC, len))
		return (*st_a);
	else if (is_a == 0 && qs_is_sorted(*st_b, DESC, len))
	{
		while (len--)
			push_x(st_b, st_a, 'a', PRINT);
		return (*st_b);
	}
	if (len < 4 && is_a == 1)
	{
		sort_asc(st_a, st_b, len);
		return (*st_a);
	}
	else if (len < 4)
	{
		sort_desc(st_a, st_b, len);
		return (*st_b);
	}
	if (is_a == 1)
	{
		// if is_a =
		// if is_a = 1 then send 1 else send zero
		len_b = lst_partition_a(st_a, st_b, len);
		len_a = len - len_b;
	}
	else
	{
		// if is_a = 1 and rotate = 0 -> change rotate to 1
		len_a = lst_partition_b(st_b, st_a, len);
		len_b = len - len_a;
	}
	ps_qs_helper(st_a, st_b, len_a, 1);
	// if rotate = 
	ps_qs_helper(st_a, st_b, len_b, 0);
	// if (is_a == 1)
	// 	return (ps_merge(st_b, st_a, len_b, 'a'));
	// else
	// 	return (ps_merge(st_a, st_b, len_a, 'b'));
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
	ps_qs_helper(st_a, &st_b, len, 1);
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