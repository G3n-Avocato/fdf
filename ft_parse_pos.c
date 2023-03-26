/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:51:28 by lamasson          #+#    #+#             */
/*   Updated: 2023/03/26 15:54:20 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float	ft_parse_pos_y(int y, int pos)
{
	float	cord;

	cord = (float) y / 2;
	cord *= -1;
	cord += pos;
	return (cord);
}

static float	ft_parse_pos_x(int x)
{
	float	cord;

	cord = (float) x / 2;
	cord *= -1;
	return (cord);
}

t_point	**ft_parse_struct(char ***tab_v, t_point **tab, int pos, t_size size)
{
	int		i;
	float	x_c;
	float	y_c;

	i = 0;
	x_c = ft_parse_pos_x(size.x);
	y_c = ft_parse_pos_y(size.y, pos);
	while (i != size.x)
	{
		tab[pos][i].x = x_c;
		tab[pos][i].y = y_c;
		tab[pos][i].z = ft_atoi(tab_v[i][0]) / 4.0;
		i++;
		x_c = x_c + 1;
	}
	ft_free_n_tab(tab_v, i - 1);
	return (tab);
}

char	***ft_map_storage(char *line, char ***tab_v, int x)
{
	char	**tab_c;
	int		i;

	i = 0;
	tab_c = ft_split(line, ' ');
	if (tab_c == NULL)
	{
		ft_free_n_tab(tab_v, x);
		return (NULL);
	}
	while (i != x)
	{
		tab_v[i] = ft_split(tab_c[i], ',');
		if (tab_v[i] == NULL && tab_c[i] == NULL)
		{
			ft_free_tab(tab_c);
			ft_free_n_tab(tab_v, i - 1);
			return (NULL);
		}
		i++;
	}
	ft_free_tab(tab_c);
	return (tab_v);
}
