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

	size_t e;

	e = 0;
	while (e < (data->col * data->row))
	{

		printf("struct %zu, X : %d, Y : %d, Z : %d, Color : %d\n", e + 1, matrix[e].x, matrix[e].y, matrix[e].z, matrix[e].color);
		e++;
	}
}




int main(int argc, char **argv)
{
	size_t		i;
	t_vars		vars;
	t_data		img;
	//t_data		t_img;
	t_matrix	*matrix;
	t_matrix	*isomatrix;
	t_parse		data;
	t_screen	screen;

	screen.SCREEN_W = 1920;
	screen.SCREEN_H = 1080;
	screen.SCALE = 30;
	i = 0;
	if (argc != 2)
	{
		ft_putendl_fd("Error", 1);
		return (-1);
	}
	if (ft_count_row_col(argv[1], &data) == -1)
		return (-1);
	matrix = (t_matrix *)ft_calloc(sizeof(t_matrix), data.size);
	if (matrix == NULL)
		return (-1);
	if (ft_store_data(argv[1], &data, matrix) == -1)
		return (-1);

	/* TEST PRINT */
	ft_tester(&data, matrix);
	/* END TEST */

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, screen.SCREEN_W, screen.SCREEN_H, "FdF");
	img.img = mlx_new_image(vars.mlx, screen.SCREEN_W, screen.SCREEN_H);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);




	isomatrix = to_isometric(&data, matrix, &screen);
	draw_line (&img, matrix, &data, &screen, isomatrix);
	draw_col (&img, matrix, &data, &screen, isomatrix);

	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, close_window, &vars);
	//mlx_hook(vars.win, 2, 1L<<0, ft_translate, &vars);

	mlx_loop(vars.mlx);

	/* free matrix / free isomatrix */
	return (0);
}