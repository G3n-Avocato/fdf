/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 12:56:51 by lamasson          #+#    #+#             */
/*   Updated: 2023/03/02 14:01:48 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_parse(char *line)
{
	char	**tab;

	tab = ft_split(line, ' ');



int	ft_open_fd(char *fd);
{
	int	in;
	char	*line;

	in = open(fd, O_RDONLY, 0644);
	if (in == -1)
	{
		perror(fd);
		exit (1);
	}
	while (1)
	{
		line = get_next_line(fd);
		ft_parse(line);




int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	ft_open_fd(argv[1]);
