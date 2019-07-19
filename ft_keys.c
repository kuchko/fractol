/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuchko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 13:50:24 by okuchko           #+#    #+#             */
/*   Updated: 2019/03/30 13:50:25 by okuchko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


// static int	ft_keys_continue(int key, t_global *g)
// {
// 	if (key == 78 || key == 69)
// 	{
// 		// ft_zoom_change(key, g->w[g->wire_mod]);
// 		ft_re_draw(g);
// 	}
// 	else if (key >= 123 || key <= 126)
// 	{
// 		// ft_bias_change(key, g->w[g->wire_mod]);
// 		ft_re_draw(g);
// 	}
// 	return (0);
// }

int			ft_keys(int key, t_global *g)
{
	if (key == ESC)
	{
		system("leaks fractol > leaks");
		exit(0);
	}
	else if (key == MOVE_UP)
		g->fr.move_y -= 0.2 / g->fr.zoom;
	else if (key == MOVE_DOWN)
		g->fr.move_y += 0.2 / g->fr.zoom;
	else if (key == MOVE_LEFT)
		g->fr.move_x -= 0.2 / g->fr.zoom;
	else if (key == MOVE_RIGHT)
		g->fr.move_x += 0.2 / g->fr.zoom;
	else if (key == ITER_PLUS)
		g->fr.max_iterations += 2;
	else if (key == ITER_MINUS)
		g->fr.max_iterations -= 2;
	else if (key == CENTER_ZOOM_IN)
		g->fr.zoom += 0.2 * g->fr.zoom;
	else if (key == CENTER_ZOOM_OUT)
		g->fr.zoom -= 0.2 * g->fr.zoom;

	draw_julia(g);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_ptr, 0, 0);
	ft_bzero(g->adr, sizeof(g->adr));

	// else
	// 	ft_keys_continue(key, f);
	return (0);
}

int		ft_mouse_press(int key, int x, int y, t_global *g)
{
	// int k;

	// k = x + y;

	if (key == ZOOM_IN)
	{
		//g->fr.zoom *= 1.1;

		/// this is [-1; 1]  :  2 * (y - g->img_high / 2) / (double) g->img_high;
		// g->fr.move_y += (2.0 * (y - g->img_high / 2) / (double) g->img_high - 2.0 * (y - g->img_high / 2) / (double) g->img_high / g->fr.zoom_step) / g->fr.zoom;

		g->fr.move_y += ((2 * y - g->img_high) / (double) g->img_high - (2 * y - g->img_high) / (double) g->img_high / g->fr.zoom_step) / g->fr.zoom;
		g->fr.move_x += 1.5 * ((2 * x - g->img_width) / (double) g->img_width - (2 * x - g->img_width) / (double) g->img_width / g->fr.zoom_step) / g->fr.zoom;
		g->fr.zoom *= g->fr.zoom_step;
		g->fr.max_iterations++;

	}
	else if (key == ZOOM_OUT)
	{

		g->fr.move_y -= (2.0 * (y - g->img_high / 2) / (double) g->img_high - 2.0 * (y - g->img_high / 2) / (double) g->img_high / g->fr.zoom_step) / g->fr.zoom;// / g->fr.zoom_step;
		g->fr.move_x -= 1.5 * ((2 * x - g->img_width) / (double) g->img_width - (2 * x - g->img_width) / (double) g->img_width / g->fr.zoom_step) / g->fr.zoom;
		// g->fr.move_x -= (x - 0.5 * g->img_width) / g->img_width / g->fr.zoom;
		g->fr.zoom /= g->fr.zoom_step ;
		g->fr.max_iterations--;
	}
	else if (key == MOUSE_LEFT)
	{
		g->fr.flag_move = 1;
		g->fr.x_pre = x;
		g->fr.y_pre = y;
		// ft_printf("(%d, %d)-", x, y);
	}

	ft_printf("%f\t", g->fr.zoom);
	draw_julia(g);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_ptr, 0, 0);
	ft_bzero(g->adr, sizeof(g->adr));
	return(0);
}

int		ft_mouse_release(int key, int x, int y, t_global *g)
{
		int k;

	k = x + y;
	if (key == MOUSE_LEFT)
	{
		ft_printf("\n OUT MOUSE UNPRESS\n");
		g->fr.flag_move = 0;

		// draw_julia(g);
		// mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_ptr, 0, 0);
		// ft_bzero(g->adr, sizeof(g->adr));
	}
	return (0);
}

int		ft_mouse_move(int x, int y,  t_global *g)
{
	if (g->fr.flag_move == 1 && x > -1 && x < g->img_width && y > -1 && y < g->img_high)
	{
		// g->fr.c_re = 2.0 * (double) x / (double) g->img_width - (2.0);
		// g->fr.c_im = (2.0) * (double) y / (double) g->img_high;
		g->fr.c_re += (double) (x - g->fr.x_pre) / (double) g->img_width / g->fr.zoom / 0.5;
		g->fr.c_im += (double) (y - g->fr.y_pre) / (double) g->img_high / g->fr.zoom / 0.5;
		g->fr.x_pre = x;
		g->fr.y_pre = y;
		ft_printf("(%d, %d)-", x, y);
		ft_printf("[%f, %f] ", g->fr.c_re, g->fr.c_im);

		draw_julia(g);
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_ptr, 0, 0);
		ft_bzero(g->adr, sizeof(g->adr));
	}

	return(0);
}
