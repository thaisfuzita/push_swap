/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decide_ordenation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrique <hrique@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 15:57:32 by tjulya-c          #+#    #+#             */
/*   Updated: 2026/07/09 12:26:54 by hrique           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ordenation(t_stack *a, t_stack *b, t_bench *bechmark)
{
	exec_mode(a, b, benchmark);
}

void	exec_mode(t_stack *a, t_stack *b, t_bench *benchmark)
{
	is_ordered();
}

float	ft_check_disorder(t_stack a)
{
	int	mistakes;
	int	total_pairs;
	int	size;
	int	i;
	int	j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	size = ft_lstsize(a);
	while (i < (size - 1))
	{
		j = i + 1;
		while (j < (size - 1))
		{
			total_pairs += 1;
			if (a[i] > a[j])
				mistakes += 1;
		}
	}
	return ((float)mistakes / total_pairs);
}

int	is_ordered(t_stack a)
{
	float	disorder;

	disorder = ft_check_disorder(a);
	if (disorder == 0)
		return (1);
	return (0);
}
