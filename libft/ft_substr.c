/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjulya-c <tjulya-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 14:05:24 by tjulya-c          #+#    #+#             */
/*   Updated: 2026/06/03 14:27:02 by tjulya-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*string;
	size_t	i;
	size_t	size;

	size = ft_strlen(s);
	if (start > size)
		len = 0;
	else if (size - start < len)
		len = size - start;
	string = malloc((len + 1) * sizeof(char));
	if (!string)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		string[i] = s[start + i];
		i++;
	}
	string[i] = '\0';
	return (string);
}
