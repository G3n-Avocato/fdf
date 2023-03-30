/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:44:00 by lamasson          #+#    #+#             */
/*   Updated: 2023/03/30 17:27:53 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_get_color(t_vars *vars, t_pixel pixel, int i, int j)
{
	int	pix;

	pix = (pixel.pos_y * vars->data.line_length) + (pixel.pos_x * 4);
	if (vars->data.endian == 1)
	{
		vars->data.addr[pix + 0] = 00;
		vars->data.addr[pix + 1] = vars->point[i][j].rgb[0];
		vars->data.addr[pix + 2] = vars->point[i][j].rgb[1];
		vars->data.addr[pix + 3] = vars->point[i][j].rgb[2];
	}
	else if (vars->data.endian == 0)
	{
		vars->data.addr[pix + 0] = (vars->point[i][j].rgb[2]);
		vars->data.addr[pix + 1] = (vars->point[i][j].rgb[1] << 8);
		vars->data.addr[pix + 2] = (vars->point[i][j].rgb[0] << 16);
		vars->data.addr[pix + 3] = 0 << 24;
	}
}

int		ft_int_color(t_vars *vars, int i, int j)
{
	int color;
	
	color = (vars->point[i][j].rgb[2] | vars->point[i][j].rgb[1] << 8 | vars->point[i][j].rgb[0] << 16 | 0 << 24);
	
	printf("color int = %d\n", color);
	return (color);
}
