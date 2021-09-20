/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 10:51:44 by ysonmez           #+#    #+#             */
/*   Updated: 2021/09/20 09:56:19 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

int	to_isometric(t_fdf	*fdf)
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
		fdf->isomatrix[i].x = (fdf->matrix[i].x - fdf->matrix[i].y) * cos(fdf->screen.cos) * fdf->screen.scale + fdf->screen.translate_x;
		fdf->isomatrix[i].y = ((fdf->matrix[i].x + fdf->matrix[i].y) * sin(fdf->screen.sin) - fdf->matrix[i].z) * fdf->screen.scale + fdf->screen.translate_y;
		i++;
	}
	return (0);
}
