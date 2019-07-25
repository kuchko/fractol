/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuchko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:20:00 by okuchko           #+#    #+#             */
/*   Updated: 2019/07/25 17:20:03 by okuchko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_x(void *p)
{
	(void)p;
	system("leaks fractol > leaks");
	exit(0);
	return (0);
}

static void	iteration_init(t_global *g, int x, int y)
{
	if (g->fractol_select == 1)
	{
		g->fr.new_re = 1.5 * (x - IMG_WIDTH / 2) /
					(0.5 * g->fr.zoom * IMG_WIDTH) + g->fr.move_x;
		g->fr.new_im = (y - IMG_HIGHT / 2) /
					(0.5 * g->fr.zoom * IMG_HIGHT) + g->fr.move_y;
	}
	else
	{
		g->fr.c_re = 1.5 * (x - IMG_WIDTH / 2) /
						(0.5 * g->fr.zoom * IMG_WIDTH) + g->fr.move_x;
		g->fr.c_im = (y - IMG_HIGHT / 2) /
						(0.5 * g->fr.zoom * IMG_HIGHT) + g->fr.move_y;
		g->fr.new_re = 0;
		g->fr.new_im = 0;
	}
}

static void	pixel_calc_color(t_global *g, int i)
{
	double	t;

	t = (double)(i) / (double)(g->fr.max_iterations);
	g->fr.color = (((int)((9 * (1 - t) * t * t * t * 255)) << 16) |
		(((int)(15 * (1 - t) * (1 - t) * t * t * 255)) << 8)) |
					(int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	g->fr.color = change_color_rgb(g->fr.color, g->fr.c_step_x,
											g->fr.c_step_y, g->fr.a_s);
}

void		draw_fractol(t_global *g)
{
	int	y;
	int	x;
	int	(*iterate[5])(t_global*);

	iterate[0] = &julia_iter;
	iterate[1] = &mandelbrot_iter;
	iterate[2] = &buffalo_iter;
	iterate[3] = &burningship_iter;
	iterate[4] = &burningstar_iter;
	y = g->ystart;
	while (y < g->yend)
	{
		x = g->xstart;
		while (x < g->xend)
		{
			iteration_init(g, x, y);
			pixel_calc_color(g, iterate[g->fractol_select - 1](g));
			ft_putpixel(g, x, y, g->fr.color);
			x++;
		}
		y++;
	}
}

int			ft_draw(t_global *g)
{
	g->mlx_ptr = mlx_init();
	g->win_ptr = mlx_new_window(g->mlx_ptr, WIDTH, HIGHT, "Fractol");
	g->img_ptr = mlx_new_image(g->mlx_ptr, IMG_WIDTH, IMG_HIGHT);
	g->adr = mlx_get_data_addr(g->img_ptr, &g->bpp, &g->size_line, &g->endian);
	ft_draw_menu_start(g);
	ft_draw_menu_end(g);
	mlx_hook(g->win_ptr, 17, 0, ft_x, g);
	mlx_hook(g->win_ptr, 2, 0, ft_keys, g);
	mlx_hook(g->win_ptr, 4, 0, ft_mouse_press, g);
	mlx_hook(g->win_ptr, 5, 0, ft_mouse_release, g);
	mlx_hook(g->win_ptr, 6, 0, ft_mouse_move, g);
	mlx_loop(g->mlx_ptr);
	return (0);
}
