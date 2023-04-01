/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:35:32 by lamasson          #+#    #+#             */
/*   Updated: 2023/04/01 20:42:35 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_parse_line(char *line, t_point **tab, int pos, t_size size)
{
	char	***tab_v;

	tab_v = ft_calloc(size.x + 1, sizeof(char **));
	if (tab_v == NULL)
	{
		ft_free_struct(tab);
		return (1);
	}
	tab_v = ft_map_storage(line, tab_v, size.x);
	if (tab_v == NULL)
	{
		ft_free_struct(tab);
		return (1);
	}
	tab = ft_parse_color(tab_v, tab, pos, size.x);
	tab = ft_parse_struct(tab_v, tab, pos, size);
	return (0);
}

static t_point	**ft_get_map(t_size size, int in)
{
	t_point	**tab;
	char	*line;
	int		check;
	int		pos;

	pos = 0;
	check = 0;
	tab = ft_init_struct(size);
	line = get_next_line(in);
	while (line != NULL && check == 0)
	{
		check = ft_parse_line(line, tab, pos, size);
		free(line);
		line = get_next_line(in);
		pos++;
	}
	while (line != NULL)
	{
		free(line);
		line = get_next_line(in);
		if (line == NULL)
			return (NULL);
	}
	return (tab);
}

t_point	**ft_rec_fd(char *fd, t_size *size)
{
	int		in;
	t_point	**tab;

	in = ft_open_fd(fd);
	size->x = ft_len_x(in);
	in = ft_open_fd(fd);
	size->y = ft_len_y(in);
	in = ft_open_fd(fd);
	tab = ft_get_map(*size, in);
	if (tab == NULL)
	{
		perror(fd);
		exit (1);
	}
	return (tab);
}
