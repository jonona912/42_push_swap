/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_operations_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:08:42 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/01/27 11:59:06 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap_bonus.h"
#include "../include/push_swap_bonus.h"

t_stack_operations	init_operations()
{
	t_stack_operations	ops;

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
	return	(ops);
}

int	ps_strcmp(char	*s1, char *opd)
{
	while (*s1 && *s1 == *opd)
	{
		s1++;
		opd++;
	}
	if (*s1 == '\0' && *opd == '\n')
		return (0);
	return (*s1 - *opd);
}

int	perform_operands(int_lst **st_a, int_lst **st_b, int fd)
{
	char	*str;
	t_stack_operations	ops;
	t_stack_operations	ops_no_nl;
	int	flag;
	static int i = 0;

	ops = init_operations();
	str = get_next_line(fd);
	while (str)
	{
		i++;
		flag = 0;
		if (!ps_strcmp(str, ops.pa) && *st_b)
		{
			push_x(st_b, st_a, 'a', NOTPRINT);
			flag = 1;
		}
		else if (!ps_strcmp(str, ops.pb) && *st_a)
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
		else if (!ps_strcmp(str, ops.rr))
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
		else if (!ps_strcmp(str, ops.sa))
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
		free (str);
		if (flag == 0)
			print_error(2);
		str = get_next_line(fd);
	}
	return (1);
}
