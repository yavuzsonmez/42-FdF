/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 13:32:38 by ysonmez           #+#    #+#             */
/*   Updated: 2021/10/21 15:22:03 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

static char	*new_line(char **arr, t_gnl *gnl, int fd)
{
	if (gnl->i >= 0)
	{
		gnl->newline = ft_substr(arr[fd], 0, gnl->i + 1);
		gnl->buff = ft_strdup(arr[fd] + gnl->i + 1);
		free(arr[fd]);
		arr[fd] = ft_strdup(gnl->buff);
		free(gnl->buff);
		if (arr[fd][0] == '\0')
		{
			free(arr[fd]);
			arr[fd] = NULL;
		}
	}
	else
	{
		gnl->newline = ft_strdup(arr[fd]);
		free(arr[fd]);
		arr[fd] = NULL;
	}
	return (gnl->newline);
}

static int	fd_firstcall(char **arr, t_gnl *gnl, int fd)
{
	gnl->r = read(fd, gnl->buff, BUFFER_SIZE);
	if (gnl->r == -1 || gnl->r == 0)
	{
		free(gnl->buff);
		return (0);
	}
	gnl->buff[gnl->r] = '\0';
	arr[fd] = ft_strdup(gnl->buff);
	return (1);
}

static int	fd_nextcall(char **arr, t_gnl *gnl, int fd)
{
	gnl->r = read(fd, gnl->buff, BUFFER_SIZE);
	if (gnl->r == -1 || gnl->r == 0)
	{
		free(gnl->buff);
		return (0);
	}
	gnl->buff[gnl->r] = '\0';
	gnl->newline = ft_strjoin(arr[fd], gnl->buff);
	free(arr[fd]);
	arr[fd] = ft_strdup(gnl->newline);
	free(gnl->newline);
	return (1);
}

static int	reader(char **arr, t_gnl *gnl, int fd)
{
	gnl->buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (gnl->buff == NULL)
		return (0);
	if (arr[fd] == NULL)
	{
		if (!fd_firstcall(arr, gnl, fd))
			return (0);
	}
	else
	{
		if (!fd_nextcall(arr, gnl, fd))
			return (0);
	}
	free(gnl->buff);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*arr[4096];
	t_gnl		gnl;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	gnl.r = BUFFER_SIZE;
	if (arr[fd] == NULL)
	{
		if (!reader(arr, &gnl, fd))
			return (NULL);
	}
	gnl.i = ft_strchr_pos(arr[fd], '\n');
	if (gnl.i >= 0 || gnl.r < BUFFER_SIZE)
		return (new_line(arr, &gnl, fd));
	while (gnl.r > 0)
	{
		reader(arr, &gnl, fd);
		gnl.i = ft_strchr_pos(arr[fd], '\n');
		if (gnl.i >= 0 || gnl.r == 0)
			return (new_line(arr, &gnl, fd));
	}
	return (NULL);
}
