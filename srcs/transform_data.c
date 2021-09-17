/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 10:51:44 by ysonmez           #+#    #+#             */
/*   Updated: 2021/09/17 18:33:21 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

int to_isometric(t_fdf	*fdf)
{
	size_t		i;

	fdf->isomatrix = (t_matrix *)ft_calloc(sizeof(t_matrix), fdf->data.size);
	if (fdf->isomatrix == NULL)
		return (-1);
	i = 0;
	while (i < fdf->data.size)
	{
		fdf->isomatrix[i].z = fdf->matrix[i].z;
		fdf->isomatrix[i].color = fdf->matrix[i].color;
		fdf->isomatrix[i].x = (fdf->matrix[i].x - fdf->matrix[i].y) * cos(0.2) * fdf->screen.scale + (fdf->screen.width / 2);
		fdf->isomatrix[i].y = ((fdf->matrix[i].x + fdf->matrix[i].y) * sin(0.2) - fdf->matrix[i].z) * fdf->screen.scale + (fdf->screen.height / 2);
		i++;
	}
	return (0);
}
