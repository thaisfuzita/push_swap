/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_bit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesantan <hesantan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 23:43:56 by riks              #+#    #+#             */
/*   Updated: 2026/07/15 17:15:22 by hesantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_by_bit(t_stack *a, t_stack *b, int bit)
{
    int	size;
	int	i;
	
	size = a->size;
	i = 0;
	while (i < size - 1)
	{
		if (get_bit(a->top->index, bit) == 0)
			ft_pb(a, b);
		else
			ft_ra(a);
	}
	while (b->size > 0)
		ft_pa(a, b);
}
