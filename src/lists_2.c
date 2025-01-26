/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:15:26 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/01/26 20:07:43 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_isint(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	ps_lst_len(int_lst *head)
{
	int	i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

int	qs_is_sorted(int_lst *lst, t_sort sort, int len)
{
	int	i;

	i = 1;
	if (!lst)
		return (1);
	while (i < len && lst->next)
	{
		if ((lst->value > lst->next->value) && sort == ASC)
			return (0);
		else if ((lst->value < lst->next->value) && sort == DESC)
			return (0);
		lst = lst->next;
		i++;
	}
	return (1);
}