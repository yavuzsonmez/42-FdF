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

static void ft_tester(t_fdf *fdf)
{
	size_t i;

	i = 0;
	while (i < (fdf->data.col * fdf->data.row))
	{
		printf("struct %zu, X : %d, Y : %d, Z : %d, Color : %d\n", i + 1, fdf->matrix[i].x, fdf->matrix[i].y, fdf->matrix[i].z, fdf->matrix[i].color);
		i++;
	}
}

/*
void free_memory()
{

}
*/

int error_checker(int argc, char **argv, t_fdf *fdf)
{
	if (argc != 2)
	{
		ft_putendl_fd("Error", 1);
		return (0);
	}
	if (ft_count_row_col(argv[1], &fdf->data) == -1)
	{
		ft_putendl_fd("Error", 1);
		return (0);
	}
	fdf->matrix = (t_matrix *)ft_calloc(sizeof(t_matrix), fdf->data.size);
	if (fdf->matrix == NULL)
	{
		ft_putendl_fd("Error", 1);
		ft_memfreeall((void *)fdf->matrix);
		return (0);
	}
	if (ft_store_data(argv[1], &fdf->data, fdf->matrix) == -1)
	{
		ft_putendl_fd("Error", 1);
		ft_memfreeall((void *)fdf->matrix);
		return (0);
	}
	return (1);
}

void scale_window(t_fdf *fdf)
{
	fdf->screen.SCREEN_W = 1920;
	fdf->screen.SCREEN_H = 1080;
	fdf->screen.SCALE = 30;
	return ;
}

void create_window(t_fdf *fdf)
{

	scale_window(fdf);

	fdf->vars.mlx = mlx_init();
	fdf->vars.win = mlx_new_window(fdf->vars.mlx, fdf->screen.SCREEN_W, fdf->screen.SCREEN_H, "FdF");

	fdf->img.img = mlx_new_image(fdf->vars.mlx, fdf->screen.SCREEN_W, fdf->screen.SCREEN_H);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bits_per_pixel, &fdf->img.line_length, &fdf->img.endian);

	/* Find a way to check and free everything */
	fdf->isomatrix = to_isometric(&fdf->data, fdf->matrix, &fdf->screen);
	/* Find a way to check and free everything */
	draw(&fdf->img, fdf->matrix, &fdf->data, &fdf->screen, fdf->isomatrix);


	mlx_put_image_to_window(fdf->vars.mlx, fdf->vars.win, fdf->img.img, 0, 0);

	//mlx_hook(vars->win, 2, 1L<<0, close_window, fdf);

	//mlx_hook(vars->win, 2, 1L<<0, zoom, fdf);

	mlx_loop(fdf->vars.mlx);


}

t_fdf	*init_data_struct(void)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)ft_calloc(sizeof(t_fdf), 1);
	if (fdf == NULL)
	{
		ft_putendl_fd("Error", 1);
		return (NULL);
	}
	return (fdf);
/*
	t_vars		vars;
	t_data		img;
	t_parse		data;
	t_screen	screen;
	t_matrix	*matrix;
	t_matrix	*isomatrix;
*/
}

int main(int argc, char **argv)
{
	t_fdf	*fdf;

	fdf = init_data_struct();

	error_checker(argc, argv, fdf);

	/* TEST PRINT */
	ft_tester(fdf);
	/* END TEST */

	create_window(fdf);
	return (0);
}
