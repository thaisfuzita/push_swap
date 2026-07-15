/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesantan <hesantan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 18:11:26 by hrique            #+#    #+#             */
/*   Updated: 2026/07/15 15:30:31 by hesantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_distance(t_node *top, t_node *min_node)
{
	int		moves;
	t_node	*temp;

	moves = 0;
	temp = top;
	while (temp != min_node)
	{
		temp = temp->next;
		moves++;
	}
	return (moves);
}

static t_node	*find_min(t_stack *a)
{
	t_node	*temp;
	t_node	*min_node;

	if (!a || a->size <= 1)
		return (a->top);
	temp = a->top;
	min_node = temp;
	while (temp)
	{
		if (temp->value < min_node->value)
		{
			min_node = temp;
		}
		temp = temp->next;
	}
	return (min_node);
}

static void	simple_order(t_stack *a, t_stack *b, t_bench *bm)
{
	int		i;
	int		moves;
	t_node	*min_node;

	if (!a || a->size <= 1)
		return ;
	i = 0;
	min_node = find_min(a);
	moves = count_distance(a->top, min_node);
	if (moves < (a->size - moves))
	{
		while (i++ < moves)
			ft_ra(a, bm);
	}
	else
	{
		while (i++ < (a->size - moves))
			ft_r_ra(a, bm);
	}
	if (a->top == min_node)
		ft_pb(a, b, bm);
}

void	simple(t_stack *a, t_stack *b, t_bench *bm)
{
	int	total;

	if (!a || a->size <= 1)
		return ;
	print_both(a, b);
	while (a->size > 1)
		simple_order(a, b, bm);
	while (b->size > 0)
		ft_pa(a, b, bm);
	total = bm->total_ops;
	ft_printf("total: %i\n", total);
	print_both(a, b);
}
