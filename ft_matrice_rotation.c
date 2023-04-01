/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrice_rotation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:22:31 by lamasson          #+#    #+#             */
/*   Updated: 2023/04/01 15:36:26 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	matrice_z(t_point *point, float theta)
{
	float	tmp_x;

	tmp_x = point->x;
	point->x = cos(theta) * point->x - sin(theta) * point->y;
	point->y = sin(theta) * tmp_x + cos(theta) * point->y;
}

void	matrice_y(t_point *point, float theta)
{
	float	tmp_x;

	tmp_x = point->x;
	point->x = cos(theta) * point->x + sin(theta) * point->z;
	point->z = -sin(theta) * tmp_x + cos(theta) * point->z;
}

void	matrice_x(t_point *point, float theta)
{
	float	tmp_y;

	tmp_y = point->y;
	point->y = cos(theta) * point->y - sin(theta) * point->z;
	point->z = sin(theta) * tmp_y + cos(theta) * point->z;
}

void	ft_itermap(t_point **point, t_size size, void (*f)(t_point *, float), \
		float theta)
{
	int	i;
	int	j;

	i = 0;
	while (i < size.y)
	{
		j = 0;
		while (j < size.x)
		{
			f(&point[i][j], theta);
			j++;
		}
		i++;
	}
}
