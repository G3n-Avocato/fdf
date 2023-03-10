/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 12:56:51 by lamasson          #+#    #+#             */
/*   Updated: 2023/03/10 18:07:25 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}t_data;

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*((unsigned int*)dst) = color;
}


int	main(void)
{
					//	t_param	**tab;
	void	*mlx;
	void	*mlx_win;
	t_data	data;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello");
	data.img = mlx_new_image(mlx, 1920, 1080);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	ft_mlx_pixel_put(&data, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, data.img, 0, 0);
	mlx_loop(mlx);

}







/*
 * print tableau de structure 
{
	int	i, j, in, x;
	i = 0;
	in = ft_open_fd(argv[1]);
	x = ft_len_x(in);
	while (tab[i] != NULL)
	{
		j = 0;
		while (j != x)
		{
			printf("%d ", tab[i][j].alt);
		//	printf("rgb = %d, %d, %d ||", tab[i][j].rgb[0], tab[i][j].rgb[1], tab[i][j].rgb[2]);
			j++;
		}
		printf("\n");
		i++;
	}
}
*/
