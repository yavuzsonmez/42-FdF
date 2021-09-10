/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 10:51:44 by ysonmez           #+#    #+#             */
/*   Updated: 2021/09/10 11:10:35 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

void ft_transform_data(t_parse *data, t_matrix *matrix)
{
	size_t i;

	i = 0;
	while (i < (data->row * data->col))
	{
		if (matrix[i].z != 0)
		{
			matrix[i].x = (matrix[i].x - matrix[i].y) * cos(0.3) * SCALE + (SCREEN_W / 2);
			matrix[i].y = ((matrix[i].x + matrix[i].y) * sin(0.3) - matrix[i].z) * SCALE + (SCREEN_H / 2);
		}
		else
		{
			matrix[i].x = matrix[i].x * SCALE + (SCREEN_W / 2);
			matrix[i].y = matrix[i].y * SCALE + (SCREEN_H / 2);
		}
		i++;
	}
}