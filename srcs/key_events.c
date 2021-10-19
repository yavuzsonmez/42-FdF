/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:17:58 by ysonmez           #+#    #+#             */
/*   Updated: 2021/10/19 18:41:08 by ysonmez          ###   ########.fr       */
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

int	move(int keycode, t_fdf *fdf)
{
	if (keycode == DOWN)
		fdf->screen->translate_y -= 10;
	if (keycode == UP)
		fdf->screen->translate_y += 10;
	if (keycode == LEFT)
		fdf->screen->translate_x += 10;
	if (keycode == RIGHT)
		fdf->screen->translate_x -= 10;
	if (keycode == UP || keycode == DOWN || keycode == RIGHT || keycode == LEFT)
		render(fdf);
	return (0);
}

/* Change altitude with -/+ on the keypad (scale Z) */

int	altitude(int keycode, t_fdf *fdf)
{
	if (keycode == MINUS)
		fdf->screen->alt -= 1;
	else if (keycode == PLUS)
		fdf->screen->alt += 1;
	render(fdf);
	return (0);
}

int	key_handler(int keycode, t_fdf *fdf)
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
		event_rotate(keycode, fdf);
	else if (keycode == S || keycode == W)
		event_rotate(keycode, fdf);
	else if (keycode == Q || keycode == E)
		event_rotate(keycode, fdf);
	else
		return (-1);
	return (0);
}
