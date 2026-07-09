/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaisfuzita <thaisfuzita@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 14:31:23 by tjulya-c          #+#    #+#             */
/*   Updated: 2026/07/09 12:10:13 by thaisfuzita      ###   ########.fr       */
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
		return (check_error(count), 0);
	init_stack(&a);
	init_stack(&b);
	init_bench(&benchmark);
	populate(&a, numbers, count);
	order()
	{
	
	}
	free_all(&a, &b, numbers);
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

/*int main(int argc, char **argv)
{
	int	i;
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
	i = 0;
	while (i < count)
	{
		ft_putnbr_fd(numbers[i], 2);
		write(2, "\n", 1);
		i++;
	}
	return (0);
}*/
