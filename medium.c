/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaisfuzita <thaisfuzita@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 17:31:20 by thaisfuzita       #+#    #+#             */
/*   Updated: 2026/07/12 11:24:26 by thaisfuzita      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	shortest_rotation(t_stack *x, t_bench *bm, int steps, 
		void (*rot)(t_stack *, t_bench *), void (*r_rot)(t_stack *, t_bench *))
{
    if (steps > x->size / 2)
	{
        steps = x->size - steps;
        while (steps > 0)
        {
            r_rot(x, bm);
            steps--;
        }
	}
	else
	{
        while (steps > 0)
        {
            rot(x, bm);
            steps--;
        }
	}
}

static void fill_b(t_stack *a, t_stack *b, t_bench *bm, int group_size)
{
    int limit;
    int items_checked;

    limit = group_size;
    items_checked = 0;
	while (a->size > 0)
    {
		if (a->top->index < limit)
        {
            ft_pb(a, b, bm);
            items_checked = 0;
        }
		else
        {
            ft_ra(a, bm);
            items_checked++;
            if (items_checked == a->size)
            {
                limit = limit + group_size;
                items_checked = 0;
            }
        }
    }
}

static int  find_max(t_stack *b)
{
    t_node *nd;
    int max_index;
    int max_pos;
    int actual_pos;
    
    
    nd = b->top;
	actual_pos = 0;
	max_index = -1;
	max_pos = 0;
	while (nd != NULL)
    {
        if (nd->index > max_index)
        {
            max_index = nd->index;
            max_pos = actual_pos;
        }
        nd = nd->next;
        actual_pos++;
    }
	return (max_pos);
}

void	medium(t_stack *a, t_stack *b, t_bench *bm)
{
    int group_size = ft_sqrt(a->size);
    int pos;
    int total;

    ft_printf("DEBUG group_size=%d\n", group_size);
	index_normalize(a);
	fill_b(a, b, bm, group_size);
	while (b->size != 0)
    {
		pos = find_max(b);
		shortest_rotation(b, bm, pos, ft_rb, ft_r_rb);
		ft_pa(a, b, bm);
    }
    total = bm->total_ops;
    ft_printf("%i\n", total);
}
