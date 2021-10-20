/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 10:51:44 by ysonmez           #+#    #+#             */
/*   Updated: 2021/10/20 10:20:27 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

/*
int	to_parallel(t_fdf	*fdf)
{
	size_t	i;

	i = 0;
	while (i < fdf->data.size)
	{
		fdf->isomatrix[i].x = fdf->matrix[i].x;
		if (fdf->matrix[i].y == 0)
			fdf->isomatrix[i].y = fdf->isomatrix[i].z * sin(0.8);
		else if (fdf->matrix[i].y > 0 && fdf->matrix[i].z < 0)
			fdf->isomatrix[i].y = sqrt(pow(fdf->matrix[i].y, 2) + pow(fdf->isomatrix[i].z, 2)) * cos(0.8 + atan(fdf->isomatrix[i].z / fdf->matrix[i].y) + M_PI);
		else
			fdf->isomatrix[i].y = sqrt(pow(fdf->matrix[i].y, 2) + pow(fdf->isomatrix[i].z, 2)) * cos(0.8 + atan(fdf->isomatrix[i].z / fdf->matrix[i].y));
		i++;
	}
	fdf->screen.projection = PARALLEL;
	return (0);
}
*/

int	to_isometric(t_fdf	*fdf)
{
	size_t		i;

	i = 0;
	while (i < fdf->data.size)
	{
		if (fdf->matrix[i].z > 0 && (fdf->matrix[i].z + fdf->screen->alt) >= 0)
			fdf->isomatrix[i].z = fdf->matrix[i].z + fdf->screen->alt;
		else if (fdf->matrix[i].z < 0 && (fdf->matrix[i].z + fdf->screen->alt) <= 0)
			fdf->isomatrix[i].z = fdf->matrix[i].z - fdf->screen->alt;
		else if (fdf->matrix[i].z > 0 && (fdf->matrix[i].z + fdf->screen->alt) < 0)
			fdf->isomatrix[i].z = 0;
		else if (fdf->matrix[i].z < 0 && (fdf->matrix[i].z - fdf->screen->alt) > 0)
			fdf->isomatrix[i].z = 0;
		else
			fdf->isomatrix[i].z = fdf->matrix[i].z;
		 fdf->isomatrix[i].x = (fdf->matrix[i].x - fdf->matrix[i].y) * cos(0.314);
		 fdf->isomatrix[i].y = ((fdf->matrix[i].x + fdf->matrix[i].y) * sin(0.314) - fdf->isomatrix[i].z);
		i++;
	}
	return (0);
}
