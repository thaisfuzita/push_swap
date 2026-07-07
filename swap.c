/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjulya-c <tjulya-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 13:20:42 by tjulya-c          #+#    #+#             */
/*   Updated: 2026/07/07 16:45:58 by tjulya-c         ###   ########.fr       */
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

void	ft_sa(t_stack **a, t_bench *benchmark)
{
	ft_swap(a);
	benchmark->sa++;
}

void	ft_sb(t_stack **b)
{
	ft_swap(b);
}

void	ft_ss(t_stack **a, t_stack **b)
{
	ft_swap(a);
	ft_swap(b);
}
