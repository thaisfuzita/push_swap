/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjulya-c <tjulya-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 14:31:23 by tjulya-c          #+#    #+#             */
/*   Updated: 2026/07/07 16:52:46 by tjulya-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_bench	benchmark;
	int		*numbers;
	int		count;

	if (argc < 2)
		return (0);
	numbers = parse_numbers(argc, argv, &count, &benchmark);
	if (!numbers)
	{
		if (count == -1)
			write (2, "Error\n", 6);
		return (0);
	}
	init_stack(&a);
	init_stack(&b);
	populate(&a, numbers, count);
	order()
	{
	
	}
	free_all();
	return (0);
}

void	init_stack(t_stack *x)
{
	x->size = 0;
	x->top = NULL;
	x->bottom = NULL;
}

void	populate(t_stack *x, int *numbers, int count)
{
	
}

int	is_ordered(t_stack x)
{
	
}
order()
{
	exec_mode()
}

exec_mode()
{
	is_ordered();
}