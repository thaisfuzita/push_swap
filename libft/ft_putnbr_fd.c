/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjulya-c <tjulya-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 16:33:45 by tjulya-c          #+#    #+#             */
/*   Updated: 2026/06/03 14:05:42 by tjulya-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nbr;
	char		x;

	nbr = n;
	if (n < 0)
	{
		nbr = -nbr;
		write(fd, "-", 1);
	}
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	x = (nbr % 10) + '0';
	write(fd, &x, 1);
}
