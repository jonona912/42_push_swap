/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker_1_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:36:56 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/01/23 13:19:31 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_int_range_bonus(char *str)
{
	int		stack_num;
	char	*stack_str;

	stack_num = ft_atoi(str);
	stack_str = ft_itoa(stack_num);
	if (ft_strcmp(stack_str, str))
		return (0);
	free(stack_str);
	return (1);
}

int	argv_valid_bonus(char *argv[], int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (contains_space(argv[i]) && !check_str_bonus(argv[i]))
			return (0);
		else if (!ft_isint(argv[i]))
			return (0);
		else if (!check_int_range_bonus(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_str_bonus(char *str)
{
	char	**str_arr;

	str_arr = ft_split(str, ' ');
	if (!str_arr)
		return (-1);
	while (!*str_arr)
	{
		if (!ft_isint(*str_arr))
			return (0);
		check_int_range_bonus(*str_arr);
		str_arr++;
	}
	return (1);
}

// int	ft_is_dublicate(int_lst **st_a)
// {
// 	int_lst	*dublicate;
// 	int_lst	*lst;

// 	lst = *st_a;
// 	while (lst->next)
// 	{
// 		dublicate = lst->next;
// 		while (dublicate)
// 		{
// 			if (lst->value == dublicate->value)
// 			{
// 				ps_lst_clear(st_a);
// 				print_error(3);
// 			}
// 			dublicate = dublicate->next;
// 		}
// 		lst = lst->next;
// 	}
// 	return (0);
// }
