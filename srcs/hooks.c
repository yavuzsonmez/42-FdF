/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:17:58 by ysonmez           #+#    #+#             */
/*   Updated: 2021/09/15 15:57:31 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

/* Event hook to close the window with ESCAPE */

int	close_window(int keycode, t_vars *vars)
{
	if (keycode == ESCAPE)
	{
		mlx_destroy_image(vars->mlx, vars->win);
		mlx_destroy_window(vars->mlx, vars->win);
		ft_memfree(vars->win);
		ft_memfree(vars->mlx);
		exit(EXIT_SUCCESS);
	}
	else
		return (-1);
	return (0);
}