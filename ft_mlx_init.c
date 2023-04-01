/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:38:31 by lamasson          #+#    #+#             */
/*   Updated: 2023/04/01 15:30:42 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	destroy_mlx(t_vars vars)
{
	mlx_destroy_image(vars.mlx, vars.data.img);
	mlx_destroy_window(vars.mlx, vars.win);
	mlx_destroy_display(vars.mlx);
}

static int	ft_mlx_set(t_vars vars)
{
	draw_point(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.data.img, 0, 0);
	mlx_hook(vars.win, 17, 0L, ft_cross_mlx, &vars);
	mlx_hook(vars.win, 2, 1, ft_hook, &vars);
	mlx_loop(vars.mlx);
	destroy_mlx(vars);
	free(vars.mlx);
	return (0);
}

int	ft_mlx_init(t_point **point, t_size size)
{
	t_vars	vars;

	vars.zm = 30.0;
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
	vars.data.addr = mlx_get_data_addr(vars.data.img, \
			&vars.data.bits_per_pixel, &vars.data.line_length, \
			&vars.data.endian);
	ft_mlx_set(vars);
	return (0);
}
