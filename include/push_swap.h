/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 03:06:27 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/01/27 20:21:36 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../ft_printf/ft_printf.h"

typedef struct i_list
{
	int				value;
	struct i_list	*next;
}	t_ps_lst;

typedef struct s_stack
{
	int	a;
	int	rotate_a;
	int	rotate_b;
}	t_stack;

typedef enum s_print
{
	NOTPRINT = 0,
	PRINT
}	t_print;

typedef enum s_sort
{
	ASC = 0,
	DESC
}	t_sort;

// input checker - 1
int			check_int_range(char *str);
int			argv_valid(char *argv[], int argc);
int			ft_is_dublicate(t_ps_lst **st_a);

// input checker - 2
int			is_sorted(t_ps_lst *lst, t_sort sort);
void		print_error(int n);
int			contains_space(char *str);
int			check_str(char *str);
int			free_double_arr(char **str);

// lists_1.c
t_ps_lst	*ps_lstnew(int val);
t_ps_lst	*ps_lst_last(t_ps_lst *lst);
void		ps_lst_add_back(t_ps_lst **lst, t_ps_lst *new);
void		ps_lst_add_front(t_ps_lst **lst, t_ps_lst *new);
void		ps_lst_clear(t_ps_lst **lst);

// lists_2.c
int			ft_isint(char *str);
int			ps_lst_len(t_ps_lst *head);
int			qs_is_sorted(t_ps_lst *lst, t_sort sort, int len);

// main_helper.c
int			convert_add_lst(char *str, t_ps_lst **lst);
void		create_lst_from_str(t_ps_lst **lst, char *str);
t_ps_lst	*make_num_lst(char *argv[], int argc);

// merge_sort_lst_1.c
int			divide_list(t_ps_lst **lst, t_ps_lst **half2, int mid);
int			copy_lst(t_ps_lst **new_lst, t_ps_lst *lst);
int			copy_values(t_ps_lst	**sorted, t_ps_lst **cp1);
int			ft_merge(t_ps_lst **half1, t_ps_lst **half2);

// merge_sort_lst_2.c
t_ps_lst	*split_lst(t_ps_lst *head);
t_ps_lst	*merge_lst(t_ps_lst *first, t_ps_lst *second);
t_ps_lst	*merge_sort_lst(t_ps_lst *head);
int			find_median(t_ps_lst *head);

// operands_1.c
t_ps_lst	*find_penultimate(t_ps_lst *lst);
t_ps_lst	*rev_rotate_x(t_ps_lst **lst, char x, t_print status);
t_ps_lst	*rotate_x(t_ps_lst **lst, char x, t_print status);
int			push_x(t_ps_lst **st_x, t_ps_lst **st_y, char x, t_print status);
t_ps_lst	*swap_x(t_ps_lst	**lst, char x, t_print status);

// operands_2.c
int			ss(t_ps_lst	**lst_a, t_ps_lst **lst_b, t_print status);
int			rr(t_ps_lst	**lst_a, t_ps_lst **lst_b, t_print status);
int			rrr(t_ps_lst	**lst_a, t_ps_lst **lst_b, t_print status);

// ps_qs_partition_a.c
void		ps_ptn_rot_a(t_ps_lst **st_a, t_ps_lst **st_b, int *n_rotates);
int			lst_a_hpr(t_ps_lst **st_a, t_ps_lst **st_b, int len, int *len_b);
int			lst_partition_a(t_ps_lst **st_a, t_ps_lst **st_b, int len);

// ps_quick_sort_1.c
int			lst_partition_b(t_ps_lst **st_b, t_ps_lst **st_a, int len);
void		ps_qs_helper(t_ps_lst **st_a, t_ps_lst **st_b, int len, int is_a);
t_ps_lst	*ps_quick_sort(t_ps_lst **st_a);

// ps_quick_sort_2.c
int			qs_copy_lst(t_ps_lst **new_lst, t_ps_lst *lst, int len);
int			qs_find_median(t_ps_lst *head, int len);
t_ps_lst	*ps_merge(t_ps_lst **lst_b, t_ps_lst **lst_a, int len, char c);
int			is_stack_b_rot(t_ps_lst *lst);

// ps_quick_sort_helper.c
int			check_for_less(t_ps_lst *lst, int num);
int			check_for_great_eq(t_ps_lst *lst, int num);
int			is_sorted_beyond(t_ps_lst *lst, int len);
t_ps_lst	*find_max_beyond_len(t_ps_lst *lst, int len);
int			find_bigger_num(t_ps_lst *lst, int len, t_ps_lst *max_nd);

// ps_quick_sort_helper_2.c
void		sort_b_stacks(t_ps_lst **st_a, t_ps_lst **st_b, int len, int is_a);
void		ps_set_part_len(int len, int is_a, int *len_a, int *len_b);

// ps_sort_asc.c
int			sort_needed_asc(t_ps_lst **st_a, t_ps_lst **st_b, int len);
void		rev_rot_sor_helper(t_ps_lst **st_a, t_ps_lst **st_b);
t_ps_lst	*sort_3_null_asc(t_ps_lst **st_a, t_ps_lst **st_b, int len);
t_ps_lst	*sort_3_asc(t_ps_lst **st_a, t_ps_lst **st_b, int len);
t_ps_lst	*sort_asc(t_ps_lst **st_a, t_ps_lst **st_b, int len);

// ps_sort_desc.c
int			sort_needed_desc(t_ps_lst **st_a, t_ps_lst **st_b, int len);
t_ps_lst	*sort_3_null_desc(t_ps_lst **st_a, t_ps_lst **st_b, int len);
t_ps_lst	*sort_3_desc(t_ps_lst **st_a, t_ps_lst **st_b, int len);
t_ps_lst	*sort_desc(t_ps_lst **st_a, t_ps_lst **st_b, int len);

// ps_sort_helper.c
int			double_swapped(t_ps_lst **st_a, t_ps_lst **st_b);
int			set_nums(t_ps_lst *lst, int len, int *sd, int *td);

#endif
