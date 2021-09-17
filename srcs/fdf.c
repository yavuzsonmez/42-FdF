/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:55:57 by ysonmez           #+#    #+#             */
/*   Updated: 2021/09/09 13: by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

/* Printing info related to stored data */

void ft_tester(t_parse *data, t_matrix *matrix)
{
	size_t i;

	i = 0;
	while (i < (data->col * data->row))
	{
		printf("struct %zu, X : %d, Y : %d, Z : %d, Color : %d\n", i + 1, matrix[i].x, matrix[i].y, matrix[i].z, matrix[i].color);
		i++;
	}
}

/*
void free_memory()
{

}
*/

t_matrix *error_checker(int argc, char **argv, t_parse *data)
{
	t_matrix	*matrix;
	if (argc != 2)
	{
		ft_putendl_fd("Error", 1);
		return (NULL);
	}
	if (ft_count_row_col(argv[1], data) == -1)
	{
		ft_putendl_fd("Error", 1);
		return (NULL);
	}
	matrix = (t_matrix *)ft_calloc(sizeof(t_matrix), data->size);
	if (matrix == NULL)
	{
		ft_putendl_fd("Error", 1);
		ft_memfreeall((void *)matrix);
		return (NULL);
	}
	if (ft_store_data(argv[1], data, matrix) == -1)
	{
		ft_putendl_fd("Error", 1);
		ft_memfreeall((void *)matrix);
		return (NULL);
	}
	return (matrix);
}

t_screen *scale_window(t_parse *data)
{
	t_screen	*screen;

	(void)data;
	screen = (t_screen *)ft_calloc(sizeof(t_screen), 1);
	if (screen == NULL)
		return (NULL);
	screen->SCREEN_W = 1920;
	screen->SCREEN_H = 1080;
	screen->SCALE = 20;
	return (screen);
}

void create_window(t_matrix *matrix, t_parse *data)
{
	t_vars		*vars;
	t_data		*img;
	t_matrix	*isomatrix;
	t_screen	*screen;

	/* Find a way to check and free everything */
	vars = (t_vars *)ft_calloc(sizeof(t_vars), 1);
	img = (t_data *)ft_calloc(sizeof(t_data), 1);
	screen = scale_window(data);
	/* Find a way to check and free everything */

	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, screen->SCREEN_W, screen->SCREEN_H, "FdF");

	img->img = mlx_new_image(vars->mlx, screen->SCREEN_W, screen->SCREEN_H);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);

	/* Find a way to check and free everything */
	isomatrix = to_isometric(data, matrix, screen);
	/* Find a way to check and free everything */
	draw(img, matrix, data, screen, isomatrix);


	mlx_put_image_to_window(vars->mlx, vars->win, img->img, 0, 0);

	mlx_hook(vars->win, 2, 1L<<0, close_window, vars);
	mlx_hook(vars->win, 2, 1L<<0, zoom, vars);

	mlx_loop(vars->mlx);


	//ft_memfreeall((void *)screen);
	//ft_memfreeall((void *)isomatrix);

}

int main(int argc, char **argv)
{
	t_matrix	*matrix;
	t_parse		*data;

	data = (t_parse *)ft_calloc(sizeof(t_parse), 1);
	if (data == NULL)
		return (-1);
	matrix = error_checker(argc, argv, data);
	if (matrix == NULL)
		return (-1);

	/* TEST PRINT */
	ft_tester(data, matrix);
	/* END TEST */

	create_window(matrix, data);
	ft_memfreeall((void *)matrix);
	ft_memfreeall((void *)data);
	return (0);
}
