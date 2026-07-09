/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrique <hrique@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:28:58 by hesantan          #+#    #+#             */
/*   Updated: 2026/07/09 12:00:06 by hrique           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_char(char c)
{
	write(2, &c, 1);
	return (1);
}

int	print_str(char *s)
{
	int		i;

	i = 0;
	if (!s)
	{
		write (2, "(null)", 6);
		return (6);
	}
	while (s[i])
		i += print_char(s[i]);
	return (i);
}
