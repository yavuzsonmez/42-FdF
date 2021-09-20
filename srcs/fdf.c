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

void	scale_window(t_fdf *fdf)
{
	//fdf->screen = malloc(sizeof(t_screen));

	fdf->screen.translate_x = WIDTH / 2;
	fdf->screen.translate_y = HEIGHT / 2;
	fdf->screen.scale = 30;
	fdf->screen.cos = 0.8;
	fdf->screen.sin = 0.3;
	return ;
}

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
		//free_data_struct(fdf);
		ft_putendl_fd("Error", 1);
		return (-1);
	}
	else
		return (0);
}

void render(t_fdf *fdf)
{
	fdf->img.img = mlx_new_image(fdf->vars.mlx, WIDTH, HEIGHT);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bits_per_pixel, &fdf->img.line_length, &fdf->img.endian);
	to_isometric(fdf);
	draw(fdf);
	//mlx_clear_window (fdf->vars.mlx, fdf->vars.win);
	mlx_put_image_to_window(fdf->vars.mlx, fdf->vars.win, fdf->img.img, 0, 0);
	//mlx_destroy_image(fdf->vars.mlx, fdf->img.img);
}

int key_handler(int keycode, t_fdf *fdf)
{
	if (keycode == ESCAPE)
		close_window(fdf);
	else if (keycode == PLUS || keycode == MINUS)
		zoom(keycode, fdf);
	else if (keycode == UP || keycode == DOWN || keycode == RIGHT || keycode == LEFT)
		translate(keycode, fdf);
	else if (keycode == POV1 || keycode == POV2)
		pov(keycode, fdf);
	else
		return (-1);
	return (0);
}

void	create_window(t_fdf *fdf)
{
	scale_window(fdf);
	fdf->vars.mlx = mlx_init();
	fdf->vars.win = mlx_new_window(fdf->vars.mlx, WIDTH, HEIGHT, "FdF");
	fdf->img.img = mlx_new_image(fdf->vars.mlx, WIDTH, HEIGHT);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bits_per_pixel, &fdf->img.line_length, &fdf->img.endian);
	render(fdf);
	mlx_put_image_to_window(fdf->vars.mlx, fdf->vars.win, fdf->img.img, 0, 0);

	mlx_hook(fdf->vars.win, 2, 1L<<0, key_handler, fdf);
	mlx_hook(fdf->vars.win, 4, 1L<<2, scroll_handler, fdf);
	//mlx_hook(fdf->vars.win, 2, 1L<<0, translate, fdf);
	mlx_loop(fdf->vars.mlx);
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
	ft_memfree((void *)fdf);
	return (0);
}
