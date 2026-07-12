/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrique <hrique@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 17:55:33 by thaisfuzita       #+#    #+#             */
/*   Updated: 2026/07/11 19:15:07 by hrique           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**split_args(char *str)
{
	char	**list;

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

int	is_strat_flag(char *str)
{
	if (ft_strncmp(str, "--simple", 8) == 0)
		return (1);
	else if (ft_strncmp(str, "--medium", 8) == 0)
		return (1);
	else if (ft_strncmp(str, "--complex", 9) == 0)
		return (1);
	else if (ft_strncmp(str, "--adaptive", 10) == 0)
		return (1);
	return (0);
}

long	convert_num(char *str)
{
	long	num;
	int		i;
	int		neg;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	neg = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	num = 0;
	while (ft_isdigit(str[i]))
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	num = num * neg;
	return (num);
}
