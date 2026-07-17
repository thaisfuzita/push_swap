/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_normalize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrique <hrique@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 11:10:32 by hrique            #+#    #+#             */
/*   Updated: 2026/07/11 11:13:26 by hrique           ###   ########.fr       */
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
