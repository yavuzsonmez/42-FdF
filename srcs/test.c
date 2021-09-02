/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yavuzsonmez <yavuzsonmez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:55:57 by ysonmez           #+#    #+#             */
/*   Updated: 2021/09/02 19:53:49 by yavuzsonmez      ###   ########.fr       */
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
	//int		fd;
	//char	*line;
	t_vars	vars;
	t_data	img;

	(void)argv;
	if (argc != 2)
	{
		perror(NULL);
		return (-1);
	}
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "FdF");
	img.img = mlx_new_image(vars.mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	my_mlx_pixel_put(&img, 25, 25, 0x00FF0000);
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