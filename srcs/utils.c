/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 18:45:48 by ysonmez           #+#    #+#             */
/*   Updated: 2021/09/21 14:49:26 by ysonmez          ###   ########.fr       */
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

/* Hexa to decimal converter + Base checker (upper or lowercase) */

char	*check_base(char *str)
{
	size_t	i;
	int		b;
	char	*base;

	i = 0;
	b = -1;
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else if (str[i] >= 'a' && str[i] <= 'z')
			b = 0;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			b = 1;
		if (b == 0 || b == 1)
			break ;
	}
	if (b == 0)
		base = ft_strdup("0123456789abcdef");
	else
		base = ft_strdup("0123456789ABCDEF");
	return (base);
}

int	from_hexa_to_dec(char *str, size_t i, int color)
{
	int		len;
	char	*base;

	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '0' && str[i + 1] == 'x')
		i += 2;
	len = ft_strlen(str + i);
	if (ft_strchr(str + i, '\n') != NULL)
		len--;
	base = check_base(str + i);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			break ;
		len--;
		color += ft_strchr_pos(base, str[i]) * pow(16, len);
		i++;
	}
	ft_memfree((void *)base);
	return (color);
}
