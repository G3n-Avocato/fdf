/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 12:56:51 by lamasson          #+#    #+#             */
/*   Updated: 2023/03/08 17:43:38 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>
int	main(void)
{
//	t_param	**tab;
	void	*mlx;
//	void	*mlx_win;

	mlx = mlx_init();
	mlx_new_window(mlx, 1920, 1080, "Hello");
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
