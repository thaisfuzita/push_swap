/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrique <hrique@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 13:20:42 by tjulya-c          #+#    #+#             */
/*   Updated: 2026/07/09 12:31:25 by hrique           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *x)
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
	ft_swap(a);
	benchmark->sa++;
	benchmark->total_ops++;
}

void	ft_sb(t_stack *b, t_bench *benchmark)
{
	ft_swap(b);
	benchmark->sb++;
	benchmark->total_ops++;
}

void	ft_ss(t_stack *a, t_stack *b, t_bench *benchmark)
{
	ft_swap(a);
	ft_swap(b);
	benchmark->sa++;
	benchmark->sb++;
	benchmark->total_ops++;
}
