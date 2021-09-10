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

void ft_tester(t_parse *data, t_matrix *matrix)
{

	size_t e;

	e = 0;
	while (e < (data->col * data->row))
	{
		printf("struct %zu, X : %d, Y : %d, Z : %d, Color : %d\n", e, matrix[e].x, matrix[e].y, matrix[e].z, matrix[e].color);
		e++;
	}
}

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

void drawline(t_data *img, t_matrix *matrix, t_parse *data, size_t i)
{
	int dx;
	int dy;
	int p;
	int x;
	int y;

	while (i < data->row * data->col)
	{
		dx = matrix[i + 1].x - matrix[i].x;
		dy = matrix[i + 1].y - matrix[i].y;
		x = matrix[i].x * SCALE;
		y = matrix[i].y * SCALE;
		p = 2 * dy - dx;
		while (x < matrix[i + 1].x * SCALE)
		{
			if (p >= 0)
			{
				my_mlx_pixel_put(img, x, y, matrix[i].color);
				y++;
				p = p + 2 * dy - 2 * dx;
			}
			else
			{
				my_mlx_pixel_put(img, x, y, matrix[i].color);
				p = p + 2 * dy;
			}
			x++;
		}
		i++;
	}
	i = 0;
	while (i < data->row * data->col - data->col)
	{
		dx = matrix[i].x - matrix[i].x - 1;
		dy = matrix[i].y - matrix[i].y - 1;
		x = matrix[i].x * SCALE;
		y = matrix[i].y * SCALE;
		p = 2 * dy - dx;
		while (y < matrix[i + data->col].y * SCALE)
		{
			if (p >= 0)
			{
				my_mlx_pixel_put(img, x, y, matrix[i].color);
				x++;
				p = p + 2 * dy - 2 * dx;
			}
			else
			{
				my_mlx_pixel_put(img, x, y, matrix[i].color);
				p = p + 2 * dy;
			}
			y++;
		}
		i++;
	}
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
	/*TEST*/
	ft_tester(&data, matrix);
	/*END TEST*/
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "FdF");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	while (i < (data.row * data.col))
	{
		if (matrix[i].z == 0)
			my_mlx_pixel_put(&img, matrix[i].x * SCALE + 960, matrix[i].y * SCALE + 540, matrix[i].color);
		else
			my_mlx_pixel_put(&img, (matrix[i].x - matrix[i].y) * cos(0.3) * SCALE + 960, ((matrix[i].x + matrix[i].y ) * sin(0.3) - matrix[i].z) * SCALE + 540, matrix[i].color);
		i++;
	}
	drawline(&img, matrix, &data, 0);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, e_close, &vars);
	mlx_loop(vars.mlx);


	return (0);
}