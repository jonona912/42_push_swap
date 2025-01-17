/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sort_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:11:04 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/01/15 21:12:33 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
