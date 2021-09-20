/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:56:05 by ysonmez           #+#    #+#             */
/*   Updated: 2021/09/20 16:06:38 by ysonmez          ###   ########.fr       */
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

# define	WIDTH		1920
# define	HEIGHT		1080

/* Buffer size for GNL */

# define BUFFER_SIZE	100000

/* Events Hook macOS keycodes */

# define	MWU			4
# define	MWD			5
# define	ESCAPE		53
# define	PLUS		69
# define	MINUS		78
# define	POV1		82
# define	POV2		83
# define	LEFT		123
# define	RIGHT		124
# define	DOWN		125
# define	UP			126


# define	ISOMETRIC	0
# define	PARALLEL	1

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
	int			translate_x;
	int			translate_y;
	int			scale;
	int			projection;
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
void	scale_window(t_fdf *fdf);
int		count_row_col(char *str, t_fdf *fdf);
int	store_data(char *str, t_fdf *fdf, size_t i, size_t e);

/* Calculations in order to apply isometric projectionm, scale the view, align in the middle */

int	to_isometric(t_fdf	*fdf);
int	to_parallel(t_fdf	*fdf);

/* Link points of the matrix with Bresenham algorithm */
void		render(t_fdf *fdf, int projection);
void		draw(t_fdf	*fdf);

/* Event listeners (events.c)*/

int	change_view(int keycode, t_fdf *fdf);
int			close_window(t_fdf *fdf);
int			altitude(int keycode, t_fdf *fdf);
int	translate(int keycode, t_fdf *fdf);
int key_handler(int keycode, t_fdf *fdf);
int zoom(int button, int x, int y, t_fdf *fdf);
int	rotate(int keycode, t_fdf *fdf);

/* Initialize the data struct and free it (utils.c)*/


void		free_data_struct(t_fdf	*fdf);

#endif
