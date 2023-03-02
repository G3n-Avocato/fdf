/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:55:31 by lamasson          #+#    #+#             */
/*   Updated: 2023/03/02 14:01:40 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**ft_init_tab(int x, int y);
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

int	**ft_fill_tab(int **tab)

int main(void)
{
	int	x = 10;
	int	y = 10;
	int	**tab;

	tab = ft_init_tab(x, y);
	tab = ft_fill_tab(tab);

}	
