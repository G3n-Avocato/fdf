/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 12:56:51 by lamasson          #+#    #+#             */
/*   Updated: 2023/03/06 19:07:28 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_parse(char *line, t_info_pos **tab, int pos, int x)
{
	char	**tab_c;
	char	***tab_v;
	int	i;

	i = 0;
	tab_c = ft_split(line, ' ');
	if (tab_c == NULL)
		exit (1);
	while (i != x)
	{
		tab_v[i] = ft_split(tab_c[i], ',');
		if (tab_v[i] == NULL)
		{
			ft_free_tab(tab_c);
			// fct free tab_v, i
			exit (1);
		}
		i++;
	}


//ft_parse_couleur en 2 char en int et que je remet ds le char corrrespondant ff.r ff.g ff.b

	while (i != x)
	{
		tab[pos][i].alt = ft_atoi(tab_v[i][0]);
		if (tab_v[i][1] != NULL)
//			tab[pos][i].rgb[0] = 
//			tab[pos][i].rgb[1] = 
//			tab[pos][i].rgb[2] = 
//		else
//			tab[pos][i].rgb[0] = 55
//			tab[pos][i].rgb[1] = 55
//			tab[pos][i].rgb[2] = 55 
		i++;
	}
	ft_free_tab(tab_c);
}

int	**ft_recov_map(int x, int y, int in)
{
	t_info_pos	**tab;
	char	*line = NULL;
	int	pos;

	pos = 0;
	tab = ft_init_tab(x, y);
	line = get_next_line(in);
	while (line != NULL)
	{
		ft_parse(line, tab, pos, x);
		free(line);
		line = get_next_line(in);
		pos++;
	}
	free(line);
	return (tab);
}

#include <stdio.h>
int	main(int argc, char **argv)
{
	int	x;
	int	y;
	int	in;
	t_info_pos	**tab;

	if (argc != 2)
		return (1);
	in = ft_open_fd(argv[1]);
	x = ft_len_x(in);
	in = ft_open_fd(argv[1]);
	y = ft_len_y(in);
	in = ft_open_fd(argv[1]);
	tab = ft_recov_map(x, y, in);


}

