/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 03:06:27 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/01/15 20:41:42 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../ft_printf/ft_printf.h"

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

int		ft_isint(char *str);
int_lst	*ps_lstnew(int	val);
int_lst	*ps_lst_last(int_lst *lst);
void	ps_lst_clear(int_lst **lst);
void	ps_lst_add_back(int_lst **lst, int_lst *new);
void	ps_lst_add_front(int_lst **lst, int_lst *new);

// int_lst	*ft_lst_sort(int_lst **st_a, int_lst **st_b, int len);
// void	ft_push(int_lst **st_a, int_lst **st_b, char *px);
// int_lst *ft_ra(int_lst **st1);
// int_lst	*ft_rra(int_lst *st1);

// check Validity
int		is_sorted(int_lst *lst, t_sort sort);
int		argv_valid(char *argv[], int argc);
int		ft_is_dublicate(int_lst **st_a);
void	print_error(int n);
int		contains_space(char *str);
int		check_str(char *str);
int		check_int_range(char *str);

// operands
int_lst	*find_penultimate(int_lst *lst);
int_lst	*rev_rotate_x(int_lst **lst, char x, t_print status);
int_lst	*rotate_x(int_lst **lst, char x, t_print status);
int		push_x(int_lst **st_x, int_lst **st_y, char x, t_print status);
int_lst	*swap_x(int_lst	**lst, char x, t_print status);
int		ss(int_lst	**lst_a, int_lst **lst_b);

// merge sort
int		copy_lst(int_lst **new_lst, int_lst *lst);
// void	merge_sort_lst(int_lst **lst, int len);
int		divide_list(int_lst **lst, int_lst **half2, int mid);
int		copy_values(int_lst	**sorted, int_lst **cp1);
int		ft_merge(int_lst **half1, int_lst **half2);

// merge sort new
int_lst	*split_lst(int_lst *head);

// // temporary
void	ft_print_lst(int_lst *lst, char c);
int_lst	*merge_lst(int_lst *first, int_lst *second);
int_lst	*merge_sort_lst(int_lst *head);
int		find_median(int_lst *head);
int		ps_lst_len(int_lst *head);
int_lst *sort_asc(int_lst *st_a, int len);

// // quicksort - pt 1
// int		lst_partition_a(int_lst **st_a, int len, int_lst **st_b);
// int		lst_partition_b(int_lst **st_b, int len, int_lst **st_a);
// int_lst	*ps_qs_helper_a(int_lst **st_a, int len, int is_a, int_lst **st_b);
// int_lst	*ps_qs_helper_b(int_lst **st_b, int len, int is_a, int_lst **st_a);
// int_lst	*ps_quick_sort(int_lst **st_a);
// // quicksort - pt 2
// int		qs_copy_lst(int_lst **new_lst, int_lst *lst, int len);
// int		qs_find_median(int_lst *head, int len);
// int_lst	*ps_merge(int_lst **lst_a, int_lst **lst_b, int len, char c);

// // sort
// int_lst	*sort_desc(int_lst *st_a, int len);
// int	qs_is_sorted(int_lst *lst, t_sort sort, int len);

// quicksort
// int_lst	*ps_qs_split(int_lst **stack, int median, int len);
int_lst	*ps_quick_sort(int_lst **st_a);
int_lst	*sort_desc(int_lst *st_a, int len);
int_lst *ps_merge(int_lst **lst_a, int_lst **lst_b, int len, char c);

int	qs_copy_lst(int_lst **new_lst, int_lst *lst, int len);
int	qs_find_median(int_lst *head, int len);




int	qs_is_sorted(int_lst *lst, t_sort sort, int len);
#endif

