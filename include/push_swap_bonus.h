/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:56:47 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/01/27 19:30:22 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
#define PUSH_SWAP_BONUS_H

#include "../include/push_swap.h"
#include "../ft_printf/ft_printf.h"
#include "../src_bonus/gnl/get_next_line.h"

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
} t_stk_ops;

// check_error_bonus.c
void	check_error_output(void);
int		check_no_output(void);
int_lst	*check_for_error(int argc, char *argv[]);

// checker_bonus.c
int	check_int_range_bonus(char *str);
int	argv_valid_bonus(char *argv[], int argc);
int	check_str_bonus(char *str);
int	ps_strcmp(char	*s1, char *opd);

// perform_operations_bonus.c
t_stk_ops	init_operations(void);
int	pfm_ops_helper_1(int_lst **st_a, int_lst **st_b, t_stk_ops ops, char *str);
int	pfm_ops_helper_2(int_lst **st_a, int_lst **st_b, t_stk_ops ops, char *str);
int	pfm_ops_helper_3(int_lst **st_a, int_lst **st_b, t_stk_ops ops, char *str);
int	perform_operands(int_lst **st_a, int_lst **st_b, int fd);

// list_bonus.c
int	lst_compare(int_lst	*lst_a, int_lst *lst_b);
#endif
