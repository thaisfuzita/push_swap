/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjulya-c <tjulya-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 12:58:27 by tjulya-c          #+#    #+#             */
/*   Updated: 2026/07/07 15:57:03 by tjulya-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] == '\0')
			return (0);
		i++;
	}
	if (str[i] == '\0')
		return (0);
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

int	is_overflow(long num)
{
	if (num < INT_MIN || num > INT_MAX)
		return (1);
	return (0);
}
