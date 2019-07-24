#include "fractol.h"

int		ft_re_draw(t_global *g)
{
	ft_printf("\tft_re_draw [%d]\n", g->i_tester++);
	ft_threads(g);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_ptr, 0, 0);
	ft_bzero(g->adr, sizeof(g->adr));
	return (0);
}

void	ft_threads(t_global *g)
{
	t_global	glbl[THREADS];
	int		i;

	i = -1;
	while (++i < THREADS)
	{
		glbl[i] = *g;
		glbl[i].xstart = 0;
		glbl[i].xend = IMG_WIDTH;
		glbl[i].ystart = IMG_HIGHT / THREADS * i;
		glbl[i].yend = IMG_HIGHT / THREADS * (i + 1);
		pthread_create(&g->threads[i], NULL,
		(void *)draw_fractol, (void *)&glbl[i]);
	}
	i = -1;
	while (++i < THREADS)
		pthread_join(g->threads[i], NULL);
}
