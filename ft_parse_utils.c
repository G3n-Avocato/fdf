/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:55:31 by lamasson          #+#    #+#             */
/*   Updated: 2023/03/06 19:30:57 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_info_pos	**ft_init_struct(int x, int y)
{
	t_info_pos	**tab;
	int	i;

	i = 0;
	tab = malloc(sizeof(t_info_pos *) * y);
	while (i < y)
	{
		tab[i] = malloc(sizeof(t_info_pos) * x);
		i++;
	}
	return (tab);
}

int	ft_open_fd(char *fd)
{
	int	in;

	in = open(fd, O_RDONLY, 0644);
	if (in == -1)
	{
		perror(fd);
		exit (1);
	}
	return (in);
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
	close(in);
	return (y);
}
