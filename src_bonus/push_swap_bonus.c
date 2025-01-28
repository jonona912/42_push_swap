/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:14:43 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/01/27 23:07:30 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"
// #include <stdio.h>

// void	ft_prt_ps_lst(t_ps_lst *lst, char c)
// {
// 	int	i = 1;
// 	ft_printf("Stack %c\n", c);
// 	while (lst)
// 	{
// 		ft_printf("idx: %d: %d\n", i, lst->value);
// 		lst = lst->next;
// 		i++;
// 	}
// }

void	m_h(t_ps_lst **st_a, t_ps_lst **st_b, t_ps_lst **sorted, int i_l)
{
	if (i_l != ps_lst_len(*st_a))
	{
		ps_lst_clear(sorted);
		ps_lst_clear(st_a);
		ps_lst_clear(st_b);
		ft_printf("KO\n");
	}
	if (!is_sorted(*st_a, ASC) || !lst_compare(*st_a, *sorted))
	{
		ps_lst_clear(sorted);
		ps_lst_clear(st_a);
		ps_lst_clear(st_b);
		ft_printf("KO\n");
	}
	else
	{
		ps_lst_clear(sorted);
		ps_lst_clear(st_a);
		ps_lst_clear(st_b);
		ft_printf("OK\n");
	}
}

int	main(int argc, char *argv[])
{
	t_ps_lst	*st_a;
	t_ps_lst	*st_b;
	t_ps_lst	*sorted;
	int			init_len;

	sorted = NULL;
	st_b = NULL;
	if (argc < 2 && check_no_output())
		return (0);
	st_a = check_for_error(argc, argv);
	copy_lst(&sorted, st_a);
	sorted = merge_sort_lst(sorted);
	init_len = ps_lst_len(st_a);
	if (!pfm_ops(&st_a, &st_b, &sorted, 0))
	{
		ps_lst_clear(&sorted);
		ps_lst_clear(&st_a);
		ps_lst_clear(&st_b);
		ft_printf("KO\n");
		return (0);
	}
	m_h(&st_a, &st_b, &sorted, init_len);
	return (0);
}
