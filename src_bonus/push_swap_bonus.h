/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:05:16 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/01/23 15:00:03 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
#define PUSH_SWAP_BONUS_H

#include "../include/push_swap.h"
#include "../ft_printf/ft_printf.h"
#include "./gnl/get_next_line.h"

typedef struct	s_stack_operations {
	char *sa;
	char *sb;
	char *ss;
	char *pa;
	char *pb;
	char *ra;
	char *rb;
	char *rr;
	char *rra;
	char *rrb;
	char *rrr;
} t_stack_operations;

// check error bonus
void	check_error_output();
void	check_no_output();
int_lst	*check_for_error(int argc, char *argv[]);



// input checker
int	check_int_range_bonus(char *str);
int	argv_valid_bonus(char *argv[], int argc);
int	check_str_bonus(char *str);

// perform operations
t_stack_operations	init_operations();
int	perform_operands(int_lst **st_a, int_lst **st_b, int fd);

// lists_bonus
int	lst_compare(int_lst	*lst_a, int_lst *lst_b);

#endif