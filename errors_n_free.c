/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_n_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrique <hrique@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 17:51:52 by thaisfuzita       #+#    #+#             */
/*   Updated: 2026/07/11 19:08:22 by hrique           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_matrix(char **list)
{
	int	i;

	i = 0;
	while (list[i] != NULL)
	{
		free(list[i]);
		i++;
	}
	free(list);
}

void	free_all(t_stack *a, t_stack *b, int *nums)
{
	int	i;
	int	j;
	t_node	*nd;

	i = a->size;
	while (i > 0)
	{
		nd = a->bottom;
		a->bottom = nd->prev;
		free(nd);
		i--;
	}
	j = b->size;
	while (j > 0)
	{
		nd = b->bottom;
		b->bottom = nd->prev;
		free(nd);
		j--;
	}
	free(nums);
}

void	check_error(int count)
{
	if (count == -1)
		ft_printf("%s\n", "Error");
}