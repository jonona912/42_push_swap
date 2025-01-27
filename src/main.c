/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:15:51 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/01/27 17:02:05 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdlib.h>

void	ft_print_lst(int_lst *lst, char c)
{
	int	i;

	i = 1;
	ft_printf("Stack %c\n", c);
	while (lst)
	{
		ft_printf("idx: %d: %d\n", i, lst->value);
		lst = lst->next;
		i++;
	}
}

// int	main(int argc, char *argv[])
// {
// 	int_lst	*st_a;

// 	if (argc < 2)
// 		return (0);
// 	argv_valid(argv, argc);
// 	st_a = make_num_lst(argv, argc);
// 	if (ft_is_dublicate(&st_a))
// 		exit(2);
// 	if (is_sorted(st_a, ASC))
// 		return (0);
// 	ps_quick_sort(&st_a);
// 	ps_lst_clear(&st_a);
// 	return (0);
// }

int	main(int argc, char *argv[])
{
	int_lst	*st_a;

	if (argc < 2)
		return (0);
	argv_valid(argv, argc);
	st_a = make_num_lst(argv, argc);
	if (ft_is_dublicate(&st_a))
		exit(2);
	if (is_sorted(st_a, ASC))
		return (0);
	ps_quick_sort(&st_a);
	// ft_print_lst(st_a, '~');
	// if (is_sorted(st_a, ASC))
	// 	printf("sorted\n");
	// else
	// 	printf("not sorted\n");
	ps_lst_clear(&st_a);
	return (0);
}
