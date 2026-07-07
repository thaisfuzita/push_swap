/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjulya-c <tjulya-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 15:57:32 by tjulya-c          #+#    #+#             */
/*   Updated: 2026/07/07 16:04:15 by tjulya-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_disorder(t_stack a)
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
	return (mistakes / total_pairs);
}
