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
	g->fr.zoom = 1;
	g->fr.zoom_step = 1.2;
	g->fr.max_iterations = 10;
	// Julia init
	g->fr.c_re = -M_PI_2;//-0.7;
	g->fr.c_im = 0;//0.27015;
	// g->fr.c_re = -0.7;
	// g->fr.c_im = 0.27015;
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
