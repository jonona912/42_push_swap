/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:57:46 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/01/23 14:58:08 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	lst_compare(int_lst	*lst_a, int_lst *lst_b)
{
	while (lst_a && lst_b)
	{
		if (lst_a->value != lst_b->value)
			return (0);
		lst_a = lst_a->next;
		lst_b = lst_b->next;
	}
	if (lst_a == lst_b)
		return (1);
	return (0);
}
