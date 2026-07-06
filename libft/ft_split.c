/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjulya-c <tjulya-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:13:48 by tjulya-c          #+#    #+#             */
/*   Updated: 2026/06/05 15:24:15 by tjulya-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	size;

	if (!s)
		return (0);
	i = 0;
	size = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != '\0')
			size++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (size);
}

static int	wordlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**free_all(char **list, int x)
{
	while (x >= 0)
	{
		free(list[x]);
		x--;
	}
	free(list);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		x;
	int		len;
	char	**list;
	int		size;

	size = count_words(s, c);
	list = malloc((size + 1) * sizeof(char *));
	if (!list)
		return (NULL);
	i = 0;
	x = 0;
	while (x < size)
	{
		while (s[i] == c)
			i++;
		len = wordlen(&s[i], c);
		list[x] = ft_substr(s, i, len);
		if (!list[x])
			return (free_all(list, x - 1));
		i += len;
		x++;
	}
	list[x] = NULL;
	return (list);
}
