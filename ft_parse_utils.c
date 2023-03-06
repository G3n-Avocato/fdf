/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:55:31 by lamasson          #+#    #+#             */
/*   Updated: 2023/03/05 20:51:26 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**ft_init_tab(int x, int y)
{
	int	**tab;
	int	i;

	i = 0;
	tab = malloc(sizeof(int) * y);
	while (i != y)
	{
		tab[i] = malloc(sizeof(int *) * x);
		i++;
	}
	return (tab);
}

int	ft_len_x(int in)
{
	char	*line;
	int	i;
	int	x;

	i = 0;
	x = 0;
	line = get_next_line(in);
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (ft_isdigit(line[i]) == 1 || line[i] == '-')
			x++;
		while (line[i] != ' ' && line[i] != '\n')
			i++;
		while (line[i] == ' ' && line[i] != '\n')
			i++;
	}
	free(line);
	close(in);
	return (x);
}

int	ft_len_y(int in)
{
	char	*line;
	int	y;

	y = 0;
	line = get_next_line(in);
	while (line != NULL)
	{
		y++;
		free(line);
		line = get_next_line(in);
	}
	free(line);
	return (y);
}

#include<stdio.h>
int main(int argc, char **argv)
{
	(void) argc;
	int	in;
	int	x;
	int	y;

	in = open(argv[1], O_RDONLY, 0644);
	x = ft_len_x(in);
	close(in);
	in = open(argv[1], O_RDONLY, 0644);
	y = ft_len_y(in);
	printf("x = %d\ny = %d\n", x, y);

}	
