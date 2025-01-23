/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:14:43 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/01/23 12:46:46 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "./gnl/get_next_line.h"

void	check_error_output()
{
		char	*str;

		str = get_next_line(0);
		if (ft_strcmp(str, "Error\n") == 0)
		{
			ft_printf("OK\n");
			free(str);
			exit(1);
		}
		else
		{
			free(str);
			print_error(1);
		}
}

void	check_no_output()
{
		char	*str;

		str = get_next_line(0);
		if (str == NULL)
		{
			ft_printf("OK\n");
			free(str);
			exit(1);
		}
		else
		{
			free(str);
			print_error(1);
		}
}

int_lst	*check_for_error(int argc, char *argv[])
{
	int_lst	*st_a;

	st_a = NULL;
	if (argc < 2)
		check_no_output();
	if (!argv_valid_bonus(argv, argc))
		check_error_output();
	st_a = make_num_lst(argv, argc);
	if (ft_is_dublicate(&st_a))
		check_error_output(); // free st_a
	if (is_sorted(st_a, ASC))
		check_no_output();
	return (st_a);
}

t_stack_operations init_operations()
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
	return ops;
}

int	perform_operands(int_lst **st_a, int_lst **st_b)
{
	char	*str;
	t_stack_operations	ops;
	int	flag;

	ops = init_operations();
	str = get_next_line(0);
	while (str)
	{
		flag = 0;
		if (!ft_strcmp(str, ops.pa) && *st_b)
		{
			push_x(st_b, st_a, 'a', NOTPRINT);
			flag = 1;
		}
		else if (!ft_strcmp(str, ops.pb) && *st_a)
		{
			push_x(st_a, st_b, 'b', NOTPRINT);
			flag = 1;
		}
		else if (!ft_strcmp(str, ops.ra))
		{
			rotate_x(st_a, 'a', NOTPRINT);
			flag = 1;
		}
		else if (!ft_strcmp(str, ops.rb))
		{
			rotate_x(st_b, 'b', NOTPRINT);
			flag = 1;
		}
		else if (!ft_strcmp(str, ops.rr))
		{
			rr(st_a, st_b, NOTPRINT);
			flag = 1;
		}
		else if (!ft_strcmp(str, ops.rra))
		{
			rev_rotate_x(st_a, 'a', NOTPRINT);
			flag = 1;
		}
		else if (!ft_strcmp(str, ops.rrb))
		{
			rev_rotate_x(st_b, 'b', NOTPRINT);
			flag = 1;
		}
		else if (!ft_strcmp(str, ops.rrr))
		{
			rrr(st_a, st_b, NOTPRINT);
			flag = 1;
		}
		else if (!ft_strcmp(str, ops.sa))
		{
			swap_x(st_a, 'a', NOTPRINT);
			flag = 1;
		}
		else if (!ft_strcmp(str, ops.sb))
		{
			swap_x(st_b, 'b', NOTPRINT);
			flag = 1;
		}
		else if (!ft_strcmp(str, ops.ss))
		{
			ss(st_a, st_b, NOTPRINT);
			flag = 1;
		}
		free (str);
		if (flag == 0)
			print_error(2);
		str = get_next_line(0);
	}
	return (1);
}

int	lst_compare(int_lst	*lst_a, int_lst *lst_b)
{
	while (lst_a && lst_b)
	{
		if (lst_a->value != lst_b->value)
			return (0);
		lst_a = lst_a->next;
		lst_b = lst_b->next;
	}
	if (lst_a == lst_b)
		return (1);
	return (0);
}

int_lst	*make_num_lst(char *argv[], int argc)
{
	int_lst	*st_a;
	int		stack_num;
	int		i;

	st_a = NULL;
	i = 1;
	while (i < argc)
	{
		if (contains_space(argv[i]))
		{
			create_lst_from_str(&st_a, argv[i]);
		}
		else
			convert_add_lst(argv[i], &st_a);
		// stack_num = ft_atoi(argv[i]);
		// ps_lst_add_back(&st_a, ps_lstnew(stack_num));
		i++;
	}
	return (st_a);
}

void	create_lst_from_str(int_lst **lst, char *str)
{
	char	**str_arr;
	int		i;

	str_arr = ft_split(str, ' ');
	i = 0;
	while (*(str_arr + i))
	{
		convert_add_lst(*(str_arr + i), lst);
		i++;
	}
	
}

int main(int argc, char *argv[])
{
	int_lst	*st_a;
	int_lst	*st_b;
	int_lst	*sorted;
	int		init_len;

	sorted = NULL;
	st_b = NULL;
	st_a = check_for_error(argc, argv);
	init_len = ps_lst_len(st_a);
	perform_operands(st_a, st_b);
	copy_lst(&sorted, st_a);
	sorted = merge_sort_lst(sorted);
	if (init_len != ps_lst_len(st_a))
		print_error(3); // free lists
	if (!is_sorted(st_a, ASC) || !lst_compare(st_a, sorted))
		print_error(4); // free lists
	ft_printf("OK\n");
	return (0);
}
