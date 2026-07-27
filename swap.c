/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrique <hrique@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 13:20:42 by tjulya-c          #+#    #+#             */
/*   Updated: 2026/07/11 18:57:29 by hrique           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack *x)
{
	int	temp;

	if (!x->top || !x->top->next)
		return ;
	temp = x->top->value;
	x->top->value = x->top->next->value;
	x->top->next->value = temp;
}

void	ft_sa(t_stack *a, t_bench *benchmark)
{
	if (!a->top || !a->top->next)
		return ;
	ft_swap(a);
	print_op("sa", benchmark);
	benchmark->sa++;
	benchmark->total_ops++;
}

void	ft_sb(t_stack *b, t_bench *benchmark)
{
	if (!b->top || !b->top->next)
		return ;
	ft_swap(b);
	print_op("sb", benchmark);
	benchmark->sb++;
	benchmark->total_ops++;
}

void	ft_ss(t_stack *a, t_stack *b, t_bench *benchmark)
{
	if ((!a->top || !a->top->next) && (!b->top || !b->top->next))
		return ;
	ft_swap(a);
	ft_swap(b);
	print_op("ss", benchmark);
	benchmark->ss++;
	benchmark->total_ops++;
}
