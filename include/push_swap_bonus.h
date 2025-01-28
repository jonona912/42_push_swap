/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:56:47 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/01/27 21:00:04 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../include/push_swap.h"
# include "../ft_printf/ft_printf.h"
# include "../src_bonus/gnl/get_next_line.h"

typedef struct s_stack_operations
{
	char	*sa;
	char	*sb;
	char	*ss;
	char	*pa;
	char	*pb;
	char	*ra;
	char	*rb;
	char	*rr;
	char	*rra;
	char	*rrb;
	char	*rrr;
}	t_stk_ops;

// check_error_bonus.c
void		check_error_output(void);
int			check_no_output(void);
t_ps_lst	*check_for_error(int argc, char *argv[]);

// checker_bonus.c
int			check_int_range_bonus(char *str);
int			argv_valid_bonus(char *argv[], int argc);
int			check_str_bonus(char *str);
int			ps_strcmp(char	*s1, char *opd);

// perform_operations_bonus.c
t_stk_ops	init_operations(void);
int			p_hpr_1(t_ps_lst **st_a, t_ps_lst **st_b, t_stk_ops ops, char *str);
int			p_hpr_2(t_ps_lst **st_a, t_ps_lst **st_b, t_stk_ops ops, char *str);
int			p_hpr_3(t_ps_lst **st_a, t_ps_lst **st_b, t_stk_ops ops, char *str);
int			pfm_ops(t_ps_lst **st_a, t_ps_lst **st_b, t_ps_lst **s, int fd);

// list_bonus.c
int			lst_compare(t_ps_lst	*lst_a, t_ps_lst *lst_b);

// push_swap_bonus.c
void		m_h(t_ps_lst **st_a, t_ps_lst **st_b, t_ps_lst **sorted, int i_l);

#endif
