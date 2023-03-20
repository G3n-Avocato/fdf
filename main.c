/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 12:56:51 by lamasson          #+#    #+#             */
/*   Updated: 2023/03/20 16:21:12 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	(void) argc;
	t_point	**point;
	t_size	size;

	point = ft_rec_fd(argv[1], &size);
	ft_mlx_init(point, size);
	return 0;
}






/*
int	draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color)
{
	double deltaX = endX - beginX;
	double deltaY = endY - beginY;
	int	pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels;
	deltaY /= pixels;
	double pixelX = beginX;
	double pixelY = beginY;
	while (pixels)
	{
		mlx_pixel_put(mlx, win, pixelX, pixelY, color);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
	return (0);
}

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*((unsigned int*)dst) = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	data;

	mlx = mlx_init();
	if (mlx == NULL)
		return (MLX_ERROR);
	mlx_win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "FDF");
	if (mlx_win == NULL)
	{
		free(mlx_win);
		return (MLX_ERROR);
	}
	data.img = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
**	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
**	data.addr[]
	draw_line(mlx, mlx_win, WIN_WIDTH, WIN_HEIGHT, 0, 0, 0x555555);
	
//	ft_mlx_pixel_put(&data, 5, 5, 0x00FF0000);
//	mlx_put_image_to_window(mlx, mlx_win, data.img, 0, 0);
	mlx_loop(mlx);
}*/

/*
//print tableau de structure 

int	main(int argc, char **argv)
{
	(void) argc;
	t_point	**tab;
	int	i, j, in, x;

	i = 0;
	tab = ft_rec_fd(argv[1]);
	in = ft_open_fd(argv[1]);
	x = ft_len_x(in);
	close(in); 
	while (tab[i] != NULL)
	{
		j = 0;
		while (j != x)
		{
			printf("%d-%d ", i, j);
			printf("x__%f ", tab[i][j].x);
			printf("y__%f ", tab[i][j].y);
			printf("z__%f ", tab[i][j].z);
			printf("rgb = %d, %d, %d ||\n", tab[i][j].rgb[0], tab[i][j].rgb[1], tab[i][j].rgb[2]);
			j++;
		}
		printf("\n");
		i++;
	}
	///free init_struct ???

}*/ 
