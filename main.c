/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 12:56:51 by lamasson          #+#    #+#             */
/*   Updated: 2023/04/01 17:27:37 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_point	**point;
	t_size	size;

	if (argc != 2)
	{
		write(1, "Wrong Input!\n", 13);
		exit (1);
	}
	point = ft_rec_fd(argv[1], &size);
	ft_mlx_init(point, size);
	return (0);
}
/*
//print tableau de structure 

int	main(int argc, char **argv)
{
	(void) argc;
	t_point	**tab;
	t_size size;
	int	i, j, in, x;

	i = 0;
	tab = ft_rec_fd(argv[1], &size);
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

} */
