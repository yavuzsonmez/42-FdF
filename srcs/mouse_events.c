/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:09:42 by ysonmez           #+#    #+#             */
/*   Updated: 2021/10/18 14:07:57 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

/* ZOOM with MOUSE WHEEL (scale factor) */

int	zoom(int keycode, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	if (keycode == MOUSE_WHEEL_UP)
		fdf->screen->scale += 0.3;
	if (keycode == MOUSE_WHEEL_DOWN)
		fdf->screen->scale -= 0.3;
	if (keycode == MOUSE_WHEEL_UP || keycode == MOUSE_WHEEL_DOWN)
		render(fdf);
	return (0);
}

void	rotate_x(t_fdf *fdf)
{
	size_t	i;

	i = 0;
	while (i < fdf->data.size)
	{
		fdf->isomatrix[i].y = fabs(fdf->isomatrix[i].y * cos(fdf->screen->alpha) - fdf->isomatrix[i].z * sin(fdf->screen->alpha));
		fdf->isomatrix[i].z = fabs(fdf->isomatrix[i].y * sin(fdf->screen->alpha) + fdf->isomatrix[i].z * cos(fdf->screen->alpha));
		i++;
	}
}

void	rotate_y(t_fdf *fdf)
{
	size_t	i;

	i = 0;
	while (i < fdf->data.size)
	{
		fdf->isomatrix[i].x = fabs(fdf->isomatrix[i].x * cos(fdf->screen->beta) + fdf->isomatrix[i].z * sin(fdf->screen->beta));
		fdf->isomatrix[i].z = fabs(fdf->isomatrix[i].z * cos(fdf->screen->beta) - fdf->isomatrix[i].x * sin(fdf->screen->beta));
		i++;
	}
}

void	rotate_z(t_fdf *fdf)
{
	size_t	i;

	i = 0;
	while (i < fdf->data.size)
	{
		fdf->isomatrix[i].x = fabs(fdf->isomatrix[i].x * cos(fdf->screen->theta) - fdf->isomatrix[i].y * sin(fdf->screen->theta));
		fdf->isomatrix[i].y = fabs(fdf->isomatrix[i].x * sin(fdf->screen->theta) + fdf->isomatrix[i].y * cos(fdf->screen->theta));
		i++;
	}
}

int	rotate(int keycode, t_fdf *fdf)
{
	ft_memfree((void *)fdf->img.img);
	ft_memfree((void *)fdf->img.addr);
	fdf->img.img = mlx_new_image(fdf->vars.mlx, WIDTH, HEIGHT);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bits_per_pixel,
			&fdf->img.line_length, &fdf->img.endian);
	to_isometric(fdf);
	scale(fdf);
	translate(fdf);
	if (keycode == 1)
	{
		fdf->screen->alpha += 0.1;
		rotate_x(fdf);
	}
	else if (keycode == 2)
	{
		fdf->screen->beta += 0.1;
		rotate_y(fdf);
	}
	else if (keycode == 0)
	{
		fdf->screen->theta += 0.1;
		rotate_z(fdf);
	}
	else
		return (-1);
	draw(fdf);
	mlx_put_image_to_window(fdf->vars.mlx, fdf->vars.win, fdf->img.img, 0, 0);
	return (0);
}
