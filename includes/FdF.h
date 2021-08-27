/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:56:05 by ysonmez           #+#    #+#             */
/*   Updated: 2021/08/27 16:54:42 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

# define BUFFER_SIZE 100

char	*get_next_line(int fd);

typedef struct s_data
{
	char	*buff;
	char	*newline;
	int		r;
	int		i;
}	t_data;

typedef struct	s_mlx {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx;

#endif