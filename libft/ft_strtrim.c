/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjulya-c <tjulya-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 14:36:49 by tjulya-c          #+#    #+#             */
/*   Updated: 2026/06/05 15:23:01 by tjulya-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isinset(char const *s, char a)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == a)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		len;
	char	*string;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (isinset(set, s1[i]))
		i++;
	len = ft_strlen(s1);
	j = len - 1;
	while (j >= 0 && isinset(set, s1[j]) && j >= i)
		j--;
	len = (j - i) + 1;
	if (len <= 0)
		string = ft_strdup("");
	else
		string = ft_substr(s1, i, len);
	return (string);
}
