/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 11:44:37 by ysonmez           #+#    #+#             */
/*   Updated: 2021/09/03 11:31:40 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

char *ft_get_color(char *str)
{
	size_t i;

	i = 0;
	while(str[i] != '\0' && str[i] != ',')
		i++;
	if (str[i] == ',')
	{
		++i;
		return (str + i);
	}
	return NULL;
}

int ft_store_data(char *str, t_parse *data, t_matrix *matrix)
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
	while(i < data->row)
	{
		data->buf = get_next_line(fd);
		if (data->buf == NULL)
			return (-1);
		data->arr = ft_split(data->buf, ' ');
		k = 0;
		while(k < data->col)
		{
			matrix[e].x = k;
			matrix[e].y = i;
			matrix[e].z = ft_atoi(data->arr[k]);
			matrix[e].color = ft_get_color(data->arr[k]);
			//printf("%s\n", data->arr[k]);
			printf("struct %zu, X : %d, Y : %d, Z : %d, Color : %s\n", e, matrix[e].x, matrix[e].y, matrix[e].z, matrix[e].color);
			k++;
			e++;
		}
		printf("________________\n");
		ft_memfree(data->buf);
		ft_memfreeall((void *)data->arr);
		i++;
	}
	//matrix[e] = NULL;
	close(fd);
	return (0);
}

int ft_count_row_col(char *str, t_parse *data)
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
	while(data->arr[i] != NULL)
	{
			data->col++;
			i++;
	}
	ft_memfree(data->str);
	ft_memfreeall((void *)data->arr);
	while(data->buf != NULL)
	{
		data->row++;
		ft_memfree(data->buf);
		data->buf = get_next_line(fd);
	}

	/*TEST*/
	printf("row : %zu\n", data->row);
	printf("col : %zu\n", data->col);

	close(fd);
	return (0);
}
