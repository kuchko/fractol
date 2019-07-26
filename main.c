/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuchko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:22:17 by okuchko           #+#    #+#             */
/*   Updated: 2019/07/25 17:22:19 by okuchko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		globals_init(t_global *g)
{
	ft_bzero(&g->fr, sizeof(g->fr));
	g->fr.zoom = 1;
	g->fr.zoom_step = 1.2;
	g->fr.max_iterations = 40;
	g->fr.c_re = -0.7;
	g->fr.c_im = 0.27015;
}

static void	ft_input_select(int argc, char **argv, t_global *g)
{
	if (argc == 1)
	{
		ft_printf("usage:	fractol N\n");
		ft_printf("N: number of fractol\n");
		ft_printf("1 - Julia\n");
		ft_printf("2 - Mandelbrot\n");
		ft_printf("3 - Buffalo\n");
		ft_printf("4 - Burning Ship\n");
		ft_printf("5 - Burning Star\n");
		ft_printf("6 - Burning Ship 5th order\n");
		ft_printf("7 - Mandelbrot Tricorn\n");
		ft_error("8 - Mandelbrot 4th order\n");
	}
	else if (argc == 2 && ft_strlen(argv[1]) == 1)
	{
		g->fractol_select = ft_atoi(argv[1]);
		if (g->fractol_select < 1 || g->fractol_select > 8)
			ft_error("No such fractol number\n");
	}
	else
		ft_error("invalid input\n");
}

int			main(int argc, char **argv)
{
	t_global	g;

	ft_input_select(argc, argv, &g);
	globals_init(&g);
	ft_draw(&g);
	system("leaks fractol > leaks");
	return (0);
}
