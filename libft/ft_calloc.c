/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjulya-c <tjulya-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:29:29 by tjulya-c          #+#    #+#             */
/*   Updated: 2026/06/03 14:23:02 by tjulya-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*x;
	size_t			max;

	max = -1;
	if (nmemb != 0 && size > max / nmemb)
		return (NULL);
	x = malloc(nmemb * size);
	if (!x)
		return (NULL);
	ft_bzero(x, nmemb * size);
	return (x);
}
