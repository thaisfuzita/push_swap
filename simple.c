/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrique <hrique@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 18:11:26 by hrique            #+#    #+#             */
/*   Updated: 2026/07/09 21:15:15 by hrique           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	index_normalize(t_stack	*a)
{
	t_node	*node_a;
	t_node	*node_b;
	int		count;
	int		x;

	if (a->size <= 1)
		return ;
	node_a = a->top;
	node_b = node_a;
	x = a->size - 1;
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
		if (node_a->index)
		node_a = node_a->next;
		node_b = a->top;
	}
}
