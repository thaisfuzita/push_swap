/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrique <hrique@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 12:35:56 by tjulya-c          #+#    #+#             */
/*   Updated: 2026/07/09 13:28:44 by hrique           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*top;
	t_node	*bottom;
}	t_stack;

typedef enum e_strategy
{
	EMPTY,
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_strategy;

typedef struct s_bench
{
	int			b_activate;
	double		disorder;
	t_strategy	strategy;
	int			total_ops;
	int			sa;
	int			sb;
	int			ss;
	int			pa;
	int			pb;
	int			ra;
	int			rb;
	int			rr;
	int			rra;
	int			rrb;
	int			rrr;
}	t_bench;

void	ft_pa(t_stack *a, t_stack *b, t_bench *benchmark);
void	ft_pb(t_stack *a, t_stack *b, t_bench *benchmark);
void	ft_r_ra(t_stack *a, t_bench *benchmark);
void	ft_r_rb(t_stack *b, t_bench *benchmark);
void	ft_r_rr(t_stack *a, t_stack *b, t_bench *benchmark);
void	ft_ra(t_stack *a, t_bench *benchmark);
void	ft_rb(t_stack *b, t_bench *benchmark);
void	ft_rr(t_stack *a, t_stack *b, t_bench *benchmark);
void	ft_sa(t_stack *a, t_bench *benchmark);
void	ft_sb(t_stack *b, t_bench *benchmark);
void	ft_ss(t_stack *a, t_stack *b, t_bench *benchmark);
int 	main(int argc, char **argv);
int		is_valid_number(char *str);
int		is_duplicate(int *list, int num, int i);
int		is_overflow(long num);
void	free_matrix(char **list);
int		parse_flags(int argc, char **argv, t_bench *bench);
int		*parse_numbers(int argc, char **argv, int *count, t_bench *bench);
int		*parse_and_validate(int argc, char **args, int index);
char	*join_args(int argc, char **argv);
char	**split_args(char *str);
int		items_num(char **list);
int		is_strat_flag(char *str);
long	convert_num(char *str);

#endif