/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:25:38 by lamasson          #+#    #+#             */
/*   Updated: 2023/03/26 17:37:40 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_clean_image(t_vars *vars)
{
	int	i = 0;
	int	j = 0;

	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			ft_mlx_pixel_put(vars->data, j, i, 0x00000000);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
}

void	ft_free_struct(t_point **point)
{
	int	i;

	i = 0;
	while (point[i] != NULL)
	{
		free(point[i]);
		i++;
	}
	free(point);
}

int	ft_cross_mlx(t_vars *vars)
{
	mlx_loop_end(vars->mlx);
	ft_free_struct(vars->point);
	return (0);
}

int	ft_hook(int keycode, t_vars *vars)
{

	if (keycode == 65307)
	{
		mlx_loop_end(vars->mlx);
		ft_free_struct(vars->point);
	}
	if (keycode == 65361)
		ft_itermap(vars->point, vars->size, matrice_y, 5 * PI / 180);
	if (keycode == 65363)
		ft_itermap(vars->point, vars->size, matrice_y, -5 * PI / 180);	
	if (keycode == 65362)
		ft_itermap(vars->point, vars->size, matrice_x, 5 * PI / 180);
	if (keycode == 65364)
		ft_itermap(vars->point, vars->size, matrice_x, -5 * PI / 180);
	if (keycode == 61)
		vars->zm += 1;
	if (keycode == 45 && vars->zm > 1)
		vars->zm -= 1;
	if (keycode != 65307)
	{
		ft_clean_image(vars);
		draw_point(vars);
	}
	return (0);
}
