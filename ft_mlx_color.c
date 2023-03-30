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

void	ft_get_color(t_vars *vars, t_pixel pixel)
{
	t_data	buffer;
	t_point	**col;
	int	pix;

	pix = (pixel->pos_y * line_length) + (pixel->pos_x * 4);
	col = vars->point;
	buffer = vars->data;
	if (buffer->endian == 1)
	{
		buffer->addr[pix + 0] = FF;
		buffer->addr[pix + 1] = col->rgb[0];
		buffer->addr[pix + 2] = col->rgb[1];
		buffer->addr[pix + 3] = col->rgb[2];
	}
	else if (buffer->endian == 0)
	{
		buffer->addr[pix + 0] = col->rgb[2];
		buffer->addr[pix + 1] = col->rgb[1];
		buffer->addr[pix + 2] = col->rgb[0];
		buffer->addr[pix + 3] = FF;
	}




}
