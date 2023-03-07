/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:35:32 by lamasson          #+#    #+#             */
/*   Updated: 2023/03/07 18:13:59 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_param	**ft_parse_struct(char ***tab_v, t_param **tab, int pos, int x)
{
	int	i;

	i = 0;
	while (i != x)
	{
		tab[pos][i].alt = ft_atoi(tab_v[i][0]);
		i++;
	}
	ft_free_n_tab(tab_v, i - 1);
	return (tab);
}


static t_param	**ft_parse_line(char *line, t_param **tab, int pos, int x)
{
	char	**tab_c;
	char	***tab_v = NULL;
	int	i;
	
	i = 0;
	tab_c = ft_split(line, ' ');
	if (tab_c == NULL)
		exit (1);
	tab_v = calloc(x + 1, sizeof(char **));
	if (tab_v == NULL)
	{
		ft_free_tab(tab_c);
		exit (1);
	}
	while (i != x)
	{
		tab_v[i] = ft_split(tab_c[i], ',');
		if (tab_v[i] == NULL)
		{
			ft_free_tab(tab_c);
			ft_free_n_tab(tab_v, i);
			exit (1);
		}
		i++;
	}
	ft_free_tab(tab_c);
	tab = ft_parse_color(tab_v, tab, pos, x);
	tab = ft_parse_struct(tab_v, tab, pos, x);
	return (tab);
}

static t_param	**ft_rec_map(int x, int y, int in)
{
	t_param	**tab;
	char	*line;
	int	pos;

	pos = 0;
	tab = ft_init_struct(x, y);
	line = get_next_line(in);
	while (line != NULL)
	{
		ft_parse_line(line, tab, pos, x); ///
		free(line);
		line = get_next_line(in);
		pos++;
	}
	free(line);
	return (tab);
}

t_param	**ft_rec_fd(char *fd)
{
	int	x;
	int	y;
	int	in;
	t_param	**tab;

	in = ft_open_fd(fd);
	x = ft_len_x(in);
	in = ft_open_fd(fd);
	y = ft_len_y(in);
	in = ft_open_fd(fd);
	tab = ft_rec_map(x, y, in);
	return (tab);
}
