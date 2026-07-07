/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaisfuzita <thaisfuzita@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 19:08:18 by thaisfuzita       #+#    #+#             */
/*   Updated: 2026/07/06 22:33:21 by thaisfuzita      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int parse_flags(int argc, char **argv)
{
    int i;

    i = 1;
    while (i < argc)
    {
        if (ft_strcmp(argv[i], "--bench") == 0)
            -
        else if (ft_strcmp(argv[i], "--simple") == 0)
            -
        else if (ft_strcmp(argv[i], "--medium") == 0)
            -
        else if (ft_strcmp(argv[i], "--complex") == 0)
            -
        else if (ft_strcmp(argv[i], "--adaptive") == 0)
            -
        else
            return (i);
        i++;
    }
    return (i);
}

int *parse_numbers(int argc, char **argv, int *count)
{
    int *list;
    int i;
    int is_allocated;

    i = 1;
    is_allocated = 0;
    if (argc == 2)
    {
        if (ft_strchr(argv[1], ' '))
        {
            argv = split_args(argv[1]);
            argc = items_num(argv);
            i = 0;
            is_allocated = 1;
        }
    }
    list = parse_and_validate(argc, argv, i);
    if (is_allocated == 1)
        free_matrix(argv);
    *count = argc - i;
    return(list);
}
