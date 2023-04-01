/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:44:00 by lamasson          #+#    #+#             */
/*   Updated: 2023/04/01 15:36:58 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	ft_get_color(t_vars *vars, int i, int j)
{
	unsigned int	color;

	color = 0;
	color += vars->point[i][j].rgb[0] * (1 << 16);
	color += vars->point[i][j].rgb[1] * (1 << 8);
	color += vars->point[i][j].rgb[2];
	return (color);
}
