/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 18:45:48 by ysonmez           #+#    #+#             */
/*   Updated: 2021/09/17 18:55:07 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

t_fdf	*init_data_struct(void)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)ft_calloc(sizeof(t_fdf), 1);
	if (fdf == NULL)
	{
		ft_putendl_fd("Error", 1);
		return (NULL);
	}
	return (fdf);
}

/* free everything malloc in the struct if something exist and is malloc and free the whole data struct at the end
*  not finished
*/

void	free_data_struct(t_fdf	*fdf)
{
	size_t	i;

	i = 0;
	if (fdf->matrix != NULL)
		ft_memfreeall((void **)&fdf->matrix);
	if (fdf->isomatrix != NULL)
		ft_memfreeall((void **)&fdf->isomatrix);
	ft_memfree(fdf);
}
