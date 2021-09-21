/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 10:51:44 by ysonmez           #+#    #+#             */
/*   Updated: 2021/09/21 11:22:20 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

int	to_parallel(t_fdf	*fdf)
{
	size_t	i;

	i = 0;
	while (i < fdf->data.size)
	{
		fdf->isomatrix[i].x = fdf->matrix[i].x * fdf->screen.scale + fdf->screen.translate_x;
		if (fdf->matrix[i].y == 0)
			fdf->isomatrix[i].y = fdf->matrix[i].z * sin(0.8) * fdf->screen.scale + fdf->screen.translate_y;
		else if (fdf->matrix[i].y > 0 && fdf->matrix[i].z < 0)
			fdf->isomatrix[i].y = sqrt(pow(fdf->matrix[i].y, 2) + pow(fdf->matrix[i].z, 2)) * cos(0.8 + atan(fdf->matrix[i].z / fdf->matrix[i].y) + M_PI) * fdf->screen.scale + fdf->screen.translate_y;
		else
			fdf->isomatrix[i].y = sqrt(pow(fdf->matrix[i].y, 2) + pow(fdf->matrix[i].z, 2)) * cos(0.8 + atan(fdf->matrix[i].z / fdf->matrix[i].y)) * fdf->screen.scale + fdf->screen.translate_y;
		i++;
	}
	fdf->screen.projection = PARALLEL;
	return (0);
}

int	to_isometric(t_fdf	*fdf)
{
	size_t		i;

	i = 0;
	while (i < fdf->data.size)
	{
		fdf->isomatrix[i].z = fdf->matrix[i].z;
		fdf->isomatrix[i].color = fdf->matrix[i].color;
		fdf->isomatrix[i].x = (fdf->matrix[i].x - fdf->matrix[i].y) * cos(0.8) * fdf->screen.scale + fdf->screen.translate_x;
		fdf->isomatrix[i].y = ((fdf->matrix[i].x + fdf->matrix[i].y) * sin(0.3) - fdf->matrix[i].z) * fdf->screen.scale + fdf->screen.translate_y;
		i++;
	}
	fdf->screen.projection = ISOMETRIC;
	return (0);
}
