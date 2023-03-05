/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 12:56:51 by lamasson          #+#    #+#             */
/*   Updated: 2023/03/05 20:42:19 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
char	*ft_parse(char *line)
{
	char	**tab;
	int	**
	int	i;

	tab = ft_split(line, ' ');
	if (tab == NULL)
		return (1);
*/

int	ft_open_fd(char	*fd)
{
	int	in;

	in = open(fd, O_RDONLY, 0644);
	if (in == -1)
	{
		perror(fd);
		exit (1);
	}
	return (in);
}

char	**ft_recup(char *fd)
{
	int	in;
	char	**tab;
	char	*line = NULL;
	int	i;
	int	x;

	i = 0;
	in = ft_open_fd(fd);

	line = get_next_line(in);
	while (1)
	{
		x = ft_strlen(line);
		tab[i] = malloc(sizeof(char) * (x + 1));
		tab[i] = line;
		free(line);
		line = get_next_line(in);
		i++;
	}
	free(line);
	return (tab);
}

int	main(int argc, char **argv)
{
	char	**tab;
	int	i;

	i = 0;
	if (argc != 2)
		return (1);
	tab = ft_open_fd(argv[1]);
	while (1)
	{
		printf("%s\n", tab[i]);
		i++;
	}
}

