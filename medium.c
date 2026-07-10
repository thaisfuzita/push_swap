/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaisfuzita <thaisfuzita@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 17:31:20 by thaisfuzita       #+#    #+#             */
/*   Updated: 2026/07/09 21:49:39 by thaisfuzita      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int chunk_size(t_stack *a, int index)
{
    int size;
    t_node *nd;

    size = 0;
    nd = a->bottom;
    while (nd != NULL)
    {
        if (nd->index == index)
            size++;
        nd = nd->next;
    }
    return (size);
}
static void    insert_in_order(t_stack *a, t_stack *b, t_bench *bm, int value)
{
    int rotates;
    t_node  *b_nd;
    
    rotates = 0;
    b_nd = b->top;
    while (b_nd != NULL && value < b_nd->value && rotates < b->size)
    {
        ft_rb(b, bm);
        rotates++;   
        b_nd = b->top;
    }
    ft_pb(a, b, bm);
    while (rotates != 0)
    {
        ft_r_rb(b, bm);
        rotates--;
    }
}

static void    order_chunk(t_stack *a, t_stack *b, t_bench *bm, int chunk)
{
    t_node  *nd;
    int c_size;
    int i;
    int j;

    i = 0;
    while (i < chunk)
    {
        j = 0;
        c_size = chunk_size(a, i);
        nd = a->top;
        while (j < c_size)
        {
            if (nd->index == i)
            {
                insert_in_order(a, b, bm, nd->value);
                j++;
            }
            else
                ft_ra(a, bm);
            nd = a->top;
        }
        i++;
    }
}

void    medium(t_stack *a, t_stack *b, t_bench *bm)
{
    int chunk;
    int max;
    int min;
    int range;

    chunk_limits(a, &min, &max);
    chunk = ft_sqrt(a->size);
    range = (max - min + chunk - 1) / chunk;
    set_chunk(a, min, range, chunk);
    order_chunk(a, b, bm, chunk);
    while (b->size != 0)
        ft_pa(a, b, bm);
}
