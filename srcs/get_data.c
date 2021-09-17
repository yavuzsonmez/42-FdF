/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 11:44:37 by ysonmez           #+#    #+#             */
/*   Updated: 2021/09/17 18:52:48 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

static char	*check_base(char *str)
{
	size_t	i;
	int		b;
	char	*base;

	i = 0;
	b = -1;
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else if (str[i] >= 'a' && str[i] <= 'z')
			b = 0;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			b = 1;
		if (b == 0 || b == 1)
			break ;
	}
	if (b == 0)
		base = ft_strdup("0123456789abcdef");
	else
		base = ft_strdup("0123456789ABCDEF");
	return (base);
}

static int	from_hexa_to_dec(char *str, size_t i, int color)
{
	int		len;
	char	*base;

	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '0' && str[i + 1] == 'x')
		i += 2;
	len = ft_strlen(str + i);
	if (ft_strchr(str + i, '\n') != NULL)
		len--;
	base = check_base(str + i);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			break ;
		len--;
		color += ft_strchr_pos(base, str[i]) * pow(16, len);
		i++;
	}
	ft_memfree(base);
	return (color);
}

static int	get_color(char *str)
{
	size_t	i;
	int		color;

	i = 0;
	color = 16777215;
	while (str[i] != '\0' && str[i] != ',')
		i++;
	if (str[i++] == ',')
		color = from_hexa_to_dec(str + i, 0, 0);
	return (color);
}

int	count_row_col(char *str, t_fdf *fdf)
{
	size_t		i;
	int			fd;

	i = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (-1);
	fdf->data.buf = get_next_line(fd);
	fdf->data.str = ft_strtrim(fdf->data.buf, "\n");
	fdf->data.arr = ft_split(fdf->data.str, ' ');
	while (fdf->data.arr[i++] != NULL)
		fdf->data.col++;
	ft_memfree(fdf->data.str);
	ft_memfreeall((void *)fdf->data.arr);
	while (fdf->data.buf != NULL)
	{
		fdf->data.row++;
		ft_memfree(fdf->data.buf);
		fdf->data.buf = get_next_line(fd);
	}
	fdf->data.size = fdf->data.row * fdf->data.col;
	close(fd);
	return (0);
}

int	store_data(char *str, t_fdf *fdf, size_t i, size_t e)
{
	size_t		k;
	int			fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (i < fdf->data.row)
	{
		fdf->data.buf = get_next_line(fd);
		if (fdf->data.buf == NULL)
			return (-1);
		fdf->data.arr = ft_split(fdf->data.buf, ' ');
		k = 0;
		while (k < fdf->data.col)
		{
			fdf->matrix[e].x = k;
			fdf->matrix[e].y = i;
			fdf->matrix[e].z = ft_atoi(fdf->data.arr[k]);
			fdf->matrix[e++].color = get_color(fdf->data.arr[k++]);
		}
		ft_memfree(fdf->data.buf);
		ft_memfreeall((void *)fdf->data.arr);
		i++;
	}
	close(fd);
	return (0);
}
