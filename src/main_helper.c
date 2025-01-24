/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:25:52 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/01/23 13:26:11 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	convert_add_lst(char *str, int_lst **lst)
{
	int		stack_num;

	stack_num = ft_atoi(str);
	ps_lst_add_back(lst, ps_lstnew(stack_num));
	return (1);
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
		i++;
	}
	return (st_a);
}
