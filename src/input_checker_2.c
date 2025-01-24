/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:54:23 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/01/23 22:21:56 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(int_lst *lst, t_sort sort)
{
	if (!lst)
		return (0);
	while (lst->next)
	{
		if ((lst->value > lst->next->value) && sort == ASC)
		{
			return (0);
		}
		else if ((lst->value < lst->next->value) && sort == DESC)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	print_error(int n)
{
	write(2, "Error\n", 6);
	exit(n);
}

int	contains_space(char *str)
{
	while (*str)
	{
		if (*str == ' ')
			return (1);
		str++;
	}
	return (0);
}

int	check_str(char *str)
{
	char	**str_arr;

	str_arr = ft_split(str, ' ');
	if (!str_arr)
		return (-1);
	while (!*str_arr)
	{
		if (!ft_isint(*str_arr))
			print_error(1);
		check_int_range(*str_arr);
		str_arr++;
	}
	return (1);
}

int	free_double_arr(char **str)
{
	int	i;

	i = 0;
	printf("%d %s\n", i, *str);
	return (1);
}
