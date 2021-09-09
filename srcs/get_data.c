/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 11:44:37 by ysonmez           #+#    #+#             */
/*   Updated: 2021/09/09 15:43:47 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

static char	*ft_check_base(char *str)
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

static int	ft_from_hexa_to_dec(char *str, size_t i, int color)
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
	base = ft_check_base(str + i);
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

static int	ft_get_color(char *str)
{
	size_t	i;
	int		color;

	i = 0;
	color = 16777215;
	while (str[i] != '\0' && str[i] != ',')
		i++;
	if (str[i++] == ',')
		color = ft_from_hexa_to_dec(str + i, 0, 0);
	return (color);
}

int	ft_count_row_col(char *str, t_parse *data)
{
	size_t		i;
	int			fd;

	i = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (-1);
	data->buf = get_next_line(fd);
	data->str = ft_strtrim(data->buf, "\n");
	data->arr = ft_split(data->str, ' ');
	while (data->arr[i++] != NULL)
		data->col++;
	ft_memfree(data->str);
	ft_memfreeall((void *)data->arr);
	while (data->buf != NULL)
	{
		data->row++;
		ft_memfree(data->buf);
		data->buf = get_next_line(fd);
	}
	data->size = data->row * data->col;
	close(fd);
	return (0);
}

int	ft_store_data(char *str, t_parse *data, t_matrix *matrix)
{
	size_t		i;
	size_t		k;
	size_t		e;
	int			fd;

	i = 0;
	e = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (i < data->row)
	{
		data->buf = get_next_line(fd);
		if (data->buf == NULL)
			return (-1);
		data->arr = ft_split(data->buf, ' ');
		k = 0;
		while (k < data->col)
		{
			matrix[e].x = k;
			matrix[e].y = i;
			matrix[e].z = ft_atoi(data->arr[k]);
			matrix[e++].color = ft_get_color(data->arr[k++]);
		}
		ft_memfree(data->buf);
		ft_memfreeall((void *)data->arr);
		i++;
	}
	close(fd);
	return (0);
}
