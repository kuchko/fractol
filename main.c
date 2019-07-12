/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuchko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 13:54:35 by okuchko           #+#    #+#             */
/*   Updated: 2019/03/30 13:54:37 by okuchko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		globals_init(t_global *g)
{
	g->win_width = 1600;
	g->win_high = 1000;
	g->img_width = 1600;
	g->img_high = 1000;

	// ft_fit_wire(f, &g->w_orig);
	// ft_get_z_range(&g->w_orig);
	// g->w_orig.x_bias = g->win_width / 2;
	// g->w_orig.y_bias = g->win_high / 2;
	// g->w_orig.angle.x = M_PI_2 * 0.0;
	// g->w_orig.angle.y = M_PI_2 * 0.0;
	// g->w_orig.angle.z = M_PI_2 * 0.0;
	// g->w_orig.zoom = 1.0;
	// g->w_orig.color_mod = 0;
	// if (!(ft_wires_malloc(f)))
	// 	ft_error("malloc error in wires\n");
	// ft_copy_params(&f->w_orig, &f->w_up);
	// ft_copy_params(&f->w_orig, &f->w_iso);
	// ft_copy_params(&f->w_orig, &f->w_parral);
	// ft_copy_wire(&f->w_orig, &f->w_up);
	// ft_copy_wire(&f->w_orig, &f->w_iso);
	// ft_copy_wire(&f->w_orig, &f->w_parral);
}

static void		ft_input_select(int argc, char **argv, t_global *g)
{
	if (argc == 1)
	{
		ft_printf("usage:	fractol N\n");
		ft_printf("N: number of fractol\n");
		ft_printf("1 - Julia\n");
		ft_printf("2 - Mandelbrot Sets\n");
		ft_printf("3 - \n");
		ft_error("4 - \n");
	}
	else if (argc == 2 && ft_strlen(argv[1]) == 1)
	{
		ft_printf("its all okey\n");
		g->fractol_select = ft_atoi(argv[1]);
		if (g->fractol_select < 1 && g->fractol_select > 4)
			ft_error("No such fractol number\n");

	}
	else
		ft_error("invalid input\n");
}

int		main(int argc, char **argv)
{
	t_global	g;

	ft_input_select(argc, argv, &g);
	globals_init(&g);

	ft_draw(&g);
	system("leaks fdf > leaks");
	return (0);
}
