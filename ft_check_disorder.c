/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_disorder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesantan <hesantan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:05:34 by hesantan          #+#    #+#             */
/*   Updated: 2026/07/06 15:15:17 by hesantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_disorder(stack a)
{
	int	mistakes;
	int	total_pairs;
	int	i;
	int	j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < ((size)a - 1))
	{
		j = i + 1;
		while (j < ((size)a - 1))
		{
			total_pairs += 1;
			if (a[i] > a[j])
				mistakes += 1;
		}
	}
	return (mistakes / total_pairs);
}