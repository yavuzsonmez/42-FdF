/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:17:58 by ysonmez           #+#    #+#             */
/*   Updated: 2021/09/20 16:14:12 by ysonmez          ###   ########.fr       */
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
	{

		render(fdf, fdf->screen.projection);
	}
	return (0);
}

/* Change the altitude with - or + on the keypad (scale Z factor on the isometric algorithm) */

int	altitude(int keycode, t_fdf *fdf)
{
	size_t i;

	i = 0;
	if (keycode == MINUS)
	{
		while(i < fdf->data.size)
		{
			if (fdf->matrix[i].z > 0)
				fdf->matrix[i].z -= 1;
			i++;
		}
		render(fdf, fdf->screen.projection);
	}
	else if (keycode == PLUS)
	{
		while(i < fdf->data.size)
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
	size_t i;

	i = 0;
	if (keycode == POV1)
		render(fdf, ISOMETRIC);
	if (keycode == POV2)
		render(fdf, PARALLEL);
	return (0);
}

/* ZOOM with MOUSE WHEEL (scale factor) */

int zoom(int keycode, int x, int y, t_fdf *fdf)
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
/*
int	rotate(int keycode, t_fdf *fdf)
{
	size_t i;

	i = 0;
	fdf->img.img = mlx_new_image(fdf->vars.mlx, WIDTH, HEIGHT);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bits_per_pixel, &fdf->img.line_length, &fdf->img.endian);
	if (keycode == 13)
	{
		while(i < fdf->data.size)
		{
 			fdf->matrix[i].y = fabs(fdf->matrix[i].y * cos(1.5708) - fdf->matrix[i].z * sin(1.5708));
 			fdf->matrix[i].z = fabs(fdf->matrix[i].y * sin(1.5708) + fdf->matrix[i].z * cos(1.5708));
			i++;
		}
	}
	else if (keycode == 2)
	{
		while(i < fdf->data.size)
		{
 			fdf->matrix[i].x = fabs(fdf->matrix[i].x * cos(1.5708) + fdf->matrix[i].z * sin(1.5708));
 			fdf->matrix[i].z = fabs(fdf->matrix[i].z * cos(1.5708) - fdf->matrix[i].x * sin(1.5708));
			i++;
		}
	}
	else if (keycode == 0)
	{
		while(i < fdf->data.size)
		{
 			fdf->matrix[i].x = fabs(fdf->matrix[i].x * cos(1.5708) - fdf->matrix[i].y * sin(1.5708));
 			fdf->matrix[i].y = fabs(fdf->matrix[i].x * sin(1.5708) + fdf->matrix[i].y * cos(1.5708));
			i++;
		}
	}
	draw(fdf);
	mlx_put_image_to_window(fdf->vars.mlx, fdf->vars.win, fdf->img.img, 0, 0);
	return (0);
}
*/

