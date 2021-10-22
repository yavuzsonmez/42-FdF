/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 11:02:47 by ysonmez           #+#    #+#             */
/*   Updated: 2021/10/22 11:32:58 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

void	fill_colors(t_fdf *fdf)
{
	size_t		i;

	i = 0;
	while (i < fdf->data.size)
	{
		if (fdf->matrix[i].z < 0)
			fdf->isomatrix[i].color = 30975;
		else if (fdf->matrix[i].z > 0)
			fdf->isomatrix[i].color = 16711775;
		else
			fdf->isomatrix[i].color = fdf->matrix[i].color;
		i++;
	}
}
