/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:09:42 by ysonmez           #+#    #+#             */
/*   Updated: 2021/10/19 16:59:39 by ysonmez          ###   ########.fr       */
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

void	rotate_x(int keycode, t_fdf *fdf)
{
	size_t	i;
	double	y;
	double	z;

	i = 0;
	if (keycode == D)
		fdf->screen->alpha += 0.1;
	else
		fdf->screen->alpha -= 0.1;
	while (i < fdf->data.size)
	{
		y = fdf->isomatrix[i].y;
		z = fdf->isomatrix[i].z;
		fdf->isomatrix[i].y = y * cos(fdf->screen->alpha) - z * sin(fdf->screen->alpha);
		fdf->isomatrix[i].z = y * sin(fdf->screen->alpha) + z * cos(fdf->screen->alpha);
		i++;
	}
}

void	rotate_y(int keycode, t_fdf *fdf)
{
	size_t	i;
	double	x;
	double	z;

	i = 0;
	if (keycode == W)
		fdf->screen->beta += 0.1;
	else
		fdf->screen->beta -= 0.1;
	while (i < fdf->data.size)
	{
		x = fdf->isomatrix[i].x;
		z = fdf->isomatrix[i].z;
		fdf->isomatrix[i].x = x * cos(fdf->screen->beta) + z * sin(fdf->screen->beta);
		fdf->isomatrix[i].z = z * cos(fdf->screen->beta) - x * sin(fdf->screen->beta);
		i++;
	}
}

void	rotate_z(int keycode, t_fdf *fdf)
{
	size_t	i;
	double	x;
	double	y;

	i = 0;
	if (keycode == E)
		fdf->screen->theta += 0.1;
	else
		fdf->screen->theta -= 0.1;
	while (i < fdf->data.size)
	{
		x = fdf->isomatrix[i].x;
		y = fdf->isomatrix[i].y;
		fdf->isomatrix[i].x = x * cos(fdf->screen->theta) - y * sin(fdf->screen->theta);
		fdf->isomatrix[i].y = x * sin(fdf->screen->theta) + y * cos(fdf->screen->theta);
		i++;
	}
}

int	to_isom(t_fdf	*fdf)
{
	size_t		i;

	i = 0;
	while (i < fdf->data.size)
	{
		fdf->isomatrix[i].z = fdf->matrix[i].z;
		//color_fade(fdf, i);
		fdf->isomatrix[i].x = (fdf->matrix[i].x - fdf->matrix[i].y) * cos(0.314);
		fdf->isomatrix[i].y = ((fdf->matrix[i].x + fdf->matrix[i].y) * sin(0.314) - fdf->isomatrix[i].z);
		i++;
	}
	return (0);
}

int	rotate(int keycode, t_fdf *fdf)
{
	to_isom(fdf);
	if (keycode == A || keycode == D)
		rotate_x(keycode, fdf);
	else if (keycode == S || keycode == W)
		rotate_y(keycode, fdf);
	else if (keycode == Q || keycode == E)
		rotate_z(keycode, fdf);
	else
		return (-1);
	ft_memfree((void *)fdf->img.img);
	ft_memfree((void *)fdf->img.addr);
	fdf->img.img = mlx_new_image(fdf->vars.mlx, WIDTH, HEIGHT);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bits_per_pixel,
			&fdf->img.line_length, &fdf->img.endian);
	scale(fdf);
	translate(fdf);
	draw(fdf);
	mlx_put_image_to_window(fdf->vars.mlx, fdf->vars.win, fdf->img.img, 0, 0);
	return (0);
}
