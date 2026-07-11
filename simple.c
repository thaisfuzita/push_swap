/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrique <hrique@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 18:11:26 by hrique            #+#    #+#             */
/*   Updated: 2026/07/10 23:39:53 by hrique           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_normalize(t_stack	*a)
{
	t_node	*node_a;
	t_node	*node_b;
	t_node	*min_node;
	int		count;

	if (a->size <= 1)
		return ;
	node_a = a->top;
	node_b = node_a;
	while (node_a)
	{
		count = 0;
		while (node_b)
		{
			if (node_a->value > node_b->value)
				count++;
			node_b = node_b->next;
		}
		node_a->index = count;
		if (count == 0)
			min_node = node_a;
		node_a = node_a->next;
		node_b = a->top;
	}
}

int	count_distance(t_node *top, t_node *min_node)
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

void	simple_order(t_stack *a)
{
	int	i;
	int moves;

	i = 0
	moves = count_distance(a->top, min_node);
	if (moves < (size - moves))
		while (i < moves)
		{
			ft_ra(a);
			i++;
		}
	else
		while (i < size - moves)
		{
			ft_r_ra(a);
			i++;
		}
}

t_node	*find_min(t_stack *a)
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
			min_node = temp;
		temp =	temp->next; 
	}
	return (min_node);
}
