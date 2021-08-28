/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 11:44:37 by ysonmez           #+#    #+#             */
/*   Updated: 2021/08/28 12:25:41 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

typedef struct s_parse
{
	char	*str;
	char	*tmp;
	char	*tmp2;
	size_t	i;
	int		fd;
	char	**arr;
}	t_parse;


t_matrix *ft_get_data(char **argv)
{
	t_parse		parse;
	t_matrix	*matrix;

	parse.fd = open(argv[1], O_RDONLY);
	parse.i = 0;
	parse.tmp = get_next_line(fd);
	parse.str = ft_strdup("");
	parse.tmp2 = NULL;
	while (tmp != NULL)
	{
		++i;
		parse.tmp2 = ft_strjoin(parse.tmp, parse.str);

	}



	parse.arr = ft_split(argv, ' ');
	matrix = ft_matrix(arr);

	close(fd);
	return (matrix);
}

t_matrix *ft_matrix(char **arr)
{
	size_t i;

	i = 0;
	while()

}


int main(int argc, char **argv)
{
	t_matrix *list;
	t_matrix *tmp;
	size_t	size;
	size_t	i;

	(void)argc;
	list = ft_get_data(argv[1]);
	/* TEST, PRINT CREATED LIST*/
	printf("TEST\n");
	i = 0;
	size = ft_lstsize(list);
	tmp = list;
	printf("There are %zu in the list\n", size);
	while (i < size)
	{
		printf("Element %lu in the list\t X = %d\t Y = %d\t Z = %d\n", i + 1, tmp.x, tmp.y, tmp.z);
		printf("_____________________________________________________");
		tmp = tmp->next;
		i++;
	}
	/* END PRINT TEST */


	return 0;
}