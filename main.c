/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riks <riks@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 14:31:23 by tjulya-c          #+#    #+#             */
/*   Updated: 2026/07/11 15:10:00 by riks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stack(t_stack *x)
{
	x->size = 0;
	x->top = NULL;
	x->bottom = NULL;
}

static t_node	*new_node(int value)
{
	t_node *nd;
	
	nd = malloc(sizeof(t_node));
	if (!nd)
		return (NULL);
	nd->value = value;
	nd->index = 0;
	nd->next = NULL;
	nd->prev = NULL;
	return (nd);
}

static int	populate(t_stack *a, int *numbers, int count)
{
	t_node *nd;
	int	i;

	i = count - 1;
	while (i >= 0)
	{
		nd = new_node(numbers[i]);
		if (!nd)
			return (1);
		if (a->bottom == NULL)
		{
			a->bottom = nd;
			a->top = nd;
		}
		else
		{
			a->top->prev = nd;
			nd->next = a->top;
			a->top = nd;
		}
		a->size++;
		i--;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_bench	bm;
	int		*numbers;
	int		count;

	if (argc < 2)
		return (0);
	init_bench(&bm);
	numbers = parse_numbers(argc, argv, &count, &bm);
	if (!numbers)
		return (check_error(count), 1);
	if (count < 2)
		return (0);
	init_stack(&a);
	init_stack(&b);
	if (populate(&a, numbers, count) == 0)
		ordernation(&a, &b, &bm);
	free_all(&a, &b, numbers);
	return (0);
}
