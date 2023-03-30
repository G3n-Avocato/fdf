/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:31:31 by lamasson          #+#    #+#             */
/*   Updated: 2023/03/30 15:45:08 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	*ft_parse_hexa(char *hexa)
{
	int		i;
	int		j;
	int		*rgb;
	char	*cut;

	j = 0;
	i = 2;
	rgb = malloc(sizeof(int) * 3);
	while (j != 3)
	{
		cut = ft_substr(hexa, i, 2);
		rgb[j] = ft_atoi_base(cut, "0123456789ABCDEF");
		free(cut);
		i = i + 2;
		j++;
	}
	return (rgb);
}

t_point	**ft_parse_color(char ***tab_v, t_point **tab, int pos, int x)
{
	int	i;
	int	*buf_rgb;

	i = 0;
	while (i != x)
	{
		if (tab_v[i][1] != NULL)
		{
			buf_rgb = ft_parse_hexa(tab_v[i][1]);
			tab[pos][i].rgb[0] = buf_rgb[0];
			tab[pos][i].rgb[1] = buf_rgb[1];
			tab[pos][i].rgb[2] = buf_rgb[2];
			free(buf_rgb);
		}
		else
		{
			tab[pos][i].rgb[0] = 55;
			tab[pos][i].rgb[1] = 55;
			tab[pos][i].rgb[2] = 55;
		}
		i++;
	}
	return (tab);
}
