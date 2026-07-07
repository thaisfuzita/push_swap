/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjulya-c <tjulya-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 14:31:23 by tjulya-c          #+#    #+#             */
/*   Updated: 2026/07/07 14:02:36 by tjulya-c         ###   ########.fr       */
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

	numbers = parse_numbers(argc, argv, &count, &benchmark);
	init_stack(&a);
	init_stack(&b);
	populate(&a, numbers, count);
	free(numbers);
	if (is_ordered(a))
		return (0);
	/*ordenar */
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
