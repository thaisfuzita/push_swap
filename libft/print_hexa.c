/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrique <hrique@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:28:48 by hesantan          #+#    #+#             */
/*   Updated: 2026/07/08 17:40:17 by hrique           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_hexa(unsigned int nbr, char c)
{
	int		i;
	char	*base;

	i = 0;
	if (c == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nbr >= 16)
		i += print_hexa(nbr / 16, c);
	i++;
	write(1, &base[nbr % 16], 1);
	return (i);
}

static int	print_longhexa(unsigned long nbr)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	if (nbr >= 16)
		i += print_longhexa(nbr / 16);
	i++;
	write(1, &base[nbr % 16], 1);
	return (i);
}

int	print_ptr(void *ptr)
{
	unsigned long	p;
	int				i;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	p = (unsigned long)ptr;
	write(1, "0x", 2);
	i = 2;
	i += print_longhexa(p);
	return (i);
}
