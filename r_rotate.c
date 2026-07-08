/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrique <hrique@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 13:22:44 by tjulya-c          #+#    #+#             */
/*   Updated: 2026/07/08 16:20:59 by hrique           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_r_rotate(t_stack *x)
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

void	ft_rra(t_stack *a)
{
	ft_r_rotate(a);
}

void	ft_rrb(t_stack *b)
{
	ft_r_rotate(b);
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_r_rotate(a);
	ft_r_rotate(b);
}