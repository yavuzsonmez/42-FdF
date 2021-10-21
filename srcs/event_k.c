/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_k.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:17:58 by ysonmez           #+#    #+#             */
/*   Updated: 2021/10/21 17:27:11 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

/*	Event hook to close the window with ESCAPE */

void	close_window(t_fdf *fdf)
{
	mlx_destroy_window(fdf->vars.mlx, fdf->vars.win);
	exit(EXIT_SUCCESS);
}

/*	Translate the view with KEYPAD ARROWS */

void	move(int keycode, t_fdf *fdf)
{
	if (keycode == DOWN)
		fdf->screen->translate_y -= 10;
	else if (keycode == UP)
		fdf->screen->translate_y += 10;
	else if (keycode == LEFT)
		fdf->screen->translate_x += 10;
	else if (keycode == RIGHT)
		fdf->screen->translate_x -= 10;
	if (keycode == UP || keycode == DOWN || keycode == RIGHT || keycode == LEFT)
		render(fdf);
}

/*	Change Z value with - and + on the KEYPAD */

void	altitude(int keycode, t_fdf *fdf)
{
	if (keycode == MINUS)
		fdf->screen->alt--;
	else if (keycode == PLUS)
		fdf->screen->alt++;
	if (keycode == PLUS || keycode == MINUS)
		render(fdf);
}

/*	KEYPRESS HANDLER : event hook depending of pressed key */

void	key_handler(int keycode, t_fdf *fdf)
{
	if (keycode == ESCAPE)
		close_window(fdf);
	else if (keycode == PLUS || keycode == MINUS)
		altitude(keycode, fdf);
	else if (keycode == UP || keycode == DOWN)
		move(keycode, fdf);
	else if (keycode == RIGHT || keycode == LEFT)
		move(keycode, fdf);
	else if (keycode == A || keycode == D)
		angle(keycode, fdf);
	else if (keycode == S || keycode == W)
		angle(keycode, fdf);
	else if (keycode == Q || keycode == E)
		angle(keycode, fdf);
	else
		return ;
}
