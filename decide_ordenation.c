/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decide_ordenation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 15:57:32 by tjulya-c          #+#    #+#             */
/*   Updated: 2026/07/10 21:17:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_ordered(float disorder)
{
	if (disorder == 0.0)
		return (1);
	return (0);
}

static void	adaptive(t_stack *a, t_stack *b, t_bench *bm, float disorder)
{
	if (disorder < 0.2)
		simple();
	else if (disorder >= 0.2 && disorder < 0.5)
		medium(a, b, bm);
	else
		complex();
}

static void	exec_mode(t_stack *a, t_stack *b, t_bench *bm, float disorder)
{
	int	mode;

	if (is_ordered(disorder))
		return ;
	mode = bm->strategy;
	if (mode == 1)
		simple();
	else if (mode == 2)
		medium(a, b, bm);
	else if (mode == 3)
		complex();
	else 
		adaptive(a, b, bm, disorder);
}

static float	ft_check_disorder(t_stack *a)
{
	int	mistakes;
	int	total_pairs;
	t_node 	*nd;
	t_node	*nx;

	mistakes = 0;
	total_pairs = 0;
	nd = a->top;
	nx = nd->next;
	while (nd->next != NULL)
	{
		while (nx != NULL )
		{
			total_pairs++;
			if(nd->value > nx->value)
				mistakes++;
			nx = nx->next;
		}
		nd = nd->next;
		nx = nd->next;
	}
	return (mistakes / (float)total_pairs);
}

void	ordernation(t_stack *a, t_stack *b, t_bench *bm)
{
	float	disorder;

	disorder = ft_check_disorder(a);
	bm->disorder = disorder;
	exec_mode(a, b, bm, disorder);
	/*if (bm->b_activate == 1)
		print_bench(bm);*/
}
