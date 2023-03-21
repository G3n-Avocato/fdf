/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:56:49 by lamasson          #+#    #+#             */
/*   Updated: 2023/03/21 14:19:39 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_mlx_pixel_put(t_data data, int x, int y, int color)
{
	char	*dst;

	dst = data.addr + (y * data.line_length + x * (data.bits_per_pixel / 8));
	*((unsigned int *)dst) = color;
}

static int	draw_line(t_pixel *pixel, t_vars *vars)
{
	float	put_x;
	float	put_y;
	int		pix;

	pixel->del_x = pixel->tmp_x - pixel->pos_x;
	pixel->del_y = pixel->tmp_y - pixel->pos_y;
	pix = sqrt((pixel->del_x * pixel->del_x) + (pixel->del_y * pixel->del_y));
	pixel->del_x /= pix;
	pixel->del_y /= pix;
	put_x = pixel->pos_x;
	put_y = pixel->pos_y;
	while (pix)
	{
		ft_mlx_pixel_put(vars->data, put_x, put_y, 0xFFFFFFFF);
		put_x += pixel->del_x;
		put_y += pixel->del_y;
		--pix;
	}
	return (0);
}

static void	init_pixel_y(t_pixel *pixel, t_vars *vars, int i, int j)
{
	if (i + 1 < vars->size.y)
	{
		pixel->tmp_x = (int)(vars->point[i + 1][j].x * 15.0) + WIN_WIDTH / 2;
		pixel->tmp_y = (int)(vars->point[i + 1][j].y * 15.0) + WIN_HEIGHT / 2;
	}
	draw_line(pixel, vars);
}

static void	init_pixel_x(t_pixel *pixel, t_vars *vars, int i, int j)
{
	if (j + 1 < vars->size.x)
	{
		pixel->tmp_x = (int)(vars->point[i][j + 1].x * 15.0) + WIN_WIDTH / 2;
		pixel->tmp_y = (int)(vars->point[i][j + 1].y * 15.0) + WIN_HEIGHT / 2;
	}
	draw_line(pixel, vars);
}

void	draw_point(t_vars *vars)
{
	int		i;
	int		j;
	t_pixel	pixel;

	i = 0;
	while (i < vars->size.y)
	{
		j = 0;
		while (j < vars->size.x)
		{
			pixel.pos_x = (int)(vars->point[i][j].x * 15.0) + WIN_WIDTH / 2;
			pixel.pos_y = (int)(vars->point[i][j].y * 15.0) + WIN_HEIGHT / 2;
			init_pixel_x(&pixel, vars, i, j);
			init_pixel_y(&pixel, vars, i, j);
			j++;
		}
		i++;
	}
}
