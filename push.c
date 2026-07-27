/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrique <hrique@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 13:21:20 by tjulya-c          #+#    #+#             */
/*   Updated: 2026/07/11 18:50:40 by hrique           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	change_top_bot(t_stack *x, t_node *new)
{
	x->top = new;
	x->bottom = new;
}

static void	ft_push(t_stack *src, t_stack *dst)
{
	t_node	*move;

	if (src->size == 0)
		return ;
	move = src->top;
	src->top = move->next;
	if (src->top)
		src->top->prev = NULL;
	else
		change_top_bot(src, NULL);
	src->size--;
	move->next = NULL;
	move->prev = NULL;
	if (dst->top)
	{
		dst->top->prev = move;
		move->next = dst->top;
		dst->top = move;
	}
	else
		change_top_bot(dst, move);
	dst->size++;
}

void	ft_pa(t_stack *a, t_stack *b, t_bench *benchmark)
{
	if (b->size == 0)
		return ;
	ft_push(b, a);
	print_op("pa", benchmark);
	benchmark->pa++;
	benchmark->total_ops++;
}

void	ft_pb(t_stack *a, t_stack *b, t_bench *benchmark)
{
	if (a->size == 0)
		return ;
	ft_push(a, b);
	print_op("pb", benchmark);
	benchmark->pb++;
	benchmark->total_ops++;
}
