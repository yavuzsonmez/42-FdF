/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:56:05 by ysonmez           #+#    #+#             */
/*   Updated: 2021/10/19 16:35:12 by ysonmez          ###   ########.fr       */
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

/* Window Resolution */

# define	WIDTH				1920
# define	HEIGHT				1080

/* Events Hook macOS keycodes */

# define	A					0
# define	D					2
# define	S					1
# define	W					13
# define	Q					12
# define	E					14
# define	MOUSE_WHEEL_UP		4
# define	MOUSE_WHEEL_DOWN	5
# define	ESCAPE				53
# define	PLUS				69
# define	MINUS				78
# define	LEFT				123
# define	RIGHT				124
# define	DOWN				125
# define	UP					126


/* -------- GET_NEXT_LINE.C -------- */
/* Buffer, struct and proto for Get_Next_Line */

# define BUFFER_SIZE			100000

typedef struct s_gnl
{
	char		*buff;
	char		*newline;
	int			r;
	int			i;
}	t_gnl;

char	*get_next_line(int fd);

/* Required structs for Minilibx */

typedef struct s_vars {
	void		*mlx;
	void		*win;
}	t_vars;

typedef struct s_data {
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

typedef struct s_matrix {
	double			x;
	double			y;
	double			z;
	int			color;
}	t_matrix;

/* Data related to the window and display */

typedef struct s_screen {
	double		translate_x;
	double		translate_y;
	double		scale;
	int			set;
	double		alpha;
	double		beta;
	double		theta;
}	t_screen;

/* Data for Bresenham algorithm in order to link 2 points (line) */

typedef struct s_bresenham {
	int			z0;
	int			z1;
	int			x0;
	int			x1;
	int			y0;
	int			y1;
	int			color0;
	int			color1;
	int			sx;
	int			sy;
	int			dx;
	int			dy;
	int			err;
	int			e2;
}	t_bresenham;

typedef struct s_fdf {
	t_vars		vars;
	t_data		img;
	t_parse		data;
	t_screen	*screen;
	t_matrix	*matrix;
	t_matrix	*isomatrix;
}	t_fdf;


/* -------- GET_DATA.C -------- */
/* Convert and store data (from matrix to array of struct) */
int		count_row_col(char *str, t_fdf *fdf);
int		store_data(char *str, t_fdf *fdf, size_t i, size_t e);

/* -------- TRANSFORM_DATA.C -------- */
/* Formulas application for isometric projection */

int		to_isometric(t_fdf	*fdf);

/* -------- DRAW.C -------- */
/* Link points of the matrix with Bresenham algorithm */
void	render(t_fdf *fdf);
void	draw(t_fdf	*fdf);
void	translate(t_fdf *fdf);
void	scale(t_fdf *fdf);

/* -------- KEY_EVENTS.C -------- */
/* Keypress Events */

int		change_view(int keycode, t_fdf *fdf);
int		close_window(t_fdf *fdf);
int		altitude(int keycode, t_fdf *fdf);
int		move(int keycode, t_fdf *fdf);
int		key_handler(int keycode, t_fdf *fdf);

/* --------> MOUSE_EVENTS.C <-------- */
/* Mouse Events */
int		zoom(int button, int x, int y, t_fdf *fdf);
int		rotate(int keycode, t_fdf *fdf);
void	rotate_x(int keycode, t_fdf *fdf);
void	rotate_y(int keycode, t_fdf *fdf);
void	rotate_z(int keycode, t_fdf *fdf);


/* --------> UTILS.C <-------- */
/* Initialize the data struct and free it (utils.c)*/

void color_fade(t_fdf *fdf, size_t i);
void	free_data_struct(t_fdf	*fdf);
int		from_hexa_to_dec(char *str, size_t i, int color);
char	*check_base(char *str);

#endif
