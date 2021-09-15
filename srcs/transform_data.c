/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 10:51:44 by ysonmez           #+#    #+#             */
/*   Updated: 2021/09/15 14:49:17 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

t_matrix *to_isometric(t_parse *data, t_matrix *matrix, t_screen *screen)
{
	size_t		i;
	t_matrix	*isomatrix;

	isomatrix = (t_matrix *)ft_calloc(sizeof(t_matrix), data->size);
	i = 0;
	while (i < data->size)
	{
		isomatrix[i].z = matrix[i].z;
		isomatrix[i].color = matrix[i].color;
		isomatrix[i].x = (matrix[i].x - matrix[i].y) * cos(0.3) * screen->SCALE + (screen->SCREEN_W / 2);
		isomatrix[i].y = ((matrix[i].x + matrix[i].y) * sin(0.3) - matrix[i].z) * screen->SCALE + (screen->SCREEN_H / 2);
		i++;
	}
	return (isomatrix);
}
