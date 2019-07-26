/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractols_cont_iterate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuchko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 14:50:14 by okuchko           #+#    #+#             */
/*   Updated: 2019/07/26 14:50:16 by okuchko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_4th_iter(t_global *g)
{
	int		i;
	double	sqr;
	double	sqi;

	i = 0;
	while (i < g->fr.max_iterations)
	{
		g->fr.old_re = g->fr.new_re;
		g->fr.old_im = g->fr.new_im;
		sqr = g->fr.old_re * g->fr.old_re;
		sqi = g->fr.old_im * g->fr.old_im;
		g->fr.new_re = sqr * sqr + sqi * sqi - 6 * sqr * sqi
										+ g->fr.c_re - 1.5 * g->fr.stp_re;
		g->fr.new_im = 4 * g->fr.old_re * g->fr.old_im * (sqr - sqi) +
												g->fr.c_im - g->fr.stp_im;
		if ((g->fr.new_re * g->fr.new_re + g->fr.new_im * g->fr.new_im) > 4)
			break ;
		i++;
	}
	return (i);
}

int	mandelbrot_tricorn_iter(t_global *g)
{
	int		i;

	i = 0;
	while (i < g->fr.max_iterations)
	{
		g->fr.old_re = g->fr.new_re;
		g->fr.old_im = g->fr.new_im;
		g->fr.new_re = g->fr.old_re * g->fr.old_re -
			g->fr.old_im * g->fr.old_im + g->fr.c_re - 1.5 * g->fr.stp_re;
		g->fr.new_im = -2 * g->fr.old_re * g->fr.old_im +
												g->fr.c_im - g->fr.stp_im;
		if ((g->fr.new_re * g->fr.new_re + g->fr.new_im * g->fr.new_im) > 4)
			break ;
		i++;
	}
	return (i);
}

int	burning5th_iter(t_global *g)
{
	int		i;
	double	re;
	double	im;
	double	ir;

	i = 0;
	while (i < g->fr.max_iterations)
	{
		g->fr.old_re = g->fr.new_re * g->fr.new_re;
		g->fr.old_im = g->fr.new_im * g->fr.new_im;
		re = g->fr.old_re * g->fr.old_re;
		im = g->fr.old_im * g->fr.old_im;
		ir = g->fr.old_im * g->fr.old_re;
		g->fr.new_re = fabs(g->fr.new_re) * (re - 10 * ir + 5 * im) +
											g->fr.c_re - 1.5 * g->fr.stp_re;
		g->fr.new_im = fabs(g->fr.new_im) * (5 * re - 10 * ir + im) +
												g->fr.c_im - g->fr.stp_im;
		if ((g->fr.new_re * g->fr.new_re + g->fr.new_im * g->fr.new_im) > 4)
			break ;
		i++;
	}
	return (i);
}
