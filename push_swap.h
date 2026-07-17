/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 12:35:56 by tjulya-c          #+#    #+#             */
/*   Updated: 2026/07/17 15:28:41 by marvin           ###   ########.fr       */
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
int		main(int argc, char **argv);
int		is_valid_number(char *str);
int		is_duplicate(int *list, int num, int i);
int		is_overflow(long num);
void	free_matrix(char **list);
int		*parse_numbers(int argc, char **argv, int *count, t_bench *bench);
int		items_num(char **list);
int		is_strat_flag(char *str);
long	convert_num(char *str);
void    medium(t_stack *a, t_stack *b, t_bench *bm);
int		ft_sqrt(int nb);
void 	free_all(t_stack *a, t_stack *b, int *nums);
void	check_error(int count);
void	ordernation(t_stack *a, t_stack *b, t_bench *bm);
void	init_bench(t_bench *bm);
void 	complex(t_stack *a, t_stack *b, t_bench *bm);
void	simple(t_stack *a, t_stack *b, t_bench *bm);
char	**split_args(char *str);
void	index_normalize(t_stack *a);
void	print_op(char *op, t_bench *bm);
void	print_stack(t_stack *s, char *name);
void	print_both(t_stack *a, t_stack *b);

#endif