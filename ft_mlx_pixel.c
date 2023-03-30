/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:56:49 by lamasson          #+#    #+#             */
/*   Updated: 2023/03/30 17:11:58 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mlx_pixel_put(t_data data, int x, int y, int color)
{
	char	*dst;

	if (WIN_WIDTH < x || y > WIN_HEIGHT || x < 0 || y < 0)
		return ;
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
		ft_mlx_pixel_put(vars->data, put_x, put_y, pixel->col);
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
		pixel->tmp_x = (int)(vars->point[i + 1][j].x * vars->zm) + WIN_WIDTH / 2;
		pixel->tmp_y = (int)(vars->point[i + 1][j].y * vars->zm) + WIN_HEIGHT / 2;
	}
	draw_line(pixel, vars);
}

static void	init_pixel_x(t_pixel *pixel, t_vars *vars, int i, int j)
{
	if (j + 1 < vars->size.x)
	{
		pixel->tmp_x = (int)(vars->point[i][j + 1].x * vars->zm) + WIN_WIDTH / 2;
		pixel->tmp_y = (int)(vars->point[i][j + 1].y * vars->zm) + WIN_HEIGHT / 2;
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
			ft_get_color(vars, pixel, i, j);
			pixel.col = ft_int_color(vars, i, j);
			pixel.pos_x = (int)(vars->point[i][j].x * vars->zm) + WIN_WIDTH / 2;
			pixel.pos_y = (int)(vars->point[i][j].y * vars->zm) + WIN_HEIGHT / 2;
			if (j < vars->size.x - 1)
				init_pixel_x(&pixel, vars, i, j);
			init_pixel_y(&pixel, vars, i, j);
			j++;
		}
		i++;
	}
}
