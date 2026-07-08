/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riks <riks@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 13:21:20 by tjulya-c          #+#    #+#             */
/*   Updated: 2026/07/07 23:05:47 by riks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack *src, t_stack *dst)
{
	t_node  *old_top_src;
    t_node  *new_top_src;
    t_node  *old_top_dst;
    t_node  *new_top_dst;
    
    if (src->size <= 1)
        return ;
    old_top = src->top;
    new_top_src = old_top->next;
    new_top_src->prev = NULL;
}

void	ft_pa(t_stack *a)
{
	
}

void	ft_pb(t_stack *b)
{
	
}