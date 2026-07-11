/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 21:13:41 by thaisfuzita       #+#    #+#             */
/*   Updated: 2026/07/10 22:12:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int nb)
{
	long	i;

	i = 0;
	while (i * i <= nb)
	{
		if (i * i == nb)
			return ((int)i);
		i++;
	}
	return ((int)(i - 1));
}

void chunk_limits(t_stack *a, int *min, int *max)
{
	t_node 	*nd;

	nd = a->top;
    *min = nd->value;
    *max = nd->value;
	while (nd != NULL)
	{
		if(nd->value > *max)
            *max = nd->value;
        if (nd->value < *min)
            *min = nd->value;
		nd = nd->next;
    }
}

void    set_chunk(t_stack *a, int min, int range, int chunk)
{
    int i;
    int limit;
    t_node *nd;
    
    i = 0;
    limit = range;
    while (i < chunk)
    {
        nd = a->top;
        while (nd != NULL)
        {
            if (i + 1 == chunk && nd->value >= min)
                nd->index = i;
            else if (nd->value >= min && nd->value < limit)
                nd->index = i;
            nd = nd->next;    
        }
        min = limit;
        limit = limit + range;
        i++;
    }
}


