int_lst	*ps_qs_helper(int_lst **st_a, int median, int len, int is_a, int_lst **st_b)
{
	// int_st_a	*st_a_b;
	int		len_a;
	int		median_a;
	int		len_b;
	int		median_b;

	// printf("len: %d is_a: %d\n", len, is_a);
	// ft_print_st_a(*st_a, 'a');
	// ft_print_st_a(*st_b, 'b');  n
	if (len < 4 && is_a == 1)
		return (sort_asc(*st_a, len));
	else if (len < 4)
		return (sort_desc(*st_a, len));
	// // median can be counted beforehand if len is known...
	len_b = lst_partition(st_a, median, len, st_b);
	len_a = len - len_b;
	// len_a = ps_st_a_len(*st_a);
	median_a = qs_find_median(*st_a, len_a);
	// le	n_b = ps_st_a_len(st_a_b);
	median_b = qs_find_median(*st_b, len_b);

	*st_a = ps_qs_helper(st_a, median_a, len_a, 1, st_b);
	// ft_print_st_a(*st_b, '/');
	*st_b = ps_qs_helper(st_b, median_b, len_b, 0, st_a);
	// ft_print_st_a(*st_b, 'b');
	if (is_a == 1)
	{
		return (ps_merge(st_a, st_b, len_b, 'a'));
	}
	else
	{
		return (ps_merge(st_a, st_b, len_a, 'b'));
	}
}

// // only one wing

// int_lst *ps_qs_helper(int_lst **st_a, int_lst **st_b, int len_a, int len_b)
// {
// 	int	median_a;
// 	int	len_temp;
// 	int	median_b;
// 	int	len_temp_2;

// 	if (len_a < 4)
// 			sort_asc(st_a, len_a);
// 	if (len_b < 4)
// 		return (sort_desc(st_b, len_b));
// 	else if (len_a > 3 || len_a > 3)
// 	{
// 		median_a = qs_find_median(*st_a, len_a);
// 		len_temp = lst_partition(st_a, median_a, len_a, st_b);
// 		len_a = len_a - len_temp;
// 		ps_qs_helper(st_a, st_b, len_a, len_temp);

// 		median_b = qs_find_median(*st_b, len_b);
// 		len_temp_2 = lst_partition(st_b, median_b, len_b, st_a);  // // here partition is towards st_a,
// 		ps_qs_helper(st_a, st_b, len_temp_2, len_b - len_temp_2);
// 		ps_merge(st_a, st_b, len_b);
// 		// len_temp = partition();

// 		// will keep pushing them


// 	}
// }
