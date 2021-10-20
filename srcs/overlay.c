/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overlay.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:13:29 by ysonmez           #+#    #+#             */
/*   Updated: 2021/10/20 15:59:11 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

void	print_zoom(t_fdf	*fdf)
{
	char	*scale;

	scale = ft_itoa(fdf->screen->scale);
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 10, -10, 16777215, "_____________________");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, (WIDTH / 2) - 200, 20, 16777215, "\'FdF\' Wireframe reading from ");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, (WIDTH / 2) + 100, 20, 16711777, fdf->screen->file);
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 10, 10, 16777215, "ZOOM : ");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 90, 10, 16711777, scale);
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 120, 10, 16777215, "x");
	free(scale);
}

void	print_alpha(t_fdf	*fdf)
{
	char	*alpha;
	int		angle;

	angle = fdf->screen->alpha * (180/M_PI);
	alpha = ft_itoa(angle);
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 10, 20, 16777215, "_____________________");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 10, 40, 16777215, "ALPHA : ");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 90, 40, 16711777, alpha);
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 120, 40, 16777215, "degree");
	free(alpha);
}

void	print_beta(t_fdf	*fdf)
{
	char	*beta;
	int		angle;

	angle = fdf->screen->beta * (180/M_PI);
	beta = ft_itoa(angle);
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 10, 50, 16777215, "_____________________");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 10, 70, 16777215, "BETA : ");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 90, 70, 16711777, beta);
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 120, 70, 16777215, "degree");
	free(beta);
}

void	print_theta(t_fdf	*fdf)
{
	char	*theta;
	int		angle;

	angle = fdf->screen->theta * (180/M_PI);
	theta = ft_itoa(angle);
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 10, 80, 16777215, "_____________________");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 10, 100, 16777215, "THETA : ");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 90, 100, 16711777, theta);
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 120, 100, 16777215, "degree");
	free(theta);
}

void	print_translate(t_fdf	*fdf)
{
	char	*tx;
	char	*ty;

	tx = ft_itoa(((WIDTH / 2) - ((fdf->data.col / 2) * fdf->screen->scale)) - fdf->screen->translate_x);
	ty = ft_itoa(((HEIGHT / 2) - ((fdf->data.row / 2) * fdf->screen->scale)) - fdf->screen->translate_y);
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 10, 110, 16777215, "_____________________");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 10, 130, 16777215, "T_X : ");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 90, 130, 16711777, tx);
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 10, 150, 16777215, "T_Y : ");
	mlx_string_put(fdf->vars.mlx, fdf->vars.win, 90, 150, 16711777, ty);
	free(tx);
	free(ty);
}
void	overlay(t_fdf	*fdf)
{
	print_zoom(fdf);
	print_alpha(fdf);
	print_beta(fdf);
	print_theta(fdf);
	print_translate(fdf);
	//print_ty
	//print_z
}