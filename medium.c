/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrique <hrique@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 17:31:20 by thaisfuzita       #+#    #+#             */
/*   Updated: 2026/07/11 19:14:34 by hrique           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	chunk_size(t_stack *a, int index)
{
	int	size;
	t_node	*nd;

	size = 0;
	nd = a->top;
	while (nd != NULL)
	{
		if (nd->index == index)
			size++;
		nd = nd->next;
	}
	return (size);
}

static void	shortest_rotation(t_stack *x, t_bench *bm, int i, 
		void (*rot)(t_stack *, t_bench *), void (*r_rot)(t_stack *, t_bench *))
{
	int	place;
	t_node	*nd;
	
	place = 0;
	nd = x->top;
	while (nd->index != i)
	{
		nd = nd->next;
		place++;
	}
	if (place > x->size / 2)
	{
		while (nd != x->top)
			r_rot(x, bm);
	}
	else
	{
		while (nd != x->top)
			rot(x, bm);
	}
}

static void	insert_in_order(t_stack *a, t_stack *b, t_bench *bm, int value)
{
	int	rotates;
	t_node	*b_nd;

	rotates = 0;
	b_nd = b->top;
	while (b_nd != NULL && value < b_nd->value && rotates < b->size)
	{
		ft_rb(b, bm);
		rotates++;
		b_nd = b->top;
	}
	ft_pb(a, b, bm);
	while (rotates != 0)
	{
		ft_r_rb(b, bm);
		rotates--;
	}
}

static void	order_chunk(t_stack *a, t_stack *b, t_bench *bm, int chunk)
{
	t_node	*nd;
	int		c_size;
	int		i;
	int		j;

	i = 0;
	while (i < chunk)
	{
		j = 0;
		c_size = chunk_size(a, i);
		nd = a->top;
		while (j < c_size)
		{
			if (nd->index == i)
			{
				insert_in_order(a, b, bm, nd->value);
				j++;
			}
			else
				shortest_rotation(a, bm, i, ft_ra, ft_r_ra);
		}
		i++;
	}
}

void	medium(t_stack *a, t_stack *b, t_bench *bm)
{
	int	chunk;
	int	max;
	int	min;
	int	range;
	int	total;

	chunk_limits(a, &min, &max);
	chunk = ft_sqrt(a->size);
	range = (max - min + chunk - 1) / chunk;
	set_chunk(a, min, range, chunk);
	order_chunk(a, b, bm, chunk);
	while (b->size != 0)
		ft_pa(a, b, bm);
	total = bm->total_ops;
	ft_printf("total: %i\n", total);
}
