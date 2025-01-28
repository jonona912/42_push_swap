/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:36:56 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/01/27 23:23:34 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	check_int_range_bonus(char *str)
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
		print_error(9);
	}
	free(stack_str);
	return (1);
}

int	argv_valid_bonus(char *argv[], int argc)
{
	int	i;
	int	is_space;

	i = 1;
	while (i < argc)
	{
		is_space = contains_space(argv[i]);
		if (is_space && !check_str_bonus(argv[i]))
		{
			return (0);
		}
		else if (!is_space && !ft_isint(argv[i]))
		{
			print_error(5);
		}
		else if (!is_space && !check_int_range_bonus(argv[i]))
		{
			return (0);
		}
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
	while (*str_arr)
	{
		if (!ft_isint(*str_arr))
			print_error(6);
		if (!check_int_range_bonus(*str_arr))
			return (0);
		str_arr++;
	}
	return (1);
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
