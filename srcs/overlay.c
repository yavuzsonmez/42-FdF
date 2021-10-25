/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overlay.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:13:29 by ysonmez           #+#    #+#             */
/*   Updated: 2021/10/25 11:17:22 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

/*	Printing Zoom / Scale of the graphic informations */

void	print_zoom(t_fdf	*fdf)
{
	char	*scale;
	char	*alt;

	scale = ft_itoa(fdf->screen->scale);
	alt = ft_itoa(fdf->screen->alt);
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 10, -10, 16777215, "_______");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 20, 10, 16777215, "ZOOM");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 150, 10, 16711777, scale);
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 10, 20, 16777215, "_______");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 20, 40, 16777215, "Z +");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 150, 40, 16711777, alt);
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 10, 50, 16777215, "_______");
	free(scale);
	free(alt);
}

/*	Printing X and Y Translation informations */

void	print_translate(t_fdf	*fdf)
{
	char	*tx;
	char	*ty;

	tx = ft_itoa(((WIDTH / 2) - ((fdf->data.col / 2) * fdf->screen->scale))
			- fdf->screen->translate_x);
	ty = ft_itoa(((HEIGHT / 2) - ((fdf->data.row / 2) * fdf->screen->scale))
			- fdf->screen->translate_y);
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 10, 150, 16777215, "_______");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 20, 170, 16777215, "X transl");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 150, 170, 16711777, tx);
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 10, 180, 16777215, "_______");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 20, 200, 16777215, "Y transl");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 150, 200, 16711777, ty);
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 10, 210, 16777215, "_______");
	free(tx);
	free(ty);
}

/*	Enjoying the norm (freeing strings from print_angles) */

static void	free_strings(char **str0, char **str1, char **str2)
{
	free(*str0);
	free(*str1);
	free(*str2);
}

/*	Printing Alpha, Beta, Theta values in degree
*		In order :
*					X axis rotation angle
*					Y axis rotation angle
*					Z axis rotation angle
*/

void	print_angles(t_fdf	*fdf)
{
	char	*alpha;
	char	*beta;
	char	*theta;
	int		angle;

	angle = fdf->screen->alpha * (180 / M_PI);
	alpha = ft_itoa(angle);
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 10, 280, 16777215, "_______");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 20, 300, 16777215, "Rot deg");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 10, 310, 16777215, "_______");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 20, 330, 16777215, "X axis");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 150, 330, 16711777, alpha);
	angle = fdf->screen->beta * (180 / M_PI);
	beta = ft_itoa(angle);
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 10, 340, 16777215, "_______");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 20, 360, 16777215, "Y axis");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 150, 360, 16711777, beta);
	angle = fdf->screen->theta * (180 / M_PI);
	theta = ft_itoa(angle);
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 10, 370, 16777215, "_______");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 20, 390, 16777215, "Z axis");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 150, 390, 16711777, theta);
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 10, 400, 16777215, "_______");
	free_strings(&alpha, &beta, &theta);
}

/*	Overlay main function
*	Printing basics informations and graphic informations
*/

void	overlay(t_fdf	*fdf)
{
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, (WIDTH / 2) - 200, 20,
		16777215, "\'FdF\' Wireframe reading from ");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, (WIDTH / 2) + 100, 20,
		16711777, fdf->screen->file);
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 1550, 850,
		1618992, "ZOOM with MOUSE WHEEL");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 1550, 880,
		16744704, "TRANSLATE with keypad arrows");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 1550, 910,
		16711935, "CHANGE Z with + and -");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 1550, 940,
		6318079, "ROTATE around X axis with A and D");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 1550, 970,
		16734464, "ROTATE around Y axis with S and W");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 1550, 1000,
		16776960, "ROTATE around Z axis with Q and E");
	print_zoom(fdf);
	print_translate(fdf);
	print_angles(fdf);
}
