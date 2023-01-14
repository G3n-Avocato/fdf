/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:46:12 by lamasson          #+#    #+#             */
/*   Updated: 2023/01/08 18:11:13 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
int	ft_parse_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= '0' && str[i] <= '9') || (str[i] != '-'))
		{
			ft_putendl_fd("Error\n", 2);
			exit (1);
		}
	}
}*/

char	*ft_read_fd(int fd)
{
	char	*str;
	char	*buf;

	buf = get_next_line(fd);
	while (buf)
	{
		str = get_next_line(fd);
		buf = ft_strjoin(buf, str);	
		if (str)
			free(str);

	}
	return (buf);	
}
void	ft_map(char *str)
{
	int	x;
	int	y;
	char	**tab;

	y = get_y(str);
	x = get_x(str);
	tab = ft_init_tab(x, y);
	tab = ft_put_tab(tab, str, x, y);
}

int	main(int argc, char **argv)
{
	int	fd;
	char	*str;
	int	i;
	
	i = 0;
	if (argc != 2)
		exit (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit (1);
	}
	str = ft_read_fd(fd);
}	ft_map(str);
