/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:07:31 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/01/27 11:57:35 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	check_error_output()
{
	char	*str;

	str = get_next_line(3);
	if (ft_strcmp(str, "Error\n") == 0)
	{
		ft_printf("OK\n");
		free(str);
		exit(1);
	}
	else
	{
		free(str);
		print_error(1);
	}
}

void	check_no_output()
{
		char	*str;

		str = get_next_line(3);
		if (str == NULL)
		{
			ft_printf("OK\n");
			free(str);
			exit(1);
		}
		else
		{
			free(str);
			print_error(1);
		}
}

int_lst	*check_for_error(int argc, char *argv[])
{
	int_lst	*st_a;

	st_a = NULL;
	if (argc < 2)
		check_no_output();
	if (!argv_valid_bonus(argv, argc))
		check_error_output();
	st_a = make_num_lst(argv, argc);
	if (ft_is_dublicate(&st_a))
		check_error_output(); // free st_a
	if (is_sorted(st_a, ASC))
		check_no_output();
	return (st_a);
}
