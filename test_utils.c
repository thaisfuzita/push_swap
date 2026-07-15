/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesantan <hesantan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 15:07:17 by hesantan          #+#    #+#             */
/*   Updated: 2026/07/15 15:33:53 by hesantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *s, char *name)
{
	t_node	*current;
	char *num;

	current = s->top;
	if (current)
	{
		write(2, name, ft_strlen(name));
		write(2, ": ", 2);
		while (current)
		{
			num = ft_itoa(current->value);
			write(2, num, ft_strlen(num));
			free(num);
			current = current->next;
			if (current)
				write(2, " ", 1);
		}
		write(2, "\n", 1);
	}
}

void	print_both(t_stack *a, t_stack *b)
{
	print_stack(a, "A");
	print_stack(b, "B");
	ft_printf("\n");
}