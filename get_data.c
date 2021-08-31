/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 11:44:37 by ysonmez           #+#    #+#             */
/*   Updated: 2021/08/31 16:22:37 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/FdF.h"

typedef struct s_parse
{
	char	*str;
	char	*buf;
	char	*tmp;
	char	*tmp2;
	size_t	row;
	size_t	col;
	char	**arr;
}	t_parse;
/*
void ft_get_color(char *str, t_matrix *matrix)
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
	return ;
}

void ft_create_struct_from_point(t_parse *data, t_matrix *matrix)
{
	size_t i;
	t_matrix point;

	i = 0;
	if (matrix == NULL)
		return ;
	while(matrix[i] != '\0')
		i++
	if (matrix[i] != NULL)
	{
		matrix[i]->x = data->col;
		matrix[i]->y = data->row;
		matrix[i]->z = ft_atoi(arr[i]);
		matrix[i]->color = ft_get_color();
	}
}
void ft_count_row_col(int fd, t_parse *data)
{
	size_t i;

	i = 0;
	data->buf = get_next_line(fd);
	data->arr = ft_split(data->str, ' ');
	while(data->arr[i] != NULL && data->arr[i] != '\n')
	{
		data->col++;
		i++;
	}
	while(data->buf != NULL)
	{
		data->row++;
		ft_memfree(data->buf);
		data->buf = get_next_line(fd);
	}

	i = 0;
	data->arr = ft_split(str, ' ');
	while(data->arr != NULL)
		i++;
	data->col =

	printf("row : %zu\n", data->row);
	printf("col : %zu\n", data->col);

}
*/

t_matrix *ft_get_data(int fd, t_parse *data)
{
	size_t i;
	t_matrix *matrix;

	i = 0;
	data->buf = get_next_line(fd);
	data->tmp = ft_strtrim(data->buf, "\n");
	data->tmp2 = ft_strjoin("  ", data->tmp);
	if(data->row == 0)
	{
		data->arr = ft_split(data->str, ' ');
		while(data->arr[i] != NULL)
		{
			data->col++;
			i++;
		}
		i = 0;
		ft_memfreeall((void *)data->arr);
	}
	while(data->buf != NULL)
	{
		data->row++;
		if (data->row == 1)
			data->str = ft_strdup(data->tmp2);
		else
			data->str = ft_strjoin(data->tmp2);
		ft_memfree(data->buf);
		data->buf = get_next_line(fd);
		data->tmp = ft_strtrim(data->buf, "\n");
		data->tmp = ft_strjoin("", data->tmp);
	}

	/*TEST*/
	printf("row : %zu\n", data->row);
	printf("col : %zu\n", data->col);
	/*END TEST*/

	matrix = (t_matrix *)ft_calloc(sizeof(t_matrix), (data->row * data->col) + 1);
	if (matrix == NULL)
		return (NULL);
	i = 0;
	while(--data->row)
	{
		ft_create_struct_from_point(data, matrix);
	}



	return (matrix);
}

int main(int argc, char **argv)
{
	t_matrix *matrix;
	t_parse	data;
	size_t	i;
	int fd;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	matrix = ft_get_data(fd, &data);

	/*TEST*/
	printf("------TEST------\n");
	i = 0;
	while (matrix[i] != NULL)
	{
		printf("Pixel %lu in the matrix\t X = %d\t Y = %d\t Z = %d\t Color = %s\n", i + 1, matrix[i]->x, matrix[i]->y, matrix[i]->z, matrix[i]->color);
		printf("_____________________________________________________");
		i++;
	}
	printf("------END---TEST------\n");
	/*END TEST*/

	close(fd);
	return (0);
}
