/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesantan <hesantan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 13:22:37 by tjulya-c          #+#    #+#             */
/*   Updated: 2026/07/07 17:17:00 by hesantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack *x)
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

void	ft_ra(t_stack *a)
{
	ft_rotate(a);
}

void	ft_rb(t_stack *b)
{
	ft_rotate(b);
}

void	ft_rr(t_stack *a, t_stack *b)
{
	ft_rotate(a);
	ft_rotate(b);
}
