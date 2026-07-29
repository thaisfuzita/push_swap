/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjulya-c <tjulya-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 15:03:10 by tjulya-c          #+#    #+#             */
/*   Updated: 2026/07/29 16:27:20 by tjulya-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	order_two(t_stack *a, t_bench *bm)
{
	ft_ra(a, bm);
}

static void	order_three(t_stack *a, t_bench *bm)
{
	index_normalize(a);
	if (a->top->index == 0)
	{
		ft_sa(a, bm);
		ft_ra(a, bm);
	}
	else if (a->top->index == 1)
	{
		if (a->top->next->index == 0)
			ft_sa(a, bm);
		else
			ft_r_ra(a, bm);
	}
	else
	{
		if (a->top->next->index == 0)
			ft_ra(a, bm);
		else
		{
			ft_sa(a, bm);
			ft_r_ra(a, bm);
		}
	}
}

static void	order_four(t_stack *a, t_stack *b, t_bench *bm)
{
	index_normalize(a);
	if (a->bottom->index == 0)
		ft_r_ra(a, bm);
	else if (a->bottom->prev->index == 0)
	{
		ft_r_ra(a, bm);
		ft_r_ra(a, bm);
	}
	while (a->top->index != 0)
		ft_ra(a, bm);
	ft_pb(a, b, bm);
	order_three(a, bm);
	ft_pa(a, b, bm);
}

static void	order_five(t_stack *a, t_stack *b, t_bench *bm)
{
	index_normalize(a);
	if (a->bottom->index == 0)
		ft_r_ra(a, bm);
	else if (a->bottom->prev->index == 0)
	{
		ft_r_ra(a, bm);
		ft_r_ra(a, bm);
	}
	while (a->top->index != 0)
		ft_ra(a, bm);
	ft_pb(a, b, bm);
	order_four(a, b, bm);
	ft_pa(a, b, bm);
}

void	decide_small_ordenation(t_stack *a, t_stack *b, t_bench *bm)
{
	int	size;

	size = a->size;
	if (size == 2)
		order_two(a, bm);
	else if (size == 3)
		order_three(a, bm);
	else if (size == 4)
		order_four(a, b, bm);
	else
		order_five(a, b, bm);
}
