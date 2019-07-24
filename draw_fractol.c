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

//Burning ship
// void	pixel_calculate_and_print(t_global *g, int x, int y)
// {
// 	int		i;
// 	double	t;

// 	g->fr.c_re = 1.5 * (x - IMG_WIDTH / 2) / (0.5 * g->fr.zoom * IMG_WIDTH) + g->fr.move_x;
// 	g->fr.c_im = (y - IMG_HIGHT / 2) / (0.5 * g->fr.zoom * IMG_HIGHT) + g->fr.move_y;

// 	g->fr.new_re = 0;
// 	g->fr.new_im = 0;

// 	i = 0;
// 	while (i < g->fr.max_iterations)
// 	{
// 		g->fr.old_re = g->fr.new_re;
// 		g->fr.old_im = g->fr.new_im;
// 		g->fr.new_re = g->fr.old_re * g->fr.old_re - g->fr.old_im * g->fr.old_im + g->fr.c_re;
// 		g->fr.new_im = fabs(2 * g->fr.old_re * g->fr.old_im) + g->fr.c_im;
// 		if((g->fr.new_re * g->fr.new_re + g->fr.new_im * g->fr.new_im) > 4)
// 			break;
// 		i++;
// 	}
// 	t = (double)(i) / (double)(g->fr.max_iterations);
// 	g->fr.color = (((int)((9 * (1 - t) * t * t * t * 255)) << 16) |
// 		(((int)(15 * (1 - t) * (1 - t) * t * t * 255)) << 8)) |
// 					(int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
// 	g->fr.color = change_color_rgb(g->fr.color, g->fr.c_step_x, g->fr.c_step_y, g->fr.a_s);
// 	ft_putpixel(g, x, y, g->fr.color);
// }


//Burning ship 6th
// void	pixel_calculate_and_print(t_global *g, int x, int y)
// {
// 	int		i;
// 	double	t;

// ///
// 	double	re;
// 	double	im;
// 	double	ir;
// ///

// 	g->fr.c_re = 1.5 * (x - IMG_WIDTH / 2) / (0.5 * g->fr.zoom * IMG_WIDTH) + g->fr.move_x;
// 	g->fr.c_im = (y - IMG_HIGHT / 2) / (0.5 * g->fr.zoom * IMG_HIGHT) + g->fr.move_y;


// 	g->fr.new_re = 0;
// 	g->fr.new_im = 0;
// 	g->fr.old_re = 0;
// 	g->fr.old_im = 0;
// 	i = 0;
// 	while (i < g->fr.max_iterations)
// 	{
// 		// f->j.oldre = f->j.newre * f->j.newre;
// 		// f->j.oldim = f->j.newim * f->j.newim;

// 		// f->j.newim = -f->j.newim * (5 * re - 10 * ir + im) + f->j.cim;
// 		// f->j.newre = f->j.newre * (re - 10 * ir + 5 * im) + f->j.cre;

// 		g->fr.old_re = g->fr.new_re * g->fr.new_re;
// 		g->fr.old_im = g->fr.new_im * g->fr.new_im;
// 		re = g->fr.old_re * g->fr.old_re;
// 		im = g->fr.old_im * g->fr.old_im;
// 		ir = g->fr.old_im * g->fr.old_re;

// 		g->fr.new_re = g->fr.new_re * (re - 10 * ir + 5 * im) + g->fr.c_re;
// 		g->fr.new_im = -g->fr.new_im * (5 * re - 10 * ir + im) + g->fr.c_im ;
// 		if((g->fr.new_re * g->fr.new_re + g->fr.new_im * g->fr.new_im) > 4)
// 			break;
// 		i++;
// 	}
// 	t = (double)(i) / (double)(g->fr.max_iterations);
// 	g->fr.color = (((int)((9 * (1 - t) * t * t * t * 255)) << 16) |
// 		(((int)(15 * (1 - t) * (1 - t) * t * t * 255)) << 8)) |
// 					(int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
// 	g->fr.color = change_color_rgb(g->fr.color, g->fr.c_step_x, g->fr.c_step_y, g->fr.a_s);
// 	ft_putpixel(g, x, y, g->fr.color);
// }

//Buffalo
// void	pixel_calculate_and_print(t_global *g, int x, int y)
// {
// 	int		i;
// 	double	t;

// 	g->fr.c_re = 1.5 * (x - IMG_WIDTH / 2) / (0.5 * g->fr.zoom * IMG_WIDTH) + g->fr.move_x;
// 	g->fr.c_im = (y - IMG_HIGHT / 2) / (0.5 * g->fr.zoom * IMG_HIGHT) + g->fr.move_y;


