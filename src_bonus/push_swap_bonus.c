/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:14:43 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/01/23 20:09:42 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include <stdio.h>

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

int main(int argc, char *argv[])
{
	int_lst	*st_a;
	int_lst	*st_b;
	int_lst	*sorted;
	int		init_len;

	sorted = NULL;
	st_b = NULL;
	int	fd = open("test.txt", O_RDONLY);
	st_a = check_for_error(argc, argv);
	copy_lst(&sorted, st_a);
	sorted = merge_sort_lst(sorted);
	// ft_print_lst(sorted, '$');
	init_len = ps_lst_len(st_a);
	perform_operands(&st_a, &st_b, fd);
	if (init_len != ps_lst_len(st_a))
		print_error(3); // free lists
	ft_print_lst(st_a, '9');
	printf("is_sorted: %d\n", is_sorted(st_a, ASC));
	if (!is_sorted(st_a, ASC) || !lst_compare(st_a, sorted))
		print_error(4); // free lists
	ft_printf("OK\n");
	return (0);
}
