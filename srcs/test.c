/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:55:57 by ysonmez           #+#    #+#             */
/*   Updated: 2021/08/27 16:59:53 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

int main(int argc, char **argv)
{
	int		fd;
	char	*line;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	t_mlx	img;

	if (argc != 2)
	{
		perror(NULL);
		return (-1);
	}
	mlx = mlx_init();
	img.img = mlx_new_image(mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx_win = mlx_new_window(mlx, 500, 500, "FdF");
	mlx_loop(mlx);
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	//ft_putstr_fd(line, 1);
	close(fd);
	return (0);
}