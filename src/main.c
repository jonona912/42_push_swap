/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:15:51 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/01/26 15:28:50 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdlib.h>

void	ft_print_lst(int_lst *lst, char c)
{
	int	i = 1;
	ft_printf("Stack %c\n", c);
	while (lst)
	{
		ft_printf("idx: %d: %d\n", i, lst->value);
		lst = lst->next;
		i++;
	}
	printf("--------------------------------------\n");
}

int	main(int argc, char *argv[])
{
	int_lst	*st_a;
	// int_lst *st_b;
	// int_lst *new_lst;
	// int		median;

	// new_lst = NULL;
	// st_b = NULL;
	if (argc < 2)
		return (0);
	argv_valid(argv, argc);
	// i = 1;
	// while (i < argc)
	// {
	// 	stack_num = ft_atoi(argv[i]);
	// 	ps_lst_add_back(&st_a, ps_lstnew(stack_num));
	// 	i++;
	// }
	st_a = make_num_lst(argv, argc);
	if (ft_is_dublicate(&st_a))
		exit(2); /// free list
	if (is_sorted(st_a, ASC))
		return (0);
	// median = find_median(st_a);
	// printf("median: %d\n", find_media9+(st_a));
	// ft_print_lst(st_a, 'a');
	ps_quick_sort(&st_a);
	ft_print_lst(st_a, '~');
	if (is_sorted(st_a, ASC))
		printf("sorted\n");
	else
		printf("not sorted\n");

	// // int_lst *three = NULL;
	// int_lst *temp;
	// ps_lst_add_back(&three, ps_lstnew(3));
	// ps_lst_add_back(&three, ps_lstnew(2));
	// ps_lst_add_back(&three, ps_lstnew(1));
	// ps_lst_add_back(&three, ps_lstnew(0));
	// printf("qs_is_sorted: %d\n", qs_is_sorted(three, DESC, 4));
	// ft_print_lst(three, '1');
	// temp  = sort_asc(three, 3);
	// ft_printf("temp: %d\n", temp->value);
	// ft_print_lst(temp, '2');

	// ft_print_lst(st_a, 'a');
	// copy_lst(&new_lst, st_a);
	// new_lst = split_lst(st_a);
	// int_lst *temp = merge_sort_lst(st_a);
	// ft_print_lst(st_a, 'a');
	// ft_print_lst(new_lst, 'l');
	// ft_print_lst(temp, 't');
	/// /// function tests
	// // ft_lst_sort(&st_a, &st_b, argc);
	// printf("original list\n");
	// ft_print_lst(st_a, 'a');
	// ft_print_lst(st_b, 'b');
	// printf("rev_rotate x 2\n");
	// rev_rotate_x(&st_a, 'a', PRINT);
	// rev_rotate_x(&st_a, 'a', PRINT);
	// ft_print_lst(st_a, 'a');
	// printf("rotate x 2\n");
	// rotate_x(&st_a, 'a', PRINT);
	// rotate_x(&st_a, 'a', PRINT);
	// ft_print_lst(st_a, 'a');
	// printf("push to b x 2 times");
	// push_x(&st_a, &st_b, 'b', PRINT);
	// push_x(&st_a, &st_b, 'b', PRINT);
	// push_x(&st_a, &st_b, 'b', PRINT);
	// ft_print_lst(st_a, 'a');
	// ft_print_lst(st_b, 'b');
	// printf("swap stack a and b\n");
	// swap_x(&st_a, 'a', NOTPRINT);
	// swap_x(&st_b, 'b', NOTPRINT);
	// ft_print_lst(st_a, 'a');
	// ft_print_lst(st_b, 'b');

	// printf("ss\n");
	// ss(&st_a, &st_b);
	// ft_print_lst(st_a, 'a');
	// ft_print_lst(st_b, 'b');

	// printf("rr function\n");
	// rr(&st_a, &st_b);
	// ft_print_lst(st_a, 'a');
	// ft_print_lst(st_b, 'b');

	// printf("rrr function\n");
	// rrr(&st_a, &st_b);
	// rrr(&st_a, &st_b);
	// rrr(&st_a, &st_b);
	// ft_print_lst(st_a, 'a');
	// ft_print_lst(st_b, 'b');

	// int_lst	*half2;
	// printf("\n DIVIDE LIST\n");
	// divide_list(&st_a, &half2, 2);
	// ft_print_lst(st_a, 'a');
	// ft_print_lst(half2, 'b');
	

	ps_lst_clear(&st_a);
	return (0);
}
