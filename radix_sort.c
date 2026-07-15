/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesantan <hesantan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 23:40:25 by riks              #+#    #+#             */
/*   Updated: 2026/07/15 17:21:04 by hesantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_max_bit(int size)
{
	int	bits;

	bits = 0;
	while ((1 << bits) < size)
		bits = bits + 1;
	return (bits);
}

int get_bit(int value, int bit)
{
	return (value >> bit) & 1;
}

void	radix_sort(t_stack *a, t_stack *b)
{
	...
}
