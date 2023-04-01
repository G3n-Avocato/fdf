/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 23:20:06 by lamasson          #+#    #+#             */
/*   Updated: 2023/04/01 15:17:10 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	check_base(char c, char *str_base)
{
	int		i;

	i = 0;
	while (str_base[i])
	{
		if (c == str_base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *str_base)
{
	int	neg;
	int	nb;

	nb = 0;
	neg = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	while (check_base(*str, str_base) != -1)
	{
		nb *= ft_strlen(str_base);
		nb += check_base(*str, str_base);
		str++;
	}
	return (nb * neg);
}
