/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:17:58 by ysonmez           #+#    #+#             */
/*   Updated: 2021/09/21 11:58:23 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

/* Event hook to close the window with ESCAPE */

int	close_window(t_fdf *fdf)
{
	mlx_destroy_window(fdf->vars.mlx, fdf->vars.win);
	exit(EXIT_SUCCESS);
}

/* Translate the view with keyapd arrows (translating factor on the algo) */

int	translate(int keycode, t_fdf *fdf)
{
	if (keycode == UP)
		fdf->screen.translate_y -= 5;
	if (keycode == DOWN)
		fdf->screen.translate_y += 5;
	if (keycode == RIGHT)
		fdf->screen.translate_x += 5;
	if (keycode == LEFT)
		fdf->screen.translate_x -= 5;
	if (keycode == UP || keycode == DOWN || keycode == RIGHT || keycode == LEFT)
		render(fdf, fdf->screen.projection);
	return (0);
}

/* Change altitude with -/+ on the keypad (scale Z) */

int	altitude(int keycode, t_fdf *fdf)
{
	size_t	i;

	i = 0;
	if (keycode == MINUS)
	{
		while (i < fdf->data.size)
		{
			if (fdf->matrix[i].z > 0)
				fdf->matrix[i].z -= 1;
			i++;
		}
		render(fdf, fdf->screen.projection);
	}
	else if (keycode == PLUS)
	{
		while (i < fdf->data.size)
		{
			if (fdf->matrix[i].z != 0)
				fdf->matrix[i].z += 1;
			i++;
		}
		render(fdf, fdf->screen.projection);
	}
	return (0);
}

/* Change de point of view with 0 or 1 on the keypad (cos/sin factor on the isometric algo) */

int	change_view(int keycode, t_fdf *fdf)
{
	size_t	i;

	i = 0;
	if (keycode == POV1)
		render(fdf, ISOMETRIC);
	if (keycode == POV2)
		render(fdf, PARALLEL);
	return (0);
}

/* ZOOM with MOUSE WHEEL (scale factor) */

int	zoom(int keycode, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	if (keycode == MWU)
		fdf->screen.scale += 1;
	if (keycode == MWD)
		fdf->screen.scale += -1;
	if (keycode == MWU || keycode == MWD)
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
		if (keycode == 1)
		{
			fdf->isomatrix[i].y = fabs(fdf->isomatrix[i].y * cos(0.17) - fdf->isomatrix[i].z * sin(0.17));
			fdf->isomatrix[i].z = fabs(fdf->isomatrix[i].y * sin(0.17) + fdf->isomatrix[i].z * cos(0.17));
		}
		else if (keycode == 2)
		{

			fdf->isomatrix[i].x = fabs(fdf->isomatrix[i].x * cos(0.17) + fdf->isomatrix[i].z * sin(0.17));
			fdf->isomatrix[i].z = fabs(fdf->isomatrix[i].z * cos(0.17) - fdf->isomatrix[i].x * sin(0.17));
		}
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

