/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:09:42 by ysonmez           #+#    #+#             */
/*   Updated: 2021/09/21 20:15:23 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

/* ZOOM with MOUSE WHEEL (scale factor) */

int	zoom(int keycode, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	if (keycode == MOUSE_WHEEL_UP)
		fdf->screen.scale += 1;
	if (keycode == MOUSE_WHEEL_DOWN)
		fdf->screen.scale += -1;
	if (keycode == MOUSE_WHEEL_UP || keycode == MOUSE_WHEEL_DOWN)
		render(fdf, fdf->screen.projection);
	return (0);
}


int	rotate(int keycode, t_fdf *fdf)
{
	size_t	i;

	i = 0;
	fdf->img.img = mlx_new_image(fdf->vars.mlx, WIDTH, HEIGHT);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bits_per_pixel,
			&fdf->img.line_length, &fdf->img.endian);
	while (i < fdf->data.size)
	{
		/* Around X-axis */
		if (keycode == 1)
		{
			fdf->isomatrix[i].y = fabs(fdf->isomatrix[i].y * cos(0.17) - fdf->isomatrix[i].z * sin(0.17));
			fdf->isomatrix[i].z = fabs(fdf->isomatrix[i].y * sin(0.17) + fdf->isomatrix[i].z * cos(0.17));
		}
		/* Around Y-axis */
		else if (keycode == 2)
		{
			fdf->isomatrix[i].x = fabs(fdf->isomatrix[i].x * cos(0.17) + fdf->isomatrix[i].z * sin(0.17));
			fdf->isomatrix[i].z = fabs(fdf->isomatrix[i].z * cos(0.17) - fdf->isomatrix[i].x * sin(0.17));
		}
		/* Around Z-axis */
		else if (keycode == 0)
		{
			fdf->isomatrix[i].x = fabs(fdf->isomatrix[i].x * cos(0.17) - fdf->isomatrix[i].y * sin(0.17));
			fdf->isomatrix[i].y = fabs(fdf->isomatrix[i].x * sin(0.17) + fdf->isomatrix[i].y * cos(0.17));
		}
		i++;
	}
	draw(fdf);
	mlx_put_image_to_window(fdf->vars.mlx, fdf->vars.win, fdf->img.img, 0, 0);
	return (0);
}
