/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaisfuzita <thaisfuzita@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 12:58:27 by tjulya-c          #+#    #+#             */
/*   Updated: 2026/07/06 22:16:16 by thaisfuzita      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *parse_and_validate(int argc, char **argv, int index)
{
    int *list;
    int i;
    int num;
    
    list = malloc((argc - index) * sizeof(int));
    if (!list)
        return (NULL);
    i = 0;
    while (index < argc)
    {
        if (!is_valid_number(argv[index]))
            return (free(list), NULL);
        if (is_overflow(argv[index]))
            return (free(list), NULL);
        num = convert_num(argv[index]);
        if (is_duplicate(list, num, i))
            return (free(list), NULL);
        list[i] = num;
        i++;
        index++;
    }
    return (list);
}

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

