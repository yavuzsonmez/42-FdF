/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 18:45:48 by ysonmez           #+#    #+#             */
/*   Updated: 2021/09/18 16:03:21 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"


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
