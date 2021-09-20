/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:17:58 by ysonmez           #+#    #+#             */
/*   Updated: 2021/09/20 11:08:18 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

/* Event hook to close the window with ESCAPE */

int	close_window(t_fdf *fdf)
{
	mlx_destroy_window(fdf->vars.mlx, fdf->vars.win);
	exit(EXIT_SUCCESS);
}

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
		render(fdf);
	}
	return (0);
}
/*
int	change_altitude(int keycode, t_fdf *fdf)
{

	while(i < fdf->data.size)
	{
		if (fdf->matrix[i].z != 0)
			fdf->matrix[i].z -= 1;
		i++;
	}


	fdf->img.img = mlx_new_image(fdf->vars.mlx, fdf->screen.width, fdf->screen.height);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bits_per_pixel, &fdf->img.line_length, &fdf->img.endian);
	render(fdf);
	//mlx_clear_window (fdf->vars.mlx, fdf->vars.win);
	mlx_put_image_to_window(fdf->vars.mlx, fdf->vars.win, fdf->img.img, 0, 0);
	//mlx_destroy_image(fdf->vars.mlx, fdf->img.img);
	return (0);
}
*/


int	zoom(int keycode, t_fdf *fdf)
{
	if (keycode == PLUS)
		fdf->screen.scale += 1;
	if (keycode == MINUS)
		fdf->screen.scale += -1;
	if (keycode == PLUS || keycode == MINUS)
		render(fdf);
	return (0);
}

int	pov(int keycode, t_fdf *fdf)
{
	if (keycode == POV1)
	{
		fdf->screen.cos = 0.8;
		fdf->screen.sin = 0.3;
		render(fdf);
	}
	if (keycode == POV2)
	{
		fdf->screen.cos = -0.8;
		fdf->screen.sin = -0.3;
		render(fdf);
	}
	return (0);
}

int scroll_handler(int keycode, int x, int y, t_fdf *fdf)
{
	size_t i;

	i = 0;
	(void)x;
	(void)y;
	if (keycode == 5)
	{
		while(i < fdf->data.size)
		{
			if (fdf->matrix[i].z > 0)
				fdf->matrix[i].z -= 1;
			i++;
		}
		render(fdf);
	}
	else if (keycode == 4)
	{
		while(i < fdf->data.size)
		{
			if (fdf->matrix[i].z >= 0)
				fdf->matrix[i].z += 1;
			i++;
		}
		render(fdf);
	}
	else
		return (-1);
	return (0);
}