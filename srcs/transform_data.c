/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 10:51:44 by ysonmez           #+#    #+#             */
/*   Updated: 2021/09/15 11:58:24 by ysonmez          ###   ########.fr       */
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

t_matrix *ft_transform_data(t_parse *data, t_matrix *matrix, t_screen *screen)
{
	size_t		i;
	t_matrix	*isomatrix;

	isomatrix = (t_matrix *)ft_calloc(sizeof(t_matrix), (data->size + 1));
	i = 0;
	while (i < data->size)
	{
		isomatrix[i].z = matrix[i].z;
		isomatrix[i].color = matrix[i].color;
		isomatrix[i].x = (matrix[i].x - matrix[i].y) * cos(0.3) * screen->SCALE + 960;
		isomatrix[i].y = ((matrix[i].x + matrix[i].y) * sin(0.3) - matrix[i].z) * screen->SCALE + 540;
		i++;
	}
	return (isomatrix);
}

/*
void ft_increase_altitude(t_parse *data, t_matrix *matrix)
{
	size_t	i;

	i = 0;
}

void ft_decrease_altitude(t_parse *data, t_matrix *matrix)
{
	size_t	i;

	i = 0;
}
*/