/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 18:45:48 by ysonmez           #+#    #+#             */
/*   Updated: 2021/10/25 11:58:32 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

/*	Free all allocated var in the program	*/

void	free_data(t_fdf	*fdf)
{
	size_t	i;

	i = 0;
	if (fdf->matrix != NULL && fdf->isomatrix != NULL)
	{
		while (i < fdf->data.size)
		{
			free(&fdf->matrix[i]);
			free(&fdf->isomatrix[i]);
			i++;
		}
	}
	if (fdf->screen != NULL)
		free(fdf->screen);
	if (fdf != NULL)
		free(fdf);
	if (fdf->vars.win != NULL)
		mlx_destroy_window(fdf->vars.mlx, fdf->vars.win);
}

/*	Hexa to decimal converter + Base checker (upper or lowercase) */

static char	*check_base(char *str)
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

/*	Fill color property of the transformed matrix */

void	fill_colors(t_fdf *fdf)
{
	size_t		i;

	i = 0;
	while (i < fdf->data.size)
	{
		fdf->isomatrix[i].color = fdf->matrix[i].color;
		i++;
	}
}
