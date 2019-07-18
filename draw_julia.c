/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuchko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 13:49:09 by okuchko           #+#    #+#             */
/*   Updated: 2019/03/30 13:49:14 by okuchko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void	pixel_calculate_and_print(t_global *g, int x, int y)
{
	int		i;
	double	t;

	g->fr.new_re = 1.5 * (x - g->img_width / 2) / (0.5 * g->fr.zoom * g->img_width) + g->fr.move_x;
	g->fr.new_im = (y - g->img_high / 2) / (0.5 * g->fr.zoom * g->img_high) + g->fr.move_y;

	i = 0;
	while (i < g->fr.max_iterations)
	{
		g->fr.old_re = g->fr.new_re;
		g->fr.old_im = g->fr.new_im;
		g->fr.new_re = g->fr.old_re * g->fr.old_re - g->fr.old_im * g->fr.old_im + g->fr.c_re;
		g->fr.new_im = 2 * g->fr.old_re * g->fr.old_im + g->fr.c_im;
		if((g->fr.new_re * g->fr.new_re + g->fr.new_im * g->fr.new_im) > 4)
			break;
		i++;
	}
	t = (double)(i) / (double)(g->fr.max_iterations);
	g->fr.color = (((int)((9 * (1 - t) * t * t * t * 255)) << 16) |
		(((int)(15 * (1 - t) * (1 - t) * t * t * 255)) << 8)) |
					(int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	ft_putpixel(g, x, y, g->fr.color);
}


void	draw_julia(t_global *g)
{
	g->fr.c_re = -0.7;
	g->fr.c_im = 0.27015;
	int	y;
	int	x;


	y = 0;
	while (y < g->img_high)
	{
		x = 0;
		while (x < g->img_width)
		{
			pixel_calculate_and_print(g, x, y);
			x++;
		}
		y++;
	}
}