// 	g->fr.new_re = 0;
// 	g->fr.new_im = 0;
// 	g->fr.old_re = 0;
// 	g->fr.old_im = 0;
// 	i = 0;
// 	while (i < g->fr.max_iterations)
// 	{
// 		g->fr.old_re = g->fr.new_re;
// 		g->fr.old_im = g->fr.new_im;
// 		g->fr.new_re = fabs(g->fr.old_re * g->fr.old_re - g->fr.old_im * g->fr.old_im) + g->fr.c_re;
// 		g->fr.new_im = fabs(g->fr.old_re * g->fr.old_im) * (-2) + g->fr.c_im;
// 		if((g->fr.new_re * g->fr.new_re + g->fr.new_im * g->fr.new_im) > 4)
// 			break;
// 		i++;
// 	}
// 	t = (double)(i) / (double)(g->fr.max_iterations);
// 	g->fr.color = (((int)((9 * (1 - t) * t * t * t * 255)) << 16) |
// 		(((int)(15 * (1 - t) * (1 - t) * t * t * 255)) << 8)) |
// 					(int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
// 	g->fr.color = change_color_rgb(g->fr.color, g->fr.c_step_x, g->fr.c_step_y, g->fr.a_s);
// 	ft_putpixel(g, x, y, g->fr.color);
// }

//Mandelbrot
// void	pixel_calculate_and_print(t_global *g, int x, int y)
// {
// 	int		i;
// 	double	t;

// 	g->fr.c_re = 1.5 * (x - IMG_WIDTH / 2) / (0.5 * g->fr.zoom * IMG_WIDTH) + g->fr.move_x;
// 	g->fr.c_im = (y - IMG_HIGHT / 2) / (0.5 * g->fr.zoom * IMG_HIGHT) + g->fr.move_y;

// 	g->fr.new_re = 0;
// 	g->fr.new_im = 0;

// 	i = 0;
// 	while (i < g->fr.max_iterations)
// 	{
// 		g->fr.old_re = g->fr.new_re;
// 		g->fr.old_im = g->fr.new_im;
// 		g->fr.new_re = g->fr.old_re * g->fr.old_re - g->fr.old_im * g->fr.old_im + g->fr.c_re - 1.5 * g->fr.stp_re;
// 		g->fr.new_im = 2 * g->fr.old_re * g->fr.old_im + g->fr.c_im - g->fr.stp_im;
// 		if((g->fr.new_re * g->fr.new_re + g->fr.new_im * g->fr.new_im) > 4)
// 			break;
// 		i++;
// 	}
// 	t = (double)(i) / (double)(g->fr.max_iterations);
// 	g->fr.color = (((int)((9 * (1 - t) * t * t * t * 255)) << 16) |
// 		(((int)(15 * (1 - t) * (1 - t) * t * t * 255)) << 8)) |
// 					(int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
// 	g->fr.color = change_color_rgb(g->fr.color, g->fr.c_step_x, g->fr.c_step_y, g->fr.a_s);
// 	// ft_printf("COL %x ", g->fr.color );
// 	ft_putpixel(g, x, y, g->fr.color);
// }


// JULIA
int		julia_iterate(t_global *g)
{
	int		i;

	i = 0;
	while (i < g->fr.max_iterations)
	{
		g->fr.old_re = g->fr.new_re;
		g->fr.old_im = g->fr.new_im;
		g->fr.new_re = g->fr.old_re * g->fr.old_re - g->fr.old_im *
											 g->fr.old_im + g->fr.c_re + g->fr.stp_re;
		g->fr.new_im = 2 * g->fr.old_re * g->fr.old_im + g->fr.c_im + g->fr.stp_im;
		if((g->fr.new_re * g->fr.new_re + g->fr.new_im * g->fr.new_im) > 4)
			break;
		i++;
	}
	return(i);
}

void	iteration_init(t_global *g, int x, int y)
{
	g->fr.new_re = 1.5 * (x - IMG_WIDTH / 2) /
				(0.5 * g->fr.zoom * IMG_WIDTH) + g->fr.move_x;
	g->fr.new_im = (y - IMG_HIGHT / 2) /
				(0.5 * g->fr.zoom * IMG_HIGHT) + g->fr.move_y;
}

void	pixel_calc_color(t_global *g, int i)
{
	double	t;

	t = (double)(i) / (double)(g->fr.max_iterations);
	g->fr.color = (((int)((9 * (1 - t) * t * t * t * 255)) << 16) |
		(((int)(15 * (1 - t) * (1 - t) * t * t * 255)) << 8)) |
					(int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	g->fr.color = change_color_rgb(g->fr.color, g->fr.c_step_x, g->fr.c_step_y, g->fr.a_s);
}

void	draw_fractol(t_global *g)
{
	int	y;
	int	x;

	y = g->ystart;
	while (y < g->yend)
	{
		x = g->xstart;
		while (x < g->xend)
		{
			// pixel_calculate_and_print(g, x, y);
			iteration_init(g, x, y);
			pixel_calc_color(g, julia_iterate(g));
			ft_putpixel(g, x, y, g->fr.color);
			x++;
		}
		y++;
	}
}
