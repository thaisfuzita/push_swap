/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaisfuzita <thaisfuzita@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 17:55:33 by thaisfuzita       #+#    #+#             */
/*   Updated: 2026/07/06 18:54:35 by thaisfuzita      ###   ########.fr       */
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
	return num;
}
