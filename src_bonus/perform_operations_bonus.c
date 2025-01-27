/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_operations_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:08:42 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/01/27 19:29:14 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

t_stk_ops	init_operations(void)
{
	t_stk_ops	ops;

	ops.sa = "sa\n";
	ops.sb = "sb\n";
	ops.ss = "ss\n";
	ops.pa = "pa\n";
	ops.pb = "pb\n";
	ops.ra = "ra\n";
	ops.rb = "rb\n";
	ops.rr = "rr\n";
	ops.rra = "rra\n";
	ops.rrb = "rrb\n";
	ops.rrr = "rrr\n";
	return (ops);
}

int	pfm_ops_helper_1(int_lst **st_a, int_lst **st_b, t_stk_ops ops, char *str)
{
	int	flag;

	flag = 0;
	if (!ps_strcmp(str, ops.pa))
	{
		push_x(st_b, st_a, 'a', NOTPRINT);
		flag = 1;
	}
	else if (!ps_strcmp(str, ops.pb))
	{
		push_x(st_a, st_b, 'b', NOTPRINT);
		flag = 1;
	}
	else if (!ps_strcmp(str, ops.ra))
	{
		rotate_x(st_a, 'a', NOTPRINT);
		flag = 1;
	}
	else if (!ps_strcmp(str, ops.rb))
	{
		rotate_x(st_b, 'b', NOTPRINT);
		flag = 1;
	}
	return (flag);
}

int	pfm_ops_helper_2(int_lst **st_a, int_lst **st_b, t_stk_ops ops, char *str)
{
	int	flag;

	flag = 0;
	if (!ps_strcmp(str, ops.rr))
	{
		rr(st_a, st_b, NOTPRINT);
		flag = 1;
	}
	else if (!ps_strcmp(str, ops.rra))
	{
		rev_rotate_x(st_a, 'a', NOTPRINT);
		flag = 1;
	}
	else if (!ps_strcmp(str, ops.rrb))
	{
		rev_rotate_x(st_b, 'b', NOTPRINT);
		flag = 1;
	}
	else if (!ps_strcmp(str, ops.rrr))
	{
		rrr(st_a, st_b, NOTPRINT);
		flag = 1;
	}
	return (flag);
}

int	pfm_ops_helper_3(int_lst **st_a, int_lst **st_b, t_stk_ops ops, char *str)
{
	int	flag;

	flag = 0;
	if (!ps_strcmp(str, ops.sa))
	{
		swap_x(st_a, 'a', NOTPRINT);
		flag = 1;
	}
	else if (!ps_strcmp(str, ops.sb))
	{
		swap_x(st_b, 'b', NOTPRINT);
		flag = 1;
	}
	else if (!ps_strcmp(str, ops.ss))
	{
		ss(st_a, st_b, NOTPRINT);
		flag = 1;
	}
	return (flag);
}

int	perform_operands(int_lst **st_a, int_lst **st_b, int fd)
{
	char		*str;
	t_stk_ops	ops;
	int			flag;

	ops = init_operations();
	str = get_next_line(fd);
	while (str)
	{
		flag = pfm_ops_helper_1(st_a, st_b, ops, str);
		if (!flag)
			flag = pfm_ops_helper_2(st_a, st_b, ops, str);
		if (!flag)
			flag = pfm_ops_helper_3(st_a, st_b, ops, str);
		free (str);
		if (flag == 0)
		{
			print_error(2);
		}
		str = get_next_line(fd);
	}
	return (1);
}
