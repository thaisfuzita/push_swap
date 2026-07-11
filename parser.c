/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaisfuzita <thaisfuzita@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 19:08:18 by thaisfuzita       #+#    #+#             */
/*   Updated: 2026/07/09 22:43:49 by thaisfuzita      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_flags(int argc, char **argv, t_bench *bm)
{
	int	i;

	i = 0;
	while (i < argc && i < 2)
	{
		if (is_strat_flag(argv[i]) && bm->strategy != EMPTY)
			return (i);
		if (ft_strncmp(argv[i], "--bench", 7) == 0)
			bm->b_activate = 1;
		else if (ft_strncmp(argv[i], "--simple", 8) == 0)
			bm->strategy = SIMPLE;
		else if (ft_strncmp(argv[i], "--medium", 8) == 0)
			bm->strategy = MEDIUM;
		else if (ft_strncmp(argv[i], "--complex", 9) == 0)
			bm->strategy = COMPLEX;
		else if (ft_strncmp(argv[i], "--adaptive", 10) == 0)
			bm->strategy = ADAPTIVE;
		else
			return (i);
		i++;
	}
	return (i);
}

static int	*parse_and_validate(int argc, char **args, int index)
{
	int		*list;
	int		i;
	long	num;

	list = malloc((argc - index) * sizeof(int));
	if (!list)
		return (NULL);
	i = 0;
	while (index < argc)
	{
		if (!is_valid_number(args[index]))
			return (free(list), NULL);
		num = convert_num(args[index]);
		if (is_overflow(num))
			return (free(list), NULL);
		if (is_duplicate(list, num, i))
			return (free(list), NULL);
		list[i] = (int)num;
		i++;
		index++;
	}
	return (list);
}

static char	*join_args(int argc, char **argv)
{
	int		i;
	char	*str;
	char	*tmp1;
	char	*tmp2;

	i = 2;
	str = ft_strdup(argv[1]);
	while (i < argc)
	{
		tmp1 = ft_strjoin(str, " ");
		tmp2 = ft_strjoin(tmp1, argv[i]);
		free(str);
		str = tmp2;
		free(tmp1);
		i++;
	}
	return (str);
}

int	*parse_numbers(int argc, char **argv, int *count, t_bench *bm)
{
	int		*list;
	int		flags;
	char	*str_args;
	char	**args;

	str_args = join_args(argc, argv);
	args = split_args(str_args);
	free(str_args);
	argc = items_num(args);
	flags = parse_flags(argc, args, bm);
	if (argc - flags <= 0)
	{
		free_matrix(args);
		*count = 0;
		return (NULL);
	}
	list = parse_and_validate(argc, args, flags);
	free_matrix(args);
	if (!list)
	{
		*count = -1;
		return (NULL);
	}
	*count = argc - flags;
	return (list);
}
