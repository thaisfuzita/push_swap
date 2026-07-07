/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesantan <hesantan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 12:58:27 by tjulya-c          #+#    #+#             */
/*   Updated: 2026/07/07 10:10:04 by hesantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void parse_flags(int argc, char **argv, )

int	check_input(int	argc, char **argv, int index)
{
	
}

int	valid_number(char *str)
{
	int i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] == '\0')
			return (0);
		i++;
	}
	while (str[i] != '\0' && ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

int	is_duplicate(int *list, int num, int i)
{
	while (i - 1 >= 0)
	{
		if (list[i - 1] == num)
			return (1);
		i--;
	}
	return (0);
}

int	is_overflow(char *str)
{
	int	i;
	int	neg;
	int j;

	i = 0;
	neg = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = 1;
		i++;
	}
	while (str[i] == '0')
		i++;
	while (str[i] != '\0')
	{
		i++;
		j++;
	}
	if (neg == 1)
	{
		if (j)
	}
}
