int_lst	*sort_3_null_asc(int_lst **st_a, int_lst **st_b)
{
	int		ft;
	int		sd;
	int		td;

	ft = (*st_a)->value;
	sd = (*st_a)->next->value;
	td = (*st_a)->next->next->value;
	if (ft < sd && sd > td && ft > td) // 2 3 1
		rev_rotate_x(st_a, 'a', PRINT);
	else if (ft > sd && sd > td) // 3 2 1 same operations as 1 2 3
	{
		rotate_x(st_a, 'a', PRINT);
		swap_x(st_a, 'a', PRINT);
	}
	else if (ft > sd && ft < td) // 2 1 3
		return (swap_x(st_a, 's', PRINT));
	else if (ft > sd && ft > td && sd < td) // 3 1 2
		rotate_x(st_a, 'a', PRINT);
	else if (ft < sd && ft < td && sd > td) // 1 3 2
	{
		swap_x(st_a, 'a', PRINT);
		rotate_x(st_a, 'a', PRINT);
	}
	return (*st_a);
}

int_lst	*sort_3_asc(int_lst **st_a, int_lst **st_b)
{
	int		ft;
	int		sd;
	int		td;

	ft = (*st_a)->value;
	sd = (*st_a)->next->value;
	td = (*st_a)->next->next->value;
	if (ft < sd && sd > td && ft > td) // 2 3 1
	{
		push_x(st_a, st_b, 'b', PRINT);
		swap_x(st_a, 'b', PRINT);
		push_x(st_b, st_a, 'a', PRINT);
		swap_x(st_a, 'b', PRINT);
	}
	else if (ft > sd && sd > td) // 3 2 1 same operations as 1 2 3
	{
		push_x(st_a, st_b, 'b', PRINT);
		push_x(st_a, st_b, 'b', PRINT);
		swap_x(st_b, 'b', PRINT);
		push_x(st_a, st_b, 'b', PRINT);
		swap_x(st_b, 'b', PRINT);
		push_x(st_b, st_a, 'a', PRINT);
		swap_x(st_b, 'b', PRINT);
		push_x(st_b, st_a, 'a', PRINT);
		push_x(st_b, st_a, 'a', PRINT);
	}
	else if (ft > sd && ft < td) // 2 1 3
		swap_x(st_a, 's', PRINT);
	else if (ft > sd && ft > td && sd < td) // 3 1 2
	{
		swap_x(st_a, 'a', PRINT);
		push_x(st_a, st_b, 'b', PRINT);
		swap_x(st_a, 'a', PRINT);
		push_x(st_b, st_a, 'a', PRINT);
	}
	else if (ft < sd && ft < td && sd > td) // 1 3 2
	{
		push_x(st_a, st_b, 'b', PRINT);
		swap_x(st_a, 'a', PRINT);
		push_x(st_b, st_a, 'a', PRINT);
	}
	return (*st_a);
}
