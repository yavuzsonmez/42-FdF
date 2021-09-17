/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:17:58 by ysonmez           #+#    #+#             */
/*   Updated: 2021/09/17 12:38:59 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

/* Event hook to close the window with ESCAPE */

int	close_window(int keycode, t_vars *vars)
{
	if (keycode == ESCAPE)
	{
		mlx_destroy_image(vars->mlx, vars->win);
		mlx_destroy_window(vars->mlx, vars->win);
		//ft_memfree(vars->win);
		//ft_memfree(vars->mlx);
		exit(EXIT_SUCCESS);
	}
	else
		return (-1);
	return (0);
}


int	zoom(int keycode, t_vars *vars, t_parse *data, t_matrix *matrix, t_screen *screen, t_matrix *isomatrix)
{
	t_data		*tmp_img;
	tmp_img = (t_data *)ft_calloc(sizeof(t_data), 1);
	(void)matrix;
	(void)isomatrix;
	(void)data;
	(void)screen;
	(void)vars;
	(void)keycode;
	screen->SCALE += 5;
	tmp_img->img = mlx_new_image(vars->mlx, screen->SCREEN_W, screen->SCREEN_H);
	tmp_img->addr = mlx_get_data_addr(tmp_img->img, &tmp_img->bits_per_pixel, &tmp_img->line_length, &tmp_img->endian);
	draw(tmp_img, matrix, data, screen, isomatrix);
	mlx_put_image_to_window(vars->mlx, vars->win, tmp_img->img, 0, 0);
	printf("hello");
	return (0);
}
