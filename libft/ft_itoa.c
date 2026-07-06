/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjulya-c <tjulya-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 16:17:19 by tjulya-c          #+#    #+#             */
/*   Updated: 2026/06/05 15:23:54 by tjulya-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	decimals(int n)
{
	long int	nbr;
	int			qnt;

	qnt = 0;
	nbr = n;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		nbr = -nbr;
		qnt++;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		qnt++;
	}
	return (qnt);
}

char	*ft_itoa(int n)
{
	int			qnt;
	long int	nbr;
	char		*number;

	qnt = decimals(n);
	number = malloc((qnt + 1) * sizeof(char));
	if (!number)
		return (NULL);
	nbr = n;
	if (n < 0)
	{
		nbr = -nbr;
		number[0] = '-';
	}
	if (nbr == 0)
		number[0] = '0';
	number[qnt] = '\0';
	while (nbr > 0)
	{
		number[qnt - 1] = nbr % 10 + '0';
		nbr = nbr / 10;
		qnt--;
	}
	return (number);
}
