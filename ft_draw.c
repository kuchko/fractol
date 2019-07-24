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

static int	ft_x(void *p)
{
	(void)p;
	system("leaks fractol > leaks");
	exit(0);
	return (0);
}

static void	ft_draw_menu_start(t_global *f)
{
	mlx_string_put(f->mlx_ptr, f->win_ptr, 740, 100, 0xff0000,
		"WELCOME to Fracol project by okuchko");
	mlx_string_put(f->mlx_ptr, f->win_ptr, 750, 250, 0x00ffff,
		"please, press any key to start:");
	mlx_string_put(f->mlx_ptr, f->win_ptr, 700, 300, 0xffd700,
		"1                         parallel up view");
	mlx_string_put(f->mlx_ptr, f->win_ptr, 700, 325, 0xffd700,
		"2                           isometric view");
	mlx_string_put(f->mlx_ptr, f->win_ptr, 700, 350, 0xffd700,
		"3                         perspective view");
	mlx_string_put(f->mlx_ptr, f->win_ptr, 700, 400, 0xffd700,
		"q                          original colors");
	mlx_string_put(f->mlx_ptr, f->win_ptr, 700, 425, 0xffd700,
		"w                          gradient colors");
	mlx_string_put(f->mlx_ptr, f->win_ptr, 700, 450, 0xffd700,
		"e                    fill with green color");
	mlx_string_put(f->mlx_ptr, f->win_ptr, 700, 500, 0xffd700,
		"left arrow                       move left");
	mlx_string_put(f->mlx_ptr, f->win_ptr, 700, 525, 0xffd700,
		"right arrow                     move right");
	mlx_string_put(f->mlx_ptr, f->win_ptr, 700, 550, 0xffd700,
		"up arrow                           move up");
	mlx_string_put(f->mlx_ptr, f->win_ptr, 700, 575, 0xffd700,
		"down arrow                       move down");
}

static void	ft_draw_menu_end(t_global *f)
{
	mlx_string_put(f->mlx_ptr, f->win_ptr, 700, 625, 0xffd700,
		"+                                zoom plus");
	mlx_string_put(f->mlx_ptr, f->win_ptr, 700, 650, 0xffd700,
		"-                               zoom minus");
	mlx_string_put(f->mlx_ptr, f->win_ptr, 700, 700, 0xffd700,
		"num 1                      turn by oZ left");
	mlx_string_put(f->mlx_ptr, f->win_ptr, 700, 725, 0xffd700,
		"num 3                     turn by oZ right");
	mlx_string_put(f->mlx_ptr, f->win_ptr, 700, 750, 0xffd700,
		"num 2                        turn by oX up");
	mlx_string_put(f->mlx_ptr, f->win_ptr, 700, 775, 0xffd700,
		"num 5                      turn by oX down");
	mlx_string_put(f->mlx_ptr, f->win_ptr, 700, 800, 0xffd700,
		"num 4                      turn by oY left");
	mlx_string_put(f->mlx_ptr, f->win_ptr, 700, 825, 0xffd700,
		"num 6                     turn by oY right");
}

int			ft_draw(t_global *g)
{
	g->mlx_ptr = mlx_init();
	g->win_ptr = mlx_new_window(g->mlx_ptr, WIDTH, HIGHT, "Fractol");
	g->img_ptr = mlx_new_image(g->mlx_ptr, IMG_WIDTH, IMG_HIGHT);
	g->adr = mlx_get_data_addr(g->img_ptr, &g->bpp, &g->size_line, &g->endian);
	ft_draw_menu_start(g);
	ft_draw_menu_end(g);

	// mlx_expose_hook(g->win_ptr, ft_re_draw, g);
	mlx_hook(g->win_ptr, 17, 0, ft_x, g);
	mlx_hook(g->win_ptr, 2, 0, ft_keys, g);
	mlx_hook(g->win_ptr, 4, 0, ft_mouse_press, g);
	mlx_hook(g->win_ptr, 5, 0, ft_mouse_release, g);
	mlx_hook(g->win_ptr, 6, 0, ft_mouse_move, g);
	mlx_loop(g->mlx_ptr);
	return (0);
}
