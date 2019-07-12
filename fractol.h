/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuchko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 11:58:08 by okuchko           #+#    #+#             */
/*   Updated: 2019/03/30 12:00:37 by okuchko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "get_next_line.h"
# include "ft_printf.h"
# include "libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>

typedef struct	s_fdf_iso
{
	double		x;
	double		y;
	double		z;
}				t_iso;

typedef struct	s_fdf_nod
{
	int			x;
	int			y;
	int			z;
	int			argb;
}				t_nod;

// typedef struct	s_original_wire
// {
// 	t_nod		**nods;
// 	int			x_range;
// 	int			y_range;
// 	int			z_range;
// 	int			z_min;
// 	int			z_max;
// 	int			dx;
// 	int			dy;

// 	int			x_bias;
// 	int			y_bias;
// 	t_iso		angle;
// 	double		zoom;
// 	int			color_mod;
// }				t_wire;

typedef struct	s_global
{
	void		*mlx_ptr;
	void		*img_ptr;
	void		*win_ptr;
	char		*adr;
	int			bpp;
	int			size_line;
	int			endian;
	int			win_width;
	int			win_high;
	int			img_width;
	int			img_high;

	int			fractol_select;
	// t_wire		**w;
	// int			wire_mod;
	// t_wire		w_orig;
	// t_wire		w_up;
	// t_wire		w_iso;
	// t_wire		w_parral;
}				t_global;

int				ft_draw(t_global *g);
void			draw_julia(t_global *g);
void			ft_putpixel(t_global *f, int x, int y, int color);
int				rgb_to_int(int r, int g, int b, int alfa);


// void			ft_read(t_wire *wire, t_list **start, int argc, char **argv);

// int				ft_make_valid_wire(t_list *lst, t_wire *w);
// int				ft_get_x_range(t_list *lst);
// int				ft_get_z_range(t_wire *w);

// void			ft_fdf_init(t_fdf *f);
// void			ft_copy_params(t_wire *w1, t_wire *w2);
// int				ft_wires_malloc(t_fdf *f);
// void			ft_fit_wire(t_fdf *f, t_wire *w);
// void			ft_copy_wire(t_wire *w1, t_wire *w2);

// int				ft_draw(t_fdf *f);
// void			ft_re_draw(t_fdf *f);

// int				ft_aprox_color(t_nod n1, t_nod n2, double perc);
// void			ft_putpixel(t_fdf *f, int x, int y, int color);
// void			ft_putline(t_fdf *f, t_nod n1, t_nod n2);
// void			ft_putwire(t_fdf *f, t_wire *w);

// void			ft_move_wire(t_wire *w);
// void			ft_zoom_wire(t_wire *w);
// void			ft_rotate_wire(t_wire *w2, t_iso *iso);

// void			ft_color_by_z(t_wire *w);
// void			ft_color_fill(t_wire *w, int color);
// void			ft_iso_wire(t_wire *w1);
// void			ft_perspective_wire(t_wire *w1);

// int				ft_keys(int key, t_fdf *f);

// int				ft_fdf_atoi(char *str, int *res);
// int				ft_atoi_base_positiv(const char *s, int base);
// void			**ft_double_malloc(size_t size, size_t y, size_t x);

// void			ft_error(char *s);
// void			ft_show_list(t_list *lst);
// void			ft_show_wire_coordinates(t_wire *w);

#endif
