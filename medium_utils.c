/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 21:13:41 by thaisfuzita       #+#    #+#             */
/*   Updated: 2026/07/17 12:51:15 by marvin           ###   ########.fr       */
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

void	index_normalize(t_stack *a)
{
    t_node *nd;
    t_node *cmp;
    int count_i;

    nd = a->top;
    while (nd != NULL)
    {        
        count_i = 0;
        cmp = a->top;
        while (cmp != NULL)
        {
            if (cmp->value < nd->value)
                count_i++;
            cmp = cmp->next;
        }
        nd->index = count_i;
        nd = nd->next;
    }
}
