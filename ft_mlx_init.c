/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:38:31 by lamasson          #+#    #+#             */
/*   Updated: 2023/03/21 18:32:19 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx_linux/mlx.h"
#include <math.h>
#include <stdio.h>
/*
static void	ft_mlx_pixel_put(t_data data, int x, int y, int color)
{
	char	*dst;

	dst = data.addr + (y * data.line_length + x * (data.bits_per_pixel / 8));
	*((unsigned int*)dst) = color;
}

static int	draw_line(int posx, int posy, int tmpx, int tmpy, t_data data)
{
	float	delx;
	float	dely;
	int		pixels;
	float	pixx;
	float	pixy;

	delx = tmpx - posx;
	dely = tmpy - posy;
	pixels = sqrt((delx * delx) + (dely * dely));
	delx /= pixels;
	dely /= pixels;
	pixx = posx;
	pixy = posy;
	while (pixels)
	{
		ft_mlx_pixel_put(data, posx, posy, 0xFFFFFFFF);
		posx += delx;
		posy += dely;
		--pixels;
	}
	return (0);
}

static void	draw_point(t_vars *vars)
{
	int	i;
	int	j;
	int	posx;
	int	posy;
	int	tmpx;
	int	tmpy;

	i = 0;
	while (i < size.y)
	{
		j = 0;
		while (j < size.x)
		{

			posx = (int)(point[i][j].x * 15.0) + WIN_WIDTH / 2; 
			posy = (int)(point[i][j].y * 15.0) + WIN_HEIGHT / 2;
			if (j + 1 < size.x)
			{
				tmpx = (int)(point[i][j + 1].x * 15.0) + WIN_WIDTH / 2; 
				tmpy = (int)(point[i][j + 1].y * 15.0) + WIN_HEIGHT / 2;
			}
			draw_line(posx, posy, tmpx, tmpy, data);
			if (i + 1 < size.y)
			{
				tmpx = (int)(point[i + 1][j].x * 15.0) + WIN_WIDTH / 2; 
				tmpy = (int)(point[i + 1][j].y * 15.0) + WIN_HEIGHT / 2;
			}
			draw_line(posx, posy, tmpx, tmpy, data);
			j++;
		}
		
		i++;
	}
}


void	ft_itermap(t_point **point, t_size size, void(*f)(t_point *, float), float theta)
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

void	matrice_z(t_point *point, float theta)
{
	float tmp_x;

	tmp_x = point->x;
	point->x = cos(theta) * point->x -sin(theta) * point->y;
	point->y = sin(theta) * tmp_x + cos(theta) * point->y;
}

void	matrice_y(t_point *point, float theta)
{
	float tmp_x;

	tmp_x = point->x;
	point->x = cos(theta) * point->x + sin(theta) * point->z;
	point->z = -sin(theta) * tmp_x + cos(theta) * point->z;
}

void	matrice_x(t_point *point, float theta)
{
	float	tmp_y;
	
	tmp_y = point->y;
	point->y = cos(theta) * point->y -sin(theta) * point->z;
	point->z = sin(theta) * tmp_y + cos(theta) * point->z;
}

int	ft_hook(int keycode, t_vars	*vars)
{
	(void) vars;
	if (keycode == 65307)
		mlx_loop_end(vars->mlx);
	if (keycode == 65361)
		ft_itermap(vars->point, vars->size, matrice_y, 45 * PI / 180);
	if (keycode == 65363)
		ft_itermap(vars->point, vars->size, matrice_y, -45 * PI / 180);	
	if (keycode == 65362)
		ft_itermap(vars->point, vars->size, matrice_x, 45 * PI / 180);
	if (keycode == 65364)
		ft_itermap(vars->point, vars->size, matrice_x, -45 * PI / 180);
	//printf("keycode %d\n", keycode);
	if (keycode != 65307)
	{
		draw_point(vars->data, vars->point, vars->size);
		mlx_clear_window(vars->mlx, vars->win);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
	}
	return (0);
}
*/
	
void	destroy_mlx(t_vars vars)
{
	mlx_destroy_image(vars.mlx, vars.data.img);
	mlx_destroy_window(vars.mlx, vars.win);
	mlx_destroy_display(vars.mlx);
}

int	ft_mlx_init(t_point **point, t_size size)
{
	t_vars	vars;

	vars.point = point;
	vars.size = size;
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (MLX_ERROR);
	vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "FDF");
	if (vars.win == NULL)
	{
		free(vars.win);
		return (MLX_ERROR);
	}
	vars.data.img = mlx_new_image(vars.mlx, WIN_WIDTH, WIN_HEIGHT);
	vars.data.addr = mlx_get_data_addr(vars.data.img, &vars.data.bits_per_pixel, &vars.data.line_length, &vars.data.endian);
	
	draw_point(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.data.img, 0, 0);

	mlx_hook(vars.win, 2, 1, ft_hook, &vars);

	mlx_loop(vars.mlx);
	destroy_mlx(vars);
	return (0);
}
