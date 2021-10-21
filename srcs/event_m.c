/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_m.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:09:42 by ysonmez           #+#    #+#             */
/*   Updated: 2021/10/21 17:40:36 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

/*	ZOOM with MOUSE WHEEL (SCALE the graph) */

int	zoom(int keycode, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	if (keycode == MOUSE_WHEEL_UP && fdf->screen->scale < 100)
		fdf->screen->scale += 0.3;
	else if (keycode == MOUSE_WHEEL_DOWN)
	{
		fdf->screen->scale -= 0.3;
		if (fdf->screen->scale < 1)
			fdf->screen->scale = 1;
	}
	if (keycode == MOUSE_WHEEL_UP || keycode == MOUSE_WHEEL_DOWN)
		render(fdf);
	else
		return (-1);
	return (0);
}

/*	X AXIS rotation calulations */

void	rotate_x(t_fdf *fdf)
{
	size_t	i;
	double	y;
	double	z;

	i = 0;
	while (i < fdf->data.size)
	{
		y = fdf->isomatrix[i].y;
		z = fdf->isomatrix[i].z;
		fdf->isomatrix[i].x = fdf->isomatrix[i].x;
		fdf->isomatrix[i].y = y * cos(fdf->screen->alpha)
			- z * sin(fdf->screen->alpha);
		fdf->isomatrix[i].z = y * sin(fdf->screen->alpha)
			+ z * cos(fdf->screen->alpha);
		i++;
	}
}

/*	Y AXIS rotation calulations */

void	rotate_y(t_fdf *fdf)
{
	size_t	i;
	double	x;
	double	z;

	i = 0;
	while (i < fdf->data.size)
	{
		x = fdf->isomatrix[i].x;
		z = fdf->isomatrix[i].z;
		fdf->isomatrix[i].x = x * cos(fdf->screen->beta)
			+ z * sin(fdf->screen->beta);
		fdf->isomatrix[i].y = fdf->isomatrix[i].y;
		fdf->isomatrix[i].z = z * cos(fdf->screen->beta)
			- x * sin(fdf->screen->beta);
		i++;
	}
}

/*	Z AXIS rotation calulations */

void	rotate_z(t_fdf *fdf)
{
	size_t	i;
	double	x;
	double	y;

	i = 0;
	while (i < fdf->data.size)
	{
		x = fdf->isomatrix[i].x;
		y = fdf->isomatrix[i].y;
		fdf->isomatrix[i].x = x * cos(fdf->screen->theta)
			- y * sin(fdf->screen->theta);
		fdf->isomatrix[i].y = x * sin(fdf->screen->theta)
			+ y * cos(fdf->screen->theta);
		fdf->isomatrix[i].z = fdf->isomatrix[i].z;
		i++;
	}
}

/*	Event hook for rotation
*		By using:
*			A or D: Rotate around X axis
*			W or S: Rotate around Y axis
*			E or Q: Rotate around Z axis
*/

int	angle(int keycode, t_fdf *fdf)
{
	if (keycode == D)
		fdf->screen->alpha += 0.05;
	else if (keycode == A)
		fdf->screen->alpha -= 0.05;
	else if (keycode == W)
		fdf->screen->beta += 0.05;
	else if (keycode == S)
		fdf->screen->beta -= 0.05;
	else if (keycode == E)
		fdf->screen->theta += 0.05;
	else if (keycode == Q)
		fdf->screen->theta -= 0.05;
	else
		return (-1);
	render(fdf);
	return (0);
}
