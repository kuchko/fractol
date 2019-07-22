#include "fractol.h"

void				ft_threads(t_fractol *f)
{
	t_fractol	frct[THREADS];
	int		i;

	i = -1;
	while (++i < THREADS)
	{
		frct[i] = *head;
		frct[i].xstart = 0;
		frct[i].xend = WIDTH;
		frct[i].ystart = HEIGHT / THREAD * i;
		frct[i].yend = HEIGHT / THREAD * (i + 1);
		pthread_create(&head->threads[i], NULL,
		(void *)draw_fractol, (void *)&frct[i]);
	}
	i = -1;
	while (++i < THREAD)
		pthread_join(head->threads[i], NULL);


	// t_fractol	fs[STREAMS];
	// pthread_t	streams[STREAMS];
	// int			i;
	// int			x;

	// x = 0;
	// i = -1;
	// while (++i < STREAMS)
	// {
	// 	fs[i] = *f;
	// 	fs[i].img_first = x;
	// 	x += (WIN_WIDTH / STREAMS);
	// 	fs[i].img_last = x;
	// 	pthread_create(&streams[i], NULL, (void *)draw, (void *)&fs[i]);
	// }
	// i = -1;
	// while (++i < STREAMS)
	// 	pthread_join(streams[i], NULL);
	// mlx_put_image_to_window(f->img->mlx_ptr,
	// 				f->img->mlx_win, f->img->ptr, 0, 0);
	// mlx_destroy_image(f->img->mlx_ptr, f->img->ptr);
}
