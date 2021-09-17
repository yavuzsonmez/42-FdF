/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:17:58 by ysonmez           #+#    #+#             */
/*   Updated: 2021/09/17 16:15:04 by ysonmez          ###   ########.fr       */
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
		//exit(EXIT_SUCCESS);
	}
	else
		return (-1);
	return (0);
}

/*
int	zoom(int keycode, t_d *s_test)
{
	(void)keycode;
	s_test->screen->SCALE += 1;
	mlx_destroy_image(s_test->vars->mlx, s_test->vars->win);

	s_test->img->img = mlx_new_image(s_test->vars->mlx, s_test->screen->SCREEN_W, s_test->screen->SCREEN_H);

	s_test->img->addr = mlx_get_data_addr(s_test->img->img, &s_test->img->bits_per_pixel, &s_test->img->line_length, &s_test->img->endian);

	draw(s_test->img, s_test->matrix, s_test->data, s_test->screen, s_test->isomatrix);
	mlx_put_image_to_window(s_test->vars->mlx, s_test->vars->win, s_test->img->img, 0, 0);
	write(1, "q", 1);
	return (0);
}
*/