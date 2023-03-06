/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 23:20:06 by lamasson          #+#    #+#             */
/*   Updated: 2023/03/06 18:55:51 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_base(char c, int str_base)
{
	int	i;
	char *base1 = "0123456789abcdef";
	char *base2 = "0123456789ABCDEF";
	
	i = 0;
	while (i < str_base)
	{
		if (c == base1[i] || c == base2[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi(const char *str, int str_base)
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
		nb *= str_base;
		nb += check_base(*str, str_base);
		str++;
	}
	return (nb * neg);
}
