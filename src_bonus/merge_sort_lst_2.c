/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_lst_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:53:17 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/01/15 21:01:55 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int_lst	*split_lst(int_lst *head)
{
	int_lst	*front_runner;
	int_lst	*trailer;
	int_lst	*half2;

	if (!head || !head->next)
		return (head);
	front_runner = head;
	trailer = head;
	while (front_runner && front_runner->next)
	{
		front_runner = front_runner->next->next;
		if (front_runner && front_runner->next)
			trailer = trailer->next;
	}
	half2 = trailer->next;
	trailer->next = NULL;
	return (half2);
}

int_lst	*merge_lst(int_lst *first, int_lst *second)
{
	if (!first)
		return (second);
	if (!second)
		return (first);
	if (first->value < second->value)
	{
		first->next = merge_lst(first->next, second);
		return (first);
	}
	else
	{
		second->next = merge_lst(first, second->next);
		return (second);
	}
}

int_lst	*merge_sort_lst(int_lst *head)
{
	int_lst	*half2;

	if (!head || !head->next)
		return (head);
	half2 = split_lst(head);
	head = merge_sort_lst(head);
	half2 = merge_sort_lst(half2);
	return (merge_lst(head, half2));
}

int	find_median(int_lst *head)
{
	int_lst	*median;
	int_lst	*lst_copy;
	int_lst	*sorted;
	int		ret;

	lst_copy = NULL;
	if (!head)
		return (0);
	copy_lst(&lst_copy, head);
	sorted = merge_sort_lst(lst_copy);
	median = split_lst(sorted);
	ret = median->value;
	ps_lst_clear(&sorted);
	ps_lst_clear(&median);
	return (ret);
}
