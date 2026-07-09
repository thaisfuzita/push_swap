/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_n_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrique <hrique@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 17:51:52 by thaisfuzita       #+#    #+#             */
/*   Updated: 2026/07/09 14:32:19 by hrique           ###   ########.fr       */
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

/*void free_all(t_stack *a, t_stack *b, int *nums)
{
	
	
	free(nums);
}*/
void	check_error(int count)
{
	if (count == -1)
		ft_printf("%s\n", "Error");
}