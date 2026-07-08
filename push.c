/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riks <riks@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 13:21:20 by tjulya-c          #+#    #+#             */
/*   Updated: 2026/07/08 13:50:25 by riks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack *src, t_stack *dst)
{
	t_node  *old_top_src;
    t_node  *new_top_src;
    t_node  *old_top_dst;
   
    if (src->size > 0)
    {
        old_top_src = src->top;
        new_top_src = src->top->next;
        old_top_dst = dst->top;
        if (old_top_dst)
            dst->top->prev = old_top_src;
        if (new_top_src)
        {
            new_top_src->prev = NULL;
            src->top = new_top_src;
        }
        else
        {
            src->top = NULL;
            src->bottom = NULL;
        }
        src->size--;
        old_top_src->next = old_top_dst;
        old_top_src->prev = NULL;
        dst->size++;
        dst->top = old_top_src;
    }
    return ;
}

void	ft_pa(t_stack *a, t_stack *b)
{
	ft_push(a, b);
}

void	ft_pb(t_stack *b, t_stack *a)
{
	ft_push(b, a);
}