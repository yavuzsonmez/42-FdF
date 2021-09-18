/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:17:58 by ysonmez           #+#    #+#             */
/*   Updated: 2021/09/18 12:01:14 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

/* Event hook to close the window with ESCAPE */

int	close_window(int keycode, t_fdf *fdf)
{
	(void)fdf;
	if (keycode == ESCAPE)
	{
		mlx_destroy_window(fdf->vars.mlx, fdf->vars.win);
		exit(EXIT_SUCCESS);
	}
	else
		return (-1);
	return (0);
}


int	zoom(int keycode, t_fdf *fdf)
{
	/*test*/
	if (keycode)
		write(1, "q", 1);
	size_t i;

	i = 0;
	while(i < fdf->data.size)
	{
		if (fdf->matrix[i].z != 0)
			fdf->matrix[i].z -= 5;
		i++;
	}
	/*end-test*/
	//fdf->screen.scale += 10;
	//mlx_destroy_image(fdf->vars.mlx, fdf->vars.win);
	//write(1, "q", 1);
	fdf->img.img = mlx_new_image(fdf->vars.mlx, fdf->screen.width, fdf->screen.height);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bits_per_pixel, &fdf->img.line_length, &fdf->img.endian);
	to_isometric(fdf);
	draw(fdf);
	//mlx_clear_window (fdf->vars.mlx, fdf->vars.win);
	mlx_put_image_to_window(fdf->vars.mlx, fdf->vars.win, fdf->img.img, 0, 0);
	mlx_destroy_image(fdf->vars.mlx, fdf->img.img);

	//
	//write(1, "q", 1);
	return (0);
}
