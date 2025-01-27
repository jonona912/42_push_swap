/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 03:06:27 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/01/27 12:20:50 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../ft_printf/ft_printf.h"

typedef struct i_list {
	int				value;
	struct i_list	*next;
} int_lst;

typedef struct s_stack
{
	int	a;
	int	rotate_a;
	int	rotate_b;
} t_stack;

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

// input checker - 1
int	check_int_range(char *str);
int	argv_valid(char *argv[], int argc);
int	ft_is_dublicate(int_lst **st_a);

// input checker - 2
int	is_sorted(int_lst *lst, t_sort sort);
void	print_error(int n);
int	contains_space(char *str);
int	check_str(char *str);
int	free_double_arr(char **str);

// lists_1.c
int_lst	*ps_lstnew(int val);
int_lst	*ps_lst_last(int_lst *lst);
void	ps_lst_add_back(int_lst **lst, int_lst *new);
void	ps_lst_add_front(int_lst **lst, int_lst *new);
void	ps_lst_clear(int_lst **lst);

// lists_2.c
int	ft_isint(char *str);
int	ps_lst_len(int_lst *head);
int	qs_is_sorted(int_lst *lst, t_sort sort, int len);

// main_helper.c
int	convert_add_lst(char *str, int_lst **lst);
void	create_lst_from_str(int_lst **lst, char *str);
int_lst	*make_num_lst(char *argv[], int argc);

// merge_sort_lst_1.c
int	divide_list(int_lst **lst, int_lst **half2, int mid);
int	copy_lst(int_lst **new_lst, int_lst *lst);
int	copy_values(int_lst	**sorted, int_lst **cp1);
int	ft_merge(int_lst **half1, int_lst **half2);

// merge_sort_lst_2.c
int_lst	*split_lst(int_lst *head);
int_lst	*merge_lst(int_lst *first, int_lst *second);
int_lst	*merge_sort_lst(int_lst *head);
int	find_median(int_lst *head);

// operands_1.c
int_lst	*find_penultimate(int_lst *lst);
int_lst	*rev_rotate_x(int_lst **lst, char x, t_print status);
int_lst	*rotate_x(int_lst **lst, char x, t_print status);
int	push_x(int_lst **st_x, int_lst **st_y, char x, t_print status);
int_lst	*swap_x(int_lst	**lst, char x, t_print status);

// operands_2.c
int	ss(int_lst	**lst_a, int_lst **lst_b, t_print status);
int	rr(int_lst	**lst_a, int_lst **lst_b, t_print status);
int	rrr(int_lst	**lst_a, int_lst **lst_b, t_print status);

// ps_qs_partition_a.c
void	ps_partition_rotate_a(int_lst **st_a, int_lst **st_b, int *n_rotates);
int	lst_part_a_helper(int_lst **st_a, int_lst **st_b, int len, int *len_b);
int	lst_partition_a(int_lst **st_a, int_lst **st_b, int len);

// ps_quick_sort_1.c
int	lst_partition_b(int_lst **st_b, int_lst **st_a, int len);
void ps_qs_helper(int_lst **st_a, int_lst **st_b, int len, int is_a);
int_lst	*ps_quick_sort(int_lst **st_a);

// ps_quick_sort_2.c
int	qs_copy_lst(int_lst **new_lst, int_lst *lst, int len);
int	qs_find_median(int_lst *head, int len);
int_lst	*ps_merge(int_lst **lst_b, int_lst **lst_a, int len, char c);
int	is_stack_b_rot(int_lst *lst);

// ps_quick_sort_helper.c
int	check_for_less(int_lst *lst, int num);
int	check_for_great_eq(int_lst *lst, int num);
int	is_sorted_beyond(int_lst *lst, int len);
int_lst	*find_max_beyond_len(int_lst *lst, int len);
int	find_bigger_num(int_lst *lst, int len, int_lst *max_nd);

// ps_quick_sort_helper_2.c
void	sort_both_stacks(int_lst **st_a, int_lst **st_b, int len, int is_a);
void	ps_set_part_len(int	len, int is_a, int *len_a, int *len_b);

// ps_sort_asc.c
int		sort_needed_asc(int_lst **st_a, int_lst **st_b, int len);
void	rev_rot_sor_helper(int_lst **st_a, int_lst **st_b);
int_lst	*sort_3_null_asc(int_lst **st_a, int_lst **st_b, int len);
int_lst	*sort_3_asc(int_lst **st_a, int_lst **st_b, int len);
int_lst	*sort_asc(int_lst **st_a, int_lst **st_b, int len);

// ps_sort_desc.c
int	sort_needed_desc(int_lst **st_a, int_lst **st_b, int len);
int_lst	*sort_3_null_desc(int_lst **st_a, int_lst **st_b, int len);
int_lst	*sort_3_desc(int_lst **st_a, int_lst **st_b, int len);
int_lst	*sort_desc(int_lst **st_a, int_lst **st_b, int len);

// ps_sort_helper.c
int	double_swapped(int_lst **st_a, int_lst **st_b);
int	set_nums(int_lst *lst, int len, int *sd, int *td);

#endif

