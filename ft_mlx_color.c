/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:44:00 by lamasson          #+#    #+#             */
/*   Updated: 2023/03/26 19:35:29 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_get_color(t_vars *vars, int i, int j)
{
	unsigned int color;

	color = (vars->point[i][j].rgb[2] << 16) + (vars->point[i][j].rgb[1] << 8) + (vars->point[i][j].rgb[0]);
	return (color);




}
