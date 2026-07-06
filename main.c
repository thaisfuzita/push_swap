/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjulya-c <tjulya-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 14:31:23 by tjulya-c          #+#    #+#             */
/*   Updated: 2026/07/06 15:07:28 by tjulya-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc < 2)
		return (ft_printf("Error\n"));
	if (argc == 2)
	{
		if (ft_strchr(argv[1], ' '))
		{
			argv = spliting(argv[1]);
			argc = 
		}
	}
	while (i < argc)
	{
		if (!valid_input(argv[i]))
			return (ft_printf("Error\n"));
	}
}

char	**spliting(char *str)
{
	char	*list;
	int		num;

	list = ft_split(str, ' ');
	while (list != NULL)
		num++;
}
