/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrique <hrique@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:29:20 by hesantan          #+#    #+#             */
/*   Updated: 2026/07/08 17:39:57 by hrique           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_format(va_list *args, char c)
{
	if (c == 'c')
		return (print_char(va_arg(*args, int)));
	if (c == 's')
		return (print_str(va_arg(*args, char *)));
	if (c == 'p')
		return (print_ptr(va_arg(*args, void *)));
	if (c == 'd' || c == 'i')
		return (print_nbr(va_arg(*args, int)));
	if (c == 'u')
		return (print_unint(va_arg(*args, unsigned int)));
	if (c == 'x' || c == 'X')
		return (print_hexa(va_arg(*args, unsigned int), c));
	if (c == '%')
		return (print_char('%'));
	return (print_char('%') + print_char(c));
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	args;

	if (!s)
		return (-1);
	count = 0;
	i = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] != '\0')
		{
			i++;
			count += check_format(&args, s[i]);
		}
		else
			count += print_char(s[i]);
		i++;
	}
	va_end(args);
	return (count);
}
