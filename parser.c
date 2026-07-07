/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaisfuzita <thaisfuzita@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 19:08:18 by thaisfuzita       #+#    #+#             */
/*   Updated: 2026/07/06 23:06:58 by thaisfuzita      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int parse_flags(int argc, char **argv, t_bench *bench)
{
    int i;

    i = 1;
    while (i < argc)
    {
        if (ft_strcmp(argv[i], "--bench") == 0)
            bench->b_activate = 1;
        else if (ft_strcmp(argv[i], "--simple") == 0)
            bench->strategy = "Simple / O(n²)";
        else if (ft_strcmp(argv[i], "--medium") == 0)
            bench->strategy = "Medium / O(n√n)";
        else if (ft_strcmp(argv[i], "--complex") == 0)
            bench->strategy = "Complex / O(n log n)";
        else if (ft_strcmp(argv[i], "--adaptive") == 0)
            bench->strategy = "Adaptive";
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
