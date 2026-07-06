/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjulya-c <tjulya-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:30:13 by tjulya-c          #+#    #+#             */
/*   Updated: 2026/06/03 14:10:51 by tjulya-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*one;
	unsigned char		*two;

	one = (unsigned char *)s1;
	two = (unsigned char *)s2;
	i = 0;
	while (i < n && one[i] == two[i])
		i++;
	if (i == n)
		return (0);
	return ((int)(one[i] - two[i]));
}
