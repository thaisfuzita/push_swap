/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:28:32 by hesantan          #+#    #+#             */
/*   Updated: 2026/07/17 12:52:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_nbr(int n)
{
	long int	nbr;
	char		x;
	int			i;

	i = 0;
	nbr = n;
	if (n < 0)
	{
		nbr = -nbr;
		write(1, "-", 1);
		i++;
	}
	if (nbr >= 10)
		i += print_nbr(nbr / 10);
	x = (nbr % 10) + '0';
	i++;
	write(1, &x, 1);
	return (i);
}

int	print_unint(unsigned int n)
{
	char	x;
	int		i;

	i = 0;
	if (n >= 10)
		i += print_unint(n / 10);
	x = (n % 10) + '0';
	i++;
	write(1, &x, 1);
	return (i);
}
