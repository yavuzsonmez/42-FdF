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
		printf("struct %zu, X : %f, Y : %f, Z : %f, Color : %d\n", i + 1, fdf->matrix[i].x, fdf->matrix[i].y, fdf->matrix[i].z, fdf->matrix[i].color);
		i++;
	}
}

void	rotate(t_fdf *fdf)
{
	rotate_x(fdf);
	rotate_y(fdf);
	rotate_z(fdf);
}

void	scale(t_fdf *fdf)
{
	size_t		i;

	i = 0;
	while (i < fdf->data.size)
	{
		fdf->isomatrix[i].x *= fdf->screen->scale;
		fdf->isomatrix[i].y *= fdf->screen->scale;
		i++;
	}
}

void	translate(t_fdf *fdf)
{
	size_t		i;

	i = 0;
	while (i < fdf->data.size)
	{
		fdf->isomatrix[i].x += fdf->screen->translate_x;
		fdf->isomatrix[i].y += fdf->screen->translate_y;
		i++;
	}
}

void	render(t_fdf *fdf)
{
	if (fdf->img.img != NULL && fdf->img.addr != NULL)
	{
		ft_memfree((void *)fdf->img.img);
		ft_memfree((void *)fdf->img.addr);
	}
	fdf->img.img = mlx_new_image(fdf->vars.mlx, WIDTH, HEIGHT);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bits_per_pixel,
			&fdf->img.line_length, &fdf->img.endian);
	to_isometric(fdf);
	rotate(fdf);
	scale(fdf);
	translate(fdf);
	draw(fdf);
	mlx_put_image_to_window(fdf->vars.mlx, fdf->vars.win, fdf->img.img, 0, 0);
}

void	create_window(t_fdf *fdf)
{
	fdf->screen = (t_screen *)ft_calloc(sizeof(t_screen), 1);
	fdf->screen->translate_x = WIDTH / 2;
	fdf->screen->translate_y = HEIGHT / 2;
	fdf->screen->scale = 30;
	fdf->screen->alt = 0;
	fdf->screen->alpha = 0;
	fdf->screen->beta = 0;
	fdf->screen->theta = 0;
	fdf->vars.mlx = mlx_init();
	fdf->vars.win = mlx_new_window(fdf->vars.mlx, WIDTH, HEIGHT, "FdF");
	fdf->isomatrix = (t_matrix *)ft_calloc(sizeof(t_matrix), fdf->data.size);
	if (fdf->isomatrix == NULL)
		//free_data_struct(fdf);
		return ;
	render(fdf);
	mlx_hook(fdf->vars.win, 2, 1L << 0, key_handler, fdf);
	mlx_hook(fdf->vars.win, 4, 1L << 2, zoom, fdf);
	//mlx_hook(fdf->vars.win, 6, 1L << 6, rotate, fdf);
	mlx_loop(fdf->vars.mlx);
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
		//free_data_struct(fdf);
		ft_putendl_fd("Error", 1);
		return (-1);
	}
	else
		return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)ft_calloc(sizeof(t_fdf), 1);
	if (fdf == NULL)
		return (-1);
	if (error_checker(argc, argv, fdf) == -1)
		return (-1);
	ft_tester(fdf);
	create_window(fdf);
	exit(EXIT_SUCCESS);
	return (0);
}
