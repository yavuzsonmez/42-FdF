/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:56:05 by ysonmez           #+#    #+#             */
/*   Updated: 2021/09/17 18:38:20 by ysonmez          ###   ########.fr       */
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

/* Buffer size for GNL */

# define BUFFER_SIZE 100000

/* Events Hook macOS keycodes */

# define ESCAPE	53
# define UP		126
# define DOWN	125
# define LEFT	123
# define RIGHT	124

/* GNL */

char	*get_next_line(int fd);

typedef struct s_gnl
{
	char		*buff;
	char		*newline;
	int			r;
	int			i;
}	t_gnl;

/* Required structs for Minilibx */

typedef struct	s_vars {
	void		*mlx;
	void		*win;
}	t_vars;

typedef struct	s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_data;

/* Struct for the parsing step */

typedef struct s_parse
{
	char		*str;
	char		*buf;
	size_t		row;
	size_t		col;
	char		**arr;
	size_t		size;
}	t_parse;

/* Struct to store data related to matrix and isometric matrix */

typedef struct	s_matrix {
	int			x;
	int			y;
	int			z;
	int			color;
}	t_matrix;

/* Data related to the window and display */

typedef struct s_screen {
	int			height;
	int			width;
	int			scale;
}	t_screen;

/* Data to provide to Bresenham algorithm in order to link 2 points (putpixel) */

typedef struct s_bresenham {
	int			z;
	int			x0;
	int			x1;
	int			y0;
	int			y1;
	int			color;
	int			sx;
	int			sy;
	int			dx;
	int			dy;
	int			err;
	int			e2;
}	t_bresenham;

typedef	struct s_fdf {
	t_vars		vars;
	t_data		img;
	t_parse		data;
	t_screen	screen;
	t_matrix	*matrix;
	t_matrix	*isomatrix;
	} t_fdf;

/* Convert and store data (from file matrix to array of struct) */

int		count_row_col(char *str, t_fdf *fdf);
int		store_data(char *str, t_fdf *fdf);

/* Calculations in order to apply isometric projectionm, scale the view, align in the middle */

int	to_isometric(t_fdf	*fdf);

/* Link points of the matrix with Bresenham algorithm */

void		draw(t_fdf	*fdf);

/* Event hooks */

int			close_window(int keycode, t_vars *vars);


/* Initialize the data struct and free it */

t_fdf		*init_data_struct(void);
void		free_data_struct(t_fdf	*fdf);

#endif
