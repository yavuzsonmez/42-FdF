/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:17:58 by ysonmez           #+#    #+#             */
/*   Updated: 2021/09/18 15:52:06 by ysonmez          ###   ########.fr       */
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
		fdf->matrix[0].y -= 1;
	if (keycode == DOWN)
		fdf->matrix[0].y += 1;
	if (keycode == RIGHT)
		fdf->matrix[0].x += 1;
	if (keycode == LEFT)
		fdf->matrix[0].x -= 1;
	if (keycode == UP || keycode == DOWN || keycode == RIGHT || keycode == LEFT)
	{
		fdf->img.img = mlx_new_image(fdf->vars.mlx, fdf->screen.width, fdf->screen.height);
		fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bits_per_pixel, &fdf->img.line_length, &fdf->img.endian);
		render(fdf);
		//mlx_clear_window (fdf->vars.mlx, fdf->vars.win);
		mlx_put_image_to_window(fdf->vars.mlx, fdf->vars.win, fdf->img.img, 0, 0);
		//mlx_destroy_image(fdf->vars.mlx, fdf->img.img);
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

	/*end-test*/
	if (keycode == PLUS)
		fdf->screen.scale += 1;
	if (keycode == MINUS)
		fdf->screen.scale += -1;
	if (keycode == PLUS || keycode == MINUS)
	{
		fdf->img.img = mlx_new_image(fdf->vars.mlx, fdf->screen.width, fdf->screen.height);
		fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bits_per_pixel, &fdf->img.line_length, &fdf->img.endian);
		render(fdf);
		//mlx_clear_window (fdf->vars.mlx, fdf->vars.win);
		mlx_put_image_to_window(fdf->vars.mlx, fdf->vars.win, fdf->img.img, 0, 0);
		//mlx_destroy_image(fdf->vars.mlx, fdf->img.img);
	}
	return (0);
}
