/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:09:42 by ysonmez           #+#    #+#             */
/*   Updated: 2021/10/19 11:24:34 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

/* ZOOM with MOUSE WHEEL (scale factor) */

int	zoom(int keycode, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	if (keycode == MOUSE_WHEEL_UP)
		fdf->screen->scale += 0.3;
	if (keycode == MOUSE_WHEEL_DOWN)
		fdf->screen->scale -= 0.3;
	if (keycode == MOUSE_WHEEL_UP || keycode == MOUSE_WHEEL_DOWN)
		render(fdf);
	return (0);
}

void	rotate_x(int keycode, t_fdf *fdf)
{
	size_t	i;

	i = 0;
	to_isometric(fdf);
	if (keycode == A)
		fdf->screen->alpha += 0.1;
	else
		fdf->screen->alpha -= 0.1;
	while (i < fdf->data.size)
	{
		fdf->isomatrix[i].y = fabs(fdf->isomatrix[i].y * cos(fdf->screen->alpha) - fdf->isomatrix[i].z * sin(fdf->screen->alpha));
		fdf->isomatrix[i].z = fabs(fdf->isomatrix[i].y * sin(fdf->screen->alpha) + fdf->isomatrix[i].z * cos(fdf->screen->alpha));
		i++;
	}
	render(fdf);
}

void	rotate_y(int keycode, t_fdf *fdf)
{
	size_t	i;

	i = 0;
	to_isometric(fdf);
	if (keycode == S)
		fdf->screen->beta += 0.1;
	else
		fdf->screen->beta -= 0.1;
	while (i < fdf->data.size)
	{
		fdf->isomatrix[i].x = fabs(fdf->isomatrix[i].x * cos(fdf->screen->beta) + fdf->isomatrix[i].z * sin(fdf->screen->beta));
		fdf->isomatrix[i].z = fabs(fdf->isomatrix[i].z * cos(fdf->screen->beta) - fdf->isomatrix[i].x * sin(fdf->screen->beta));
		i++;
	}
}

void	rotate_z(int keycode, t_fdf *fdf)
{
	size_t	i;

	i = 0;
	to_isometric(fdf);
	if (keycode == Q)
		fdf->screen->theta += 0.1;
	else
		fdf->screen->theta -= 0.1;
	while (i < fdf->data.size)
	{
		fdf->isomatrix[i].x = fabs(fdf->isomatrix[i].x * cos(fdf->screen->theta) - fdf->isomatrix[i].y * sin(fdf->screen->theta));
		fdf->isomatrix[i].y = fabs(fdf->isomatrix[i].x * sin(fdf->screen->theta) + fdf->isomatrix[i].y * cos(fdf->screen->theta));
		i++;
	}
}

int	rotate(int keycode, t_fdf *fdf)
{
	if (keycode == A || keycode == D)
		rotate_x(keycode, fdf);
	else if (keycode == S || keycode == W)
		rotate_y(keycode, fdf);
	else if (keycode == Q || keycode == E)
		rotate_z(keycode, fdf);
	else
		return (-1);
	render(fdf);
	return (0);
}
