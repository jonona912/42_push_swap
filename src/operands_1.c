/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operands_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:12:31 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/01/27 20:15:32 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_ps_lst	*find_penultimate(t_ps_lst *lst)
{
	t_ps_lst	*prev;

	if (!lst || !lst->next)
		return (NULL);
	while (lst->next)
	{
		prev = lst;
		lst = lst->next;
	}
	return (prev);
}

t_ps_lst	*rev_rotate_x(t_ps_lst **lst, char x, t_print status)
{
	t_ps_lst	*penultimate;

	if (!lst)
		return (NULL);
	if (!*lst || !(*lst)->next)
		return (*lst);
	if (status)
		ft_printf("rr%c\n", x);
	penultimate = find_penultimate(*lst);
	penultimate->next->next = *lst;
	*lst = penultimate->next;
	penultimate->next = NULL;
	return (*lst);
}

t_ps_lst	*rotate_x(t_ps_lst **lst, char x, t_print status)
{
	t_ps_lst	*penultimate;
	t_ps_lst	*new_head;

	if (!lst)
		return (NULL);
	if (!*lst || !(*lst)->next)
		return (*lst);
	if (status)
		ft_printf("r%c\n", x);
	penultimate = find_penultimate(*lst);
	penultimate->next->next = *lst;
	new_head = (*lst)->next;
	(*lst)->next = NULL;
	*lst = new_head;
	return (*lst);
}

int	push_x(t_ps_lst **st_x, t_ps_lst **st_y, char x, t_print status)
{
	t_ps_lst	*first_node;

	if (!*st_x)
		return (0);
	if (status)
		ft_printf("p%c\n", x);
	first_node = *st_x;
	*st_x = (*st_x)->next;
	first_node->next = NULL;
	ps_lst_add_front(st_y, first_node);
	return (1);
}

t_ps_lst	*swap_x(t_ps_lst	**lst, char x, t_print status)
{
	t_ps_lst	*temp_head;

	if (!lst)
		return (NULL);
	if (!*lst || !(*lst)->next)
		return (*lst);
	if (status)
		ft_printf("s%c\n", x);
	temp_head = *lst;
	*lst = (*lst)->next;
	temp_head->next = (*lst)->next;
	(*lst)->next = temp_head;
	return (*lst);
}
