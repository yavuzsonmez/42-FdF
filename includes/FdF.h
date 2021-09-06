/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:56:05 by ysonmez           #+#    #+#             */
/*   Updated: 2021/09/06 10:22:25 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <math.h>

/* Buffer size for GNL & Keycode to close the window + the process */

# define BUFFER_SIZE 10000
# define ESCAPE 53

/* GNL : proto & required struct */

char	*get_next_line(int fd);

typedef struct s_gnl
{
	char	*buff;
	char	*newline;
	int		r;
	int		i;
}	t_gnl;

/* Required structs for Minilibx */

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

/* Struct to store each points of the matrix and struct for the parsing step */

typedef struct	s_matrix {
	int				x;
	int				y;
	int				z;
	int				color;
}	t_matrix;

typedef struct s_parse
{
	char	*str;
	char	*buf;
	size_t	row;
	size_t	col;
	char	**arr;
	size_t	size;
}	t_parse;

int		ft_get_color(char *str);
int		ft_count_row_col(char *str, t_parse *data);
int		ft_store_data(char *str, t_parse *data, t_matrix *matrix);


#endif