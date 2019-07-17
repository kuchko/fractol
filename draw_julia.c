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

void	draw_julia(t_global *g)
{
	// double	cRe;
	// double	cIm;           //real and imaginary part of the constant c, determinate shape of the Julia Set
	// double	newRe;
	// double	newIm;
	// double	oldRe;
	// double	oldIm;   //real and imaginary parts of new and old
	// double	zoom = 1;
	// double	moveX = 0;
	// double	moveY = 0; //you can change these to zoom and change position
	// int		color; //the RGB color value for the pixel
	// int 	maxIterations = 300; //after how much iterations the function should stop

	//pick some values for the constant c, this determines the shape of the Julia Set
	// cRe = -0.7;
	// cIm = 0.27015;
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


void	pixel_calculate_and_print(t_global *g, int x, int y)
{
	int i;
	double t;

	g->fr.new_re = 1.5 * (x - g->img_width / 2) / (0.5 * zoom * g->img_width) + moveX;
	g->fr.new_im = (y - g->img_high / 2) / (0.5 * zoom * g->img_high) + moveY;

	i = 0;
	while (i < g->fr.max_iterations)
	{
		//remember value of previous iteration
		oldRe = newRe;
		oldIm = newIm;
		//the actual iteration, the real and imaginary part are calculated
		newRe = oldRe * oldRe - oldIm * oldIm + cRe;
		newIm = 2 * oldRe * oldIm + cIm;
		//if the point is outside the circle with radius 2: stop
		if((newRe * newRe + newIm * newIm) > 4) break;
		i++;
	}
	//use color model conversion to get rainbow palette, make brightness black if maxIterations reached
	//color = HSVtoRGB(ColorHSV(i % 256, 255, 255 * (i < maxIterations)));
	// color = rgb_to_int(i % 256, 255, 255 * (i < maxIterations), 0);

	t = (double)(i) / (double)(maxIterations);
	// color = rgb_to_int(i % 256, 255, 255 * t, 0);


	color = (((int)((9 * (1 - t) * t * t * t * 255)) << 16) |
		(((int)(15 * (1 - t) * (1 - t) * t * t * 255)) << 8)) |
					(int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);

	//draw the pixel		pset(x, y, color);
	ft_putpixel(g, x, y, color);
}
