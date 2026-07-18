/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrique <hrique@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 12:42:15 by hrique            #+#    #+#             */
/*   Updated: 2026/07/18 13:22:03 by hrique           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	write_disorder(double disorder)
{
	int	scaled;
	int	whole;
	int	frac;

	scaled = (int)(disorder * 10000 + 0.5);
	whole = scaled / 100;
	frac = scaled % 100;
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(whole, 2);
	ft_putstr_fd(".", 2);
	if (frac < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(frac, 2);
	ft_putstr_fd("%\n", 2);
}

static void	write_strategy(t_bench *bm)
{
	double	d;

	d = bm->disorder;
	ft_putstr_fd("[bench] strategy: ", 2);
	if (bm->strategy == SIMPLE)
		ft_putstr_fd("Simple / O(n\xc2\xb2)\n", 2);
	else if (bm->strategy == MEDIUM)
		ft_putstr_fd("Medium / O(n\xe2\x88\x9an)\n", 2);
	else if (bm->strategy == COMPLEX)
		ft_putstr_fd("Complex / O(n log n)\n", 2);
	else if (d < 0.2)
		ft_putstr_fd("Adaptive / O(n\xc2\xb2)\n", 2);
	else if (d < 0.5)
		ft_putstr_fd("Adaptive / O(n\xe2\x88\x9an)\n", 2);
	else
		ft_putstr_fd("Adaptive / O(n log n)\n", 2);
}

static void	write_ops_line1(t_bench *bm)
{
	ft_putstr_fd("[bench] ", 2);
	bench_write_label("sa", bm->sa);
	bench_write_label("sb", bm->sb);
	bench_write_label("ss", bm->ss);
	bench_write_label("pa", bm->pa);
	bench_write_label("pb", bm->pb);
	ft_putstr_fd("\n", 2);
}

static void	write_ops_line2(t_bench *bm)
{
	ft_putstr_fd("[bench] ", 2);
	bench_write_label("ra", bm->ra);
	bench_write_label("rb", bm->rb);
	bench_write_label("rr", bm->rr);
	bench_write_label("rra", bm->rra);
	bench_write_label("rrb", bm->rrb);
	bench_write_label("rrr", bm->rrr);
	ft_putstr_fd("\n", 2);
}

void	print_bench(t_bench *bm)
{
	write_disorder(bm->disorder);
	write_strategy(bm);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(bm->total_ops, 2);
	ft_putstr_fd("\n", 2);
	write_ops_line1(bm);
	write_ops_line2(bm);
}