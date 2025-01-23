/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker_2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:57:45 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/01/23 12:48:48 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_sorted(int_lst *lst, t_sort sort)
{
	if (!lst)
		return (0);
	while (lst->next)
	{
		if ((lst->value > lst->next->value) && sort == ASC)
			return (0);
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

int	free_double_arr(char **str)
{
	int	i;

	i = 0;
	printf("%d %s\n", i, *str);
	return (1);
}
