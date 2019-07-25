/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractols_iterate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuchko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:20:28 by okuchko           #+#    #+#             */
/*   Updated: 2019/07/25 17:20:30 by okuchko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	burningship_iter(t_global *g)
{
	int		i;

	i = 0;
	while (i < g->fr.max_iterations)
	{
		g->fr.old_re = g->fr.new_re;
		g->fr.old_im = g->fr.new_im;
		g->fr.new_re = g->fr.old_re * g->fr.old_re -
			g->fr.old_im * g->fr.old_im + g->fr.c_re - 1.5 * g->fr.stp_re;
		g->fr.new_im = fabs(2 * g->fr.old_re * g->fr.old_im) +
												g->fr.c_im - g->fr.stp_im;
		if ((g->fr.new_re * g->fr.new_re + g->fr.new_im * g->fr.new_im) > 4)
			break ;
		i++;
	}
	return (i);
}

int	burningstar_iter(t_global *g)
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
		g->fr.new_re = g->fr.new_re * (re - 10 * ir + 5 * im) +
											g->fr.c_re - 1.5 * g->fr.stp_re;
		g->fr.new_im = -g->fr.new_im * (5 * re - 10 * ir + im) +
												g->fr.c_im - g->fr.stp_im;
		if ((g->fr.new_re * g->fr.new_re + g->fr.new_im * g->fr.new_im) > 4)
			break ;
		i++;
	}
	return (i);
}

int	buffalo_iter(t_global *g)
{
	int		i;

	i = 0;
	while (i < g->fr.max_iterations)
	{
		g->fr.old_re = g->fr.new_re;
		g->fr.old_im = g->fr.new_im;
		g->fr.new_re = fabs(g->fr.old_re * g->fr.old_re -
			g->fr.old_im * g->fr.old_im) + g->fr.c_re - 1.5 * g->fr.stp_re;
		g->fr.new_im = fabs(g->fr.old_re * g->fr.old_im) * (-2) +
												g->fr.c_im - g->fr.stp_im;
		if ((g->fr.new_re * g->fr.new_re + g->fr.new_im * g->fr.new_im) > 4)
			break ;
		i++;
	}
	return (i);
}

int	mandelbrot_iter(t_global *g)
{
	int		i;

	i = 0;
	while (i < g->fr.max_iterations)
	{
		g->fr.old_re = g->fr.new_re;
		g->fr.old_im = g->fr.new_im;
		g->fr.new_re = g->fr.old_re * g->fr.old_re -
			g->fr.old_im * g->fr.old_im + g->fr.c_re - 1.5 * g->fr.stp_re;
		g->fr.new_im = 2 * g->fr.old_re * g->fr.old_im +
												g->fr.c_im - g->fr.stp_im;
		if ((g->fr.new_re * g->fr.new_re + g->fr.new_im * g->fr.new_im) > 4)
			break ;
		i++;
	}
	return (i);
}

int	julia_iter(t_global *g)
{
	int		i;

	i = 0;
	while (i < g->fr.max_iterations)
	{
		g->fr.old_re = g->fr.new_re;
		g->fr.old_im = g->fr.new_im;
		g->fr.new_re = g->fr.old_re * g->fr.old_re -
				g->fr.old_im * g->fr.old_im + g->fr.c_re + g->fr.stp_re;
		g->fr.new_im = 2 * g->fr.old_re * g->fr.old_im +
				g->fr.c_im + g->fr.stp_im;
		if ((g->fr.new_re * g->fr.new_re + g->fr.new_im * g->fr.new_im) > 4)
			break ;
		i++;
	}
	return (i);
}
