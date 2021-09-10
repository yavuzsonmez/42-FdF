/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 10:51:44 by ysonmez           #+#    #+#             */
/*   Updated: 2021/09/10 12:00:32 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

/*
void ft_translate(int keycode, t_vars *vars)
{
	if (keycode == UP)
	{
		ft_transform_data(&data, matrix, 0);
		drawline(&t_img, matrix, &data, 0);
		t_img->img = mlx_new_image(vars->mlx, SCREEN_W, SCREEN_H);
		mlx_put_image_to_window(vars->mlx, vars->win, t_img->img, 0, 0);
	}
}
*/

void ft_transform_data(t_parse *data, t_matrix *matrix, int transform)
{
	size_t i;

	i = 0;
	while (i < (data->row * data->col))
	{
		if (matrix[i].z != 0)
		{
			matrix[i].x = (matrix[i].x - matrix[i].y) * cos(0.3) * SCALE + (SCREEN_W / 2) + transform;
			matrix[i].y = ((matrix[i].x + matrix[i].y) * sin(0.3) - matrix[i].z) * SCALE + (SCREEN_H / 2) + transform;
		}
		else
		{
			matrix[i].x = matrix[i].x * SCALE + (SCREEN_W / 2) + transform;
			matrix[i].y = matrix[i].y * SCALE + (SCREEN_H / 2) + transform;
		}
		i++;
	}
}