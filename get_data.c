/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 11:44:37 by ysonmez           #+#    #+#             */
/*   Updated: 2021/08/30 19:44:29 by ysonmez          ###   ########.fr       */
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

static void ft_get_data(int fd, t_parse *data)
{
	size_t i;

	i = 0;
	data->buf = get_next_line(fd);
	data->str = ft_strtrim(data->buf, "\n");
	data->arr = ft_split(data->str, ' ');
	while(data->arr[i] != NULL)
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
	printf("row : %zu\n", data->row);
	printf("col : %zu\n", data->col);


	return ;
}

int main(int argc, char **argv)
{
	t_matrix *list;
	t_parse	data;
	//size_t	i;
	int fd;

	(void)argc;

	fd = open(argv[1], O_RDONLY);
	list = NULL;
	/*list = */ft_get_data(fd, &data);
/*

	printf("TEST\n");
	i = 0;
	while (list[i] != NULL)
	{
		printf("Pixel %lu in the matrix\t X = %d\t Y = %d\t Z = %d\n", i + 1, list[i]->x, list[i]->y, list[i]->z);
		printf("_____________________________________________________");
		i++;
	}

*/

	close(fd);
	return 0;
}

/*
t_matrix *ft_matrix(char **arr)
{
	size_t i;
	t_matrix *data;

	i = 0;
	while(arr[i] != NULL)
		i++
	data = (t_matrix *)malloc(sizeof(t_matrix) * (i + 1));
	if (data == NULL)
		return (NULL);
	i = 0;
	while((arr[i] != NULL)
	{
		data[i]->x =
		data[i]->y =
		data[i]->z = ft_atoi(arr[i]);
		data[i]->color =
	}

}
*/