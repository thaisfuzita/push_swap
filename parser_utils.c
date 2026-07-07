/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesantan <hesantan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 17:55:33 by thaisfuzita       #+#    #+#             */
/*   Updated: 2026/07/07 12:32:19 by hesantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**split_args(char *str)
{
	char	**list;
	int		num;

	list = ft_split(str, ' ');
	return (list);
}

int	items_num(char **list)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while (list[i] != NULL)
	{
		i++;
		num++;
	}
	return (num);
}

long	convert_num(char *str)
{
	long	num;
	int		i;
	int		neg;

	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	neg = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	num = 0;
	while (ft_isdigit(nptr[i]))
	{
		num = (num * 10) + (nptr[i] - '0');
		i++;
	}
	num = num * neg;
	return (num);
}
