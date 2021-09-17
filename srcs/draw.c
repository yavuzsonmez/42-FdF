/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:10:50 by ysonmez           #+#    #+#             */
/*   Updated: 2021/09/17 18:43:17 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

/* Calculate the memory offset using the line length */

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/* Draw line between points with Bresenham algorithm */

static void	bresenham(t_screen *screen, t_data *img, t_bresenham *p)
{
	while (1)
	{
		if (p->x0 >= 0 && p->y0 >= 0)
		{
			if (p->x0 < screen->width && p->y0 < screen->height)
				my_mlx_pixel_put(img, p->x0, p->y0, p->color);
		}
		if (p->x0 == p->x1 && p->y0 == p->y1)
			break ;
		p->e2 = 2 * p->err;
		if (p->e2 >= p->dy)
		{
			p->err += p->dy;
			p->x0 += p->sx;
		}
		if (p->e2 <= p->dx)
		{
			p->err += p->dx;
			p->y0 += p->sy;
		}
	}
}

static void	link_x(t_matrix *isomatrix, t_bresenham *p)
{
	p->z = isomatrix[0].z;
	p->x0 = isomatrix[0].x;
	p->x1 = isomatrix[1].x;
	p->y0 = isomatrix[0].y;
	p->y1 = isomatrix[1].y;
	p->color = isomatrix[0].color;
	p->dx = abs(p->x1 - p->x0);
	if (p->x0 < p->x1)
		p->sx = 1;
	else
		p->sx = -1;
	p->dy = -abs(p->y1 - p->y0);
	if (p->y0 < p->y1)
		p->sy = 1;
	else
		p->sy = -1;
	p->err = p->dx + p->dy;
}

static void	link_y(t_matrix *isomatrix, t_bresenham *p, size_t ncol)
{
	p->z = isomatrix[0].z;
	p->x0 = isomatrix[0].x;
	p->x1 = isomatrix[ncol].x;
	p->y0 = isomatrix[0].y;
	p->y1 = isomatrix[ncol].y;
	p->color = isomatrix[0].color;
	p->dx = abs(p->x1 - p->x0);
	if (p->x0 < p->x1)
		p->sx = 1;
	else
		p->sx = -1;
	p->dy = -abs(p->y1 - p->y0);
	if (p->y0 < p->y1)
		p->sy = 1;
	else
		p->sy = -1;
	p->err = p->dx + p->dy;
}

/* Drawing line by using he Bresenham's algorithm */

void	draw(t_fdf	*fdf)
{
	size_t		i;
	t_bresenham	p;

	i = 0;
	while (i < fdf->data.size - 1)
	{
		if (fdf->matrix[i].y != fdf->matrix[i + 1].y)
			i++;
		link_x(fdf->isomatrix + i, &p);
		bresenham (&fdf->screen, &fdf->img, &p);
		i++;
	}
	i = 0;
	while (i < (fdf->data.size - fdf->data.col))
	{
		link_y(fdf->isomatrix + i, &p, fdf->data.col);
		bresenham (&fdf->screen, &fdf->img, &p);
		i++;
	}
}
