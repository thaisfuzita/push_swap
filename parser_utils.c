/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjulya-c <tjulya-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 17:55:33 by thaisfuzita       #+#    #+#             */
/*   Updated: 2026/07/07 15:08:35 by tjulya-c         ###   ########.fr       */
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
