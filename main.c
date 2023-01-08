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
int	ft_tab_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9') 

int	ft_recov_tab(char *str)
{
	int	**tab;
	int	size

	while (str[i] != '\)
	{
		tab = malloc(sizeof(int) * 

	
}

int	ft_read_fd(int fd)
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
	ft_recov_tab(buf);
}

int	main(int argc, char **argv)
{
	int	fd;
	char	**str;
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
	ft_read_fd(fd);
}
