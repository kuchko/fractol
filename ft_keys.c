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

static int	ft_keys_select(int key, t_global *g)
{
	if (key > 17 && key < 22)
		g->fractol_select = key - 17;
	else if (key == 23)
		g->fractol_select = 5;
	else if (key == 22)
		g->fractol_select = 6;
	else if (key == RELOAD)
	{
		ft_bzero(&g->fr, sizeof(g->fr));
		g->fr.zoom = 1;
		g->fr.zoom_step = 1.2;
		g->fr.max_iterations = 10;
		g->fr.c_re = -0.7;
		g->fr.c_im = 0.27015;
	}
	return (0);
}

static int	ft_keys_color(int key, t_global *g)
{
	if (key == COLOR_PLUS)
	{
		g->fr.c_step_x += 1;
		g->fr.c_step_y += 1;
	}
	else if (key == COLOR_MINUS)
	{
		g->fr.c_step_x -= 1;
		g->fr.c_step_y -= 1;
	}
	else if (key == ALPHA_PLUS && g->fr.a_s < 255)
		g->fr.a_s += 5;
	else if (key == ALPHA_MINUS && g->fr.a_s > 4)
		g->fr.a_s -= 5;
	else
		ft_keys_select(key, g);
	return (0);
}

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
	else
		ft_keys_color(key, g);
	ft_print_color(g->fr.color);
	ft_re_draw(g);
	return (0);
}

int		ft_mouse_press(int key, int x, int y, t_global *g)
{
	if (key == ZOOM_IN)
	{
		g->fr.move_y += ((2 * y - IMG_HIGHT) / (double) IMG_HIGHT - (2 * y - IMG_HIGHT) / (double) IMG_HIGHT / g->fr.zoom_step) / g->fr.zoom;
		g->fr.move_x += 1.5 * ((2 * x - IMG_WIDTH) / (double) IMG_WIDTH - (2 * x - IMG_WIDTH) / (double) IMG_WIDTH / g->fr.zoom_step) / g->fr.zoom;
		g->fr.zoom *= g->fr.zoom_step;
	}
	else if (key == ZOOM_OUT)
	{
		g->fr.move_y -= (2.0 * (y - IMG_HIGHT / 2) / (double) IMG_HIGHT - 2.0 * (y - IMG_HIGHT / 2) / (double) IMG_HIGHT / g->fr.zoom_step) / g->fr.zoom;// / g->fr.zoom_step;
		g->fr.move_x -= 1.5 * ((2 * x - IMG_WIDTH) / (double) IMG_WIDTH - (2 * x - IMG_WIDTH) / (double) IMG_WIDTH / g->fr.zoom_step) / g->fr.zoom;
		g->fr.zoom /= g->fr.zoom_step ;
	}
	else if (key == MOUSE_LEFT || key == MOUSE_RIGHT)
	{
		ft_printf("ft_mouse_press - left or righ \n");
		g->fr.flag_move = (key == MOUSE_LEFT) ? 1 : 0;
		g->fr.flag_color_move = (key == MOUSE_RIGHT) ? 1 : 0;
		g->fr.x_pre = x;
		g->fr.y_pre = y;
	}
	ft_printf("%f\t", g->fr.zoom);
	ft_re_draw(g);

	return(0);
}

int		ft_mouse_release(int key, int x, int y, t_global *g)
{
	x = y;
	if (key == MOUSE_LEFT || key == MOUSE_RIGHT)
	{
		ft_printf("\n OUT MOUSE UNPRESS\n");
		g->fr.flag_move = 0;
		g->fr.flag_color_move = 0;

	}
	return (0);
}

int		ft_mouse_move(int x, int y,  t_global *g)
{
	if ((g->fr.flag_move == 1 || g->fr.flag_color_move == 1)
		&& x > -1 && x < IMG_WIDTH && y > -1 && y < IMG_HIGHT)
	{
		ft_printf("\tft_mouse_move debug\t");
		if (g->fr.flag_move == 1)
		{
			g->fr.stp_re += 2.0 * (x - g->fr.x_pre) / IMG_WIDTH / g->fr.zoom;
			g->fr.stp_im += 2.0 * (y - g->fr.y_pre) / IMG_HIGHT / g->fr.zoom;
		}
		else
		{
			g->fr.c_step_x += (x - g->fr.x_pre) / 2;
			g->fr.c_step_y += (y - g->fr.y_pre) / 2;
		}
		g->fr.x_pre = x;
		g->fr.y_pre = y;
		ft_printf("(%d, %d)-", x, y);
		ft_printf("[%f, %f] ", g->fr.c_re, g->fr.c_im);
		ft_re_draw(g);
	}
	return(0);
}
