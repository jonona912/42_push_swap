/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:24:16 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/01/26 16:56:29 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_int_range(char *str)
{
	int		stack_num;
	char	*stack_str;

	stack_num = ft_atoi(str);
	stack_str = ft_itoa(stack_num);
	if (*str == '0' && *(str + 1))
		str++;
	else if (*str == '+')
		str++;
	if (ft_strcmp(stack_str, str))
	{
		free(stack_str);
		print_error(2);
	}
	free(stack_str);
	return (1);
}

int	argv_valid(char *argv[], int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (contains_space(argv[i]))
			check_str(argv[i]);
		else if (!ft_isint(argv[i]))
			print_error(1);
		else
			check_int_range(argv[i]);
		i++;
	}
	return (1);
}

int	ft_is_dublicate(int_lst **st_a)
{
	int_lst	*dublicate;
	int_lst	*lst;

	lst = *st_a;
	while (lst->next)
	{
		dublicate = lst->next;
		while (dublicate)
		{
			if (lst->value == dublicate->value)
			{
				ps_lst_clear(st_a);
				print_error(3);
			}
			dublicate = dublicate->next;
		}
		lst = lst->next;
	}
	return (0);
}
