/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaisfuzita <thaisfuzita@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 17:31:45 by thaisfuzita       #+#    #+#             */
/*   Updated: 2026/07/12 11:06:33 by thaisfuzita      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_stack *s)
{
	int max_index;
	int bits;
	
	max_index = s->size - 1;
	bits = 0;
	while (max_index > 0)
	{
        max_index = max_index >> 1;
        bits++;
    }
	return (bits);
}

static int get_bit(int index, int bit)
{
	int bit_value;

    bit_value = (index >> bit) & 1;
    return (bit_value);
}

static void process_bits(t_stack *a, t_stack *b, t_bench *bm, int bits)
{
    int size;
    int count;

    count = 0;
	while (count != bits)
    {
        size = a->size;
        while (size != 0)
        {
            if (get_bit(a->top->index, count) == 0)
                ft_pb(a, b, bm);
            else
                ft_ra(a, bm);
            size--;
        }
        while (b->size != 0)
            ft_pa(a, b, bm);
        count++;
    }
}

void complex(t_stack *a, t_stack *b, t_bench *bm)
{
    int max_bits;

	index_normalize(a);
    print_both(a, b);
    max_bits = get_max_bits(a);
    process_bits(a, b, bm, max_bits);
    print_both(a, b);
}
