/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrique <hrique@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 18:11:26 by hrique            #+#    #+#             */
/*   Updated: 2026/07/11 13:09:48 by hrique           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		{
			min_node = temp;
		}
		temp =	temp->next;
	}
	return (min_node);
}

t_node	*simple_order(t_stack *a, t_stack *b)
{
	int		i;
	int 	moves;
	t_node	*min_node;

	if (!a || a->size <= 1)
		return (a->top);
	i = 0;
	min_node = find_min(a, sorted);
	moves = count_distance(a->top, min_node);
	if (moves < (a->size - moves))
		while (i < moves)
		{
			ft_ra(a);
			i++;
		}
	else
		while (i < (a->size - moves))
		{
			ft_r_ra(a);
			i++;
		}
	if (a->top == min_node)
		ft_pb(a, b);
	return (min_node);
}

void	selection_sort(t_stack *a, t_stack *b)
{
	t_node	*sorted;

	if (!a || a->size <= 1)
		return (a->top);
	sorted = NULL;
	while (a->size > 1)
	{
		sorted = simple_order(a, b);
	}
	while (b->size > 0)
		ft_pa(a, b);
}
