/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaisfuzita <thaisfuzita@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 12:58:27 by tjulya-c          #+#    #+#             */
/*   Updated: 2026/07/06 23:06:48 by thaisfuzita      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_number(char *str)
{
	int i;

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

