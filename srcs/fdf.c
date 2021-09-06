/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:55:57 by ysonmez           #+#    #+#             */
/*   Updated: 2021/09/04 16:32:17 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

int	e_close(int keycode, t_vars *vars)
{
	if (keycode == ESCAPE)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(EXIT_SUCCESS);
	}
	else
		return (-1);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(int argc, char **argv)
{
	size_t		i;
	t_vars		vars;
	t_data		img;
	t_matrix	*matrix;
	t_parse		data;

	i = 0;
	if (argc != 2)
	{
		perror(NULL);
		return (-1);
	}
	if (ft_count_row_col(argv[1], &data) == -1)
		return (-1);
	matrix = (t_matrix *)ft_calloc(sizeof(t_matrix), (data.size + 1));
	if (matrix == NULL)
		return (-1);
	if (ft_store_data(argv[1], &data, matrix) == -1)
		return (-1);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "FdF");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	while (i < (data.row * data.col))
	{

		my_mlx_pixel_put(&img, matrix[i].x * 30 + 960, matrix[i].y * 30 + 540, 0x00FFFFFF);
		i++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, e_close, &vars);
	mlx_loop(vars.mlx);

	/*
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	ft_putstr_fd(line, 1);
	close(fd);
	*/

	return (0);
}