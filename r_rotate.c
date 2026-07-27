/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrique <hrique@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 13:22:44 by tjulya-c          #+#    #+#             */
/*   Updated: 2026/07/11 18:54:29 by hrique           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_r_rotate(t_stack *x)
{
	t_node	*old_top;
	t_node	*old_bottom;
	t_node	*new_bottom;

	if (x->size <= 1)
		return ;
	old_top = x->top;
	old_bottom = x->bottom;
	new_bottom = x->bottom->prev;
	old_top->prev = old_bottom;
	old_bottom->next = old_top;
	new_bottom->next = NULL;
	old_bottom->prev = NULL;
	x->top = old_bottom;
	x->bottom = new_bottom;
}

void	ft_r_ra(t_stack *a, t_bench *benchmark)
{
	if (a->size <= 1)
		return ;
	ft_r_rotate(a);
	print_op("rra", benchmark);
	benchmark->rra++;
	benchmark->total_ops++;
}

void	ft_r_rb(t_stack *b, t_bench *benchmark)
{
	if (b->size <= 1)
		return ;
	ft_r_rotate(b);
	print_op("rrb", benchmark);
	benchmark->rrb++;
	benchmark->total_ops++;
}

void	ft_r_rr(t_stack *a, t_stack *b, t_bench *benchmark)
{
	if (a->size <= 1 && b->size <= 1)
		return ;
	ft_r_rotate(a);
	ft_r_rotate(b);
	print_op("rrr", benchmark);
	benchmark->rrr++;
	benchmark->total_ops++;
}