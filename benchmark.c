/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 17:31:38 by thaisfuzita       #+#    #+#             */
/*   Updated: 2026/07/17 12:49:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_bench(t_bench *bm)
{
	bm->b_activate = 0;
	bm->disorder = 0.0f;
	bm->strategy = 0;
	bm->total_ops = 0;
	bm->sa = 0;
	bm->sb = 0;
	bm->ss = 0;
	bm->pa = 0;
	bm->pb = 0;
	bm->ra = 0;
	bm->rb = 0;
	bm->rr = 0;
	bm->rra = 0;
	bm->rrb = 0;
	bm->rrr = 0;
}

void	print_op(char *op, t_bench *bm)
{
	if (bm->b_activate == 0)
		ft_printf("%s\n", op);
}

// void	print_bench(t_bench bm)
// {
	
// }