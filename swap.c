/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesantan <hesantan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 13:20:42 by tjulya-c          #+#    #+#             */
/*   Updated: 2026/07/07 15:33:35 by hesantan         ###   ########.fr       */
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

void	ft_sa(t_stack *a)
{
	ft_swap(a);
}
void	ft_sb(t_stack *b)
{
	ft_swap(b);
}

void	ft_ss(t_stack *a, t_stack *b)
{
	ft_swap(a);
	ft_swap(b);
}