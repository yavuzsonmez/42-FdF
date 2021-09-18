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

static void	ft_tester(t_fdf *fdf)
{
	size_t	i;

	i = 0;
	while (i < (fdf->data.col * fdf->data.row))
	{
		printf("struct %zu, X : %d, Y : %d, Z : %d, Color : %d\n", i + 1, fdf->matrix[i].x, fdf->matrix[i].y, fdf->matrix[i].z, fdf->matrix[i].color);
		i++;
	}
}

int	error_checker(int argc, char **argv, t_fdf *fdf)
{
	int	error;

	error = 0;
	if (argc != 2)
		error = 1;
	if (count_row_col(argv[1], fdf) == -1 && error == 0)
		error = 1;
	fdf->matrix = (t_matrix *)ft_calloc(sizeof(t_matrix), fdf->data.size);
	if (fdf->matrix == NULL)
		error = 1;
	if (store_data(argv[1], fdf, 0, 0) == -1 && error == 0)
		error = 1;
	if (error == 1)
	{
		free_data_struct(fdf);
		ft_putendl_fd("Error", 1);
		return (-1);
	}
	else
		return (0);
}

void	scale_window(t_fdf *fdf)
{
	fdf->screen.width = 1920;
	fdf->screen.height = 1080;
	fdf->screen.scale = 30;
	return ;
}

void	create_window(t_fdf *fdf)
{
	scale_window(fdf);
	fdf->vars.mlx = mlx_init();
	fdf->vars.win = mlx_new_window(fdf->vars.mlx, fdf->screen.width, fdf->screen.height, "FdF");
	fdf->img.img = mlx_new_image(fdf->vars.mlx, fdf->screen.width, fdf->screen.height);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bits_per_pixel, &fdf->img.line_length, &fdf->img.endian);
	if (to_isometric(fdf) == -1)
	{
		ft_putendl_fd("Error", 1);
		free_data_struct(fdf);
		return ;
	}
	draw(fdf);
	mlx_put_image_to_window(fdf->vars.mlx, fdf->vars.win, fdf->img.img, 0, 0);
	//mlx_hook(fdf->vars.win, 2, 1L<<0, zoom, fdf);
	//mlx_hook(fdf->vars.win, 2, 1L<<0, close_window, fdf);
	mlx_hook(fdf->vars.win, 2, 1L<<0, zoom, fdf);
	mlx_loop(fdf->vars.mlx);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	fdf = init_data_struct();
	if (fdf == NULL)
		return (-1);
	if (error_checker(argc, argv, fdf) == -1)
		return (-1);
	/* TEST PRINT */
	ft_tester(fdf);
	/* END TEST */
	create_window(fdf);
	return (0);
}
