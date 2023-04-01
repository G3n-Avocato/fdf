/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:31:31 by lamasson          #+#    #+#             */
/*   Updated: 2023/04/01 22:30:51 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	*ft_parse_hexa_four(char *hexa, int	*rgb)
{
	char	*cut;
	int		j;

	j = 2;
	cut = ft_substr(hexa, 2, 2);
	rgb[j] = ft_atoi_base(cut, 16);
	free(cut);
	while (j-- > 0)
		rgb[j] = 0;
	return (rgb);
}

static int	*ft_parse_hexa_six(char *hexa, int *rgb)
{
	char	*cut;
	int		j;
	int		i;

	i = 2;
	j = 1;
	while (j <= 2)
	{
		cut = ft_substr(hexa, i, 2);
		rgb[j] = ft_atoi_base(cut, 16);
		free(cut);
		i += 2;
		j++;
	}
	rgb[0] = 0;
	return (rgb);
}

static int	*ft_parse_hexa(char *hexa, int *rgb)
{
	int		i;
	int		j;
	char	*cut;

	j = 0;
	i = 2;
	while (j != 3)
	{
		cut = ft_substr(hexa, i, 2);
		rgb[j] = ft_atoi_base(cut, 16);
		free(cut);
		i = i + 2;
		j++;
	}
	return (rgb);
}

static int	*ft_size_hexa(char *hexa)
{
	int	*rgb;
	int	size;

	size = ft_strlen(hexa);
	rgb = malloc(sizeof(int) * 3);
	if (rgb == NULL)
		exit (1);
	if (size == 4)
		rgb = ft_parse_hexa_four(hexa, rgb);
	else if (size == 6)
		rgb = ft_parse_hexa_six(hexa, rgb);
	else
		rgb = ft_parse_hexa(hexa, rgb);
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
			buf_rgb = ft_size_hexa(tab_v[i][1]);
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
