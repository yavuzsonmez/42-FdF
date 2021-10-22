/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 10:51:44 by ysonmez           #+#    #+#             */
/*   Updated: 2021/10/22 11:20:06 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

/*	Create the starting isometric projection and apply the altitude value */

void	project(t_fdf	*fdf, size_t i)
{
	while (i < fdf->data.size)
	{
		if (fdf->matrix[i].z > 0)
		{
			if (fdf->matrix[i].z + fdf->screen->alt >= 0)
				fdf->isomatrix[i].z = fdf->matrix[i].z + fdf->screen->alt;
			else
				fdf->isomatrix[i].z = 0;
		}
		else if (fdf->matrix[i].z < 0)
		{
			if (fdf->matrix[i].z + fdf->screen->alt <= 0
				&& fdf->matrix[i].z + fdf->screen->alt >= fdf->matrix[i].z)
				fdf->isomatrix[i].z = fdf->matrix[i].z + fdf->screen->alt;
			else
				fdf->isomatrix[i].z = 0;
		}
		else
			fdf->isomatrix[i].z = fdf->matrix[i].z;
		fdf->isomatrix[i].x = fdf->matrix[i].x;
		fdf->isomatrix[i].y = fdf->matrix[i].y;
		i++;
	}
}

/*	Translate the origin point to the middle of the graph
*	in order to Rotate from the center and not from (0, 0)
*	Translate back to (0, 0) after rotation
*/

void	change_origin(t_fdf	*fdf, int origin)
{
	size_t		i;

	i = 0;
	while (i < fdf->data.size)
	{
		if (origin != 0)
		{
			fdf->isomatrix[i].z = fdf->isomatrix[i].z;
			fdf->isomatrix[i].x = fdf->isomatrix[i].x - (fdf->data.col / 2);
			fdf->isomatrix[i].y = fdf->isomatrix[i].y - (fdf->data.row / 2);
		}
		else
		{
			fdf->isomatrix[i].z = fdf->isomatrix[i].z;
			fdf->isomatrix[i].x = fdf->isomatrix[i].x + (fdf->data.col / 2);
			fdf->isomatrix[i].y = fdf->isomatrix[i].y + (fdf->data.row / 2);
		}
		i++;
	}
}

/*	Apply rotation matrix for X, Y and Z axis */

void	rotate(t_fdf *fdf)
{
	rotate_x(fdf);
	rotate_y(fdf);
	rotate_z(fdf);
}

/*	Scale the graph (make it bigger) with zoom */

void	scale(t_fdf *fdf)
{
	size_t		i;

	i = 0;
	while (i < fdf->data.size)
	{
		fdf->isomatrix[i].x *= fdf->screen->scale;
		fdf->isomatrix[i].y *= fdf->screen->scale;
		i++;
	}
}

/*	Translate the entire graph on the screen */

void	translate(t_fdf *fdf)
{
	size_t		i;

	i = 0;
	while (i < fdf->data.size)
	{
		fdf->isomatrix[i].x += fdf->screen->translate_x;
		fdf->isomatrix[i].y += fdf->screen->translate_y;
		i++;
	}
}
