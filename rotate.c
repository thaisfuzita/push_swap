/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrique <hrique@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 13:22:37 by tjulya-c          #+#    #+#             */
/*   Updated: 2026/07/11 18:55:21 by hrique           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_stack *x)
{
	t_node	*old_top;
	t_node	*new_top;

	if (x->size <= 1)
		return ;
	old_top = x->top;
	new_top = x->top->next;
	x->bottom->next = x->top;
	x->top->prev = x->bottom;
	new_top->prev = NULL;
	old_top->next = NULL;
	x->top = new_top;
	x->bottom = old_top;
}

void	ft_ra(t_stack *a, t_bench *benchmark)
{
	if (a->size <= 1)
		return ;
	ft_rotate(a);
	print_op("ra", benchmark);
	benchmark->ra++;
	benchmark->total_ops++;
}

void	ft_rb(t_stack *b, t_bench *benchmark)
{
	if (b->size <= 1)
		return ;
	ft_rotate(b);
	print_op("rb", benchmark);
	benchmark->rb++;
	benchmark->total_ops++;
}

void	ft_rr(t_stack *a, t_stack *b, t_bench *benchmark)
{
	if (a->size <= 1 && b->size <= 1)
		return ;
	ft_rotate(a);
	ft_rotate(b);
	print_op("rr", benchmark);
	benchmark->rr++;
	benchmark->total_ops++;
}
