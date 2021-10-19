/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 10:51:44 by ysonmez           #+#    #+#             */
/*   Updated: 2021/10/17 11:40:25 by home             ###   ########.fr       */
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
		fdf->isomatrix[i].x = fdf->matrix[i].x * fdf->screen.scale + fdf->screen.translate_x;
		if (fdf->matrix[i].y == 0)
			fdf->isomatrix[i].y = fdf->isomatrix[i].z * sin(0.8) * fdf->screen.scale + fdf->screen.translate_y;
		else if (fdf->matrix[i].y > 0 && fdf->matrix[i].z < 0)
			fdf->isomatrix[i].y = sqrt(pow(fdf->matrix[i].y, 2) + pow(fdf->isomatrix[i].z, 2)) * cos(0.8 + atan(fdf->isomatrix[i].z / fdf->matrix[i].y) + M_PI) * fdf->screen.scale + fdf->screen.translate_y;
		else
			fdf->isomatrix[i].y = sqrt(pow(fdf->matrix[i].y, 2) + pow(fdf->isomatrix[i].z, 2)) * cos(0.8 + atan(fdf->isomatrix[i].z / fdf->matrix[i].y)) * fdf->screen.scale + fdf->screen.translate_y;
		color_fade(fdf, i);
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
		if (!fdf->screen->set)
			fdf->isomatrix[i].z = fdf->matrix[i].z;
		else
			fdf->isomatrix[i].z = fdf->isomatrix[i].z;
		//color_fade(fdf, i);
		fdf->isomatrix[i].x = (fdf->matrix[i].x - fdf->matrix[i].y) * cos(0.8);
		fdf->isomatrix[i].y = ((fdf->matrix[i].x + fdf->matrix[i].y) * sin(0.3) - fdf->isomatrix[i].z);
		i++;
	}
	fdf->screen->set = 1;
	return (0);
}
