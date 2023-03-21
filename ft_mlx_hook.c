/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:25:38 by lamasson          #+#    #+#             */
/*   Updated: 2023/03/21 16:32:36 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_hook(int keycode, t_vars *vars)
{	
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
		//draw_point(vars);
		mlx_clear_window(vars->mlx, vars->win);
		draw_point(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
	}
	return (0);
}
