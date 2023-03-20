/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:55:31 by lamasson          #+#    #+#             */
/*   Updated: 2023/03/19 19:56:21 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	**ft_init_struct(t_size size)
{
	t_point	**tab;
	int		i;

	i = 0;
	tab = calloc(size.y + 1, sizeof(t_point *));
	while (i < size.y)
	{
		tab[i] = calloc(size.x + 1, sizeof(t_point));
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
	int		i;
	int		x;

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
	line = get_next_line(in);
	free(line);
	return (x);
}

int	ft_len_y(int in)
{
	char	*line;
	int		y;

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

void	ft_free_n_tab(char ***tab, int i)
{
	while (i != 0)
	{
		ft_free_tab(tab[i]);
		i--;
	}
	free(tab);
}
