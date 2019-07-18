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

// static void	ft_iso_change(int key, t_wire *w)
// {
// 	if (key == 87)
// 		w->angle.x -= M_PI_2 * 0.02;
// 	else if (key == 84)
// 		w->angle.x += M_PI_2 * 0.02;
// 	else if (key == 88)
// 		w->angle.y += M_PI_2 * 0.02;
// 	else if (key == 86)
// 		w->angle.y -= M_PI_2 * 0.02;
// 	else if (key == 85)
// 		w->angle.z += M_PI_2 * 0.02;
// 	else if (key == 83)
// 		w->angle.z -= M_PI_2 * 0.02;
// }

// static void	ft_zoom_change(int key, t_wire *w)
// {
// 	if (key == 78 && w->zoom >= 0.1)
// 		w->zoom -= 0.1;
// 	else if (key == 69 && w->zoom < 10.0)
// 		w->zoom += 0.1;
// }

// static void	ft_bias_change(int key, t_wire *w)
// {
// 	if (key == 123)
// 		w->x_bias -= 10;
// 	else if (key == 124)
// 		w->x_bias += 10;
// 	else if (key == 125)
// 		w->y_bias += 10;
// 	else if (key == 126)
// 		w->y_bias -= 10;
// }

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

	draw_julia(g);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_ptr, 0, 0);
	ft_bzero(g->adr, sizeof(g->adr));

	// else
	// 	ft_keys_continue(key, f);
	return (0);
}

int		ft_mouse(int key, int x, int y, t_global *g)
{
	int k;

	k = x + y;

	if (key == ZOOM_IN)
	{
		g->fr.move_y += (y - 0.5 * g->img_high) / g->img_high / g->fr.zoom / 2 ;
		g->fr.move_x += (x - 0.5 * g->img_width) / g->img_width / g->fr.zoom / 2;
		g->fr.zoom += 0.2 * g->fr.zoom;
	}
	else if (key == ZOOM_OUT)
	{
		g->fr.move_y -= (y - 0.5 * g->img_high) / g->img_high / g->fr.zoom /2;
		g->fr.move_x -= (x - 0.5 * g->img_width) / g->img_width / g->fr.zoom /2;
		g->fr.zoom -= 0.2 * g->fr.zoom;
	}
	ft_printf("%f\t", g->fr.zoom);
	draw_julia(g);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_ptr, 0, 0);
	ft_bzero(g->adr, sizeof(g->adr));
	return(0);
}
