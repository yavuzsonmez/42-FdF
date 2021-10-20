/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overlay.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:13:29 by ysonmez           #+#    #+#             */
/*   Updated: 2021/10/20 16:45:11 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

void	print_zoom(t_fdf	*fdf)
{
	char	*scale;
	char	*alt;

	scale = ft_itoa(fdf->screen->scale);
	alt = ft_itoa(fdf->screen->alt);
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 10, -10, 16777215, "_____________________");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 20, 10, 16777215, "ZOOM: ");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 200, 10, 16711777, scale);
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 10, 20, 16777215, "_____________________");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 20, 40, 16777215, "Z height: ");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 200, 40, 16711777, alt);
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 10, 50, 16777215, "_____________________");

	free(scale);
	free(alt);
}

void	print_translate(t_fdf	*fdf)
{
	char	*tx;
	char	*ty;

	tx = ft_itoa(((WIDTH / 2) - ((fdf->data.col / 2) * fdf->screen->scale)) - fdf->screen->translate_x);
	ty = ft_itoa(((HEIGHT / 2) - ((fdf->data.row / 2) * fdf->screen->scale)) - fdf->screen->translate_y);
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 10, 150, 16777215, "_____________________");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 20, 170, 16777215, "X translation: ");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 200, 170, 16711777, tx);
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 10, 180, 16777215, "_____________________");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 20, 200, 16777215, "Y translation: ");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 200, 200, 16711777, ty);
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 10, 210, 16777215, "_____________________");
	free(tx);
	free(ty);
}

void	print_alpha(t_fdf	*fdf)
{
	char	*alpha;
	int		angle;

	angle = fdf->screen->alpha * (180/M_PI);
	alpha = ft_itoa(angle);
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 10, 310, 16777215, "_____________________");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 20, 330, 16777215, "ALPHA in degree: ");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 200, 330, 16711777, alpha);
	free(alpha);
}

void	print_beta(t_fdf	*fdf)
{
	char	*beta;
	int		angle;

	angle = fdf->screen->beta * (180 / M_PI);
	beta = ft_itoa(angle);
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 10, 340, 16777215, "_____________________");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 20, 360, 16777215, "BETA in degree: ");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 200, 360, 16711777, beta);
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 10, 370, 16777215, "_____________________");
	free(beta);
}

void	print_theta(t_fdf	*fdf)
{
	char	*theta;
	int		angle;

	angle = fdf->screen->theta * (180 / M_PI);
	theta = ft_itoa(angle);
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 20, 390, 16777215, "THETA in degree: ");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 200, 390, 16711777, theta);
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 10, 400, 16777215, "_____________________");
	free(theta);
}

void	overlay(t_fdf	*fdf)
{
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, (WIDTH / 2) - 200, 20, 16777215, "\'FdF\' Wireframe reading from ");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, (WIDTH / 2) + 100, 20, 16711777, fdf->screen->file);
	print_zoom(fdf);
	print_translate(fdf);
	print_alpha(fdf);
	print_beta(fdf);
	print_theta(fdf);

}