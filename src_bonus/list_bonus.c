/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:57:46 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/01/27 20:15:32 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap_bonus.h"
#include "../include/push_swap_bonus.h"

int	lst_compare(t_ps_lst	*lst_a, t_ps_lst *lst_b)
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
