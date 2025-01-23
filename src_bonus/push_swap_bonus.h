/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:05:16 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/01/23 12:47:18 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
#define PUSH_SWAP_BONUS_H

#include "push_swap_bonus.h"
#include "../ft_printf/ft_printf.h"

typedef struct s_stack_operations {
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

typedef struct i_list {
	int				value;
	struct i_list	*next;
} int_lst;

typedef enum s_print
{
	NOTPRINT = 0,
	PRINT
} t_print;

typedef enum s_sort
{
	ASC = 0,
	DESC
} t_sort;

// push_swap_bonus
int_lst	*make_num_lst(char *argv[], int argc);
void	create_lst_from_str(int_lst **lst, char *str);



int	check_int_range_bonus(char *str);
int	argv_valid_bonus(char *argv[], int argc);
int	ft_is_dublicate(int_lst **st_a);


int	lst_compare(int_lst	*lst_a, int_lst *lst_b);
int	perform_operands(int_lst **st_a, int_lst **st_b);
t_stack_operations init_operations();
int_lst	*check_for_error(int argc, char *argv[]);
void	check_no_output();
void	check_error_output();

// input chekcer 2
int	check_str_bonus(char *str);
void	print_error(int n);
int	is_sorted(int_lst *lst, t_sort sort);
int	contains_space(char *str);
int	free_double_arr(char **str);

// mergesort
int	divide_list(int_lst **lst, int_lst **half2, int mid);
int	copy_lst(int_lst **new_lst, int_lst *lst);
int	copy_values(int_lst	**sorted, int_lst **cp1);
int	ft_merge(int_lst **half1, int_lst **half2);

int_lst	*split_lst(int_lst *head);
int_lst	*merge_lst(int_lst *first, int_lst *second);
int_lst	*merge_sort_lst(int_lst *head);
int	find_median(int_lst *head);

// operands
int_lst	*find_penultimate(int_lst *lst);
int_lst	*rev_rotate_x(int_lst **lst, char x, t_print status);
int_lst	*rotate_x(int_lst **lst, char x, t_print status);
int	push_x(int_lst **st_x, int_lst **st_y, char x, t_print status);
int_lst	*swap_x(int_lst	**lst, char x, t_print status);

int	ss(int_lst	**lst_a, int_lst **lst_b, t_print status);
int	rr(int_lst	**lst_a, int_lst **lst_b, t_print status);
int	rrr(int_lst	**lst_a, int_lst **lst_b, t_print status);


//lists
int_lst	*ps_lstnew(int val);
int_lst	*ps_lst_last(int_lst *lst);
void	ps_lst_add_back(int_lst **lst, int_lst *new);
void	ps_lst_add_front(int_lst **lst, int_lst *new);
void	ps_lst_clear(int_lst **lst);

int	ft_isint(char *str);
int	ps_lst_len(int_lst *head);


#endif