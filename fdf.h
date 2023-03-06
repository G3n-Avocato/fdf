/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:50:16 by lamasson          #+#    #+#             */
/*   Updated: 2023/03/06 18:15:19 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
//# include "mlx.h"
# include <fcntl.h> //open
# include <stdio.h> //perror
# include <stdlib.h> //exit

typedef struct s_info_pos{
	int	alt;
	char	rgb[3];
}t_info_pos;




int	**ft_init_tab(int x, int y);
int	ft_open_fd(char *fd);
int	ft_len_x(int in);
int	ft_len_y(int in);

#endif
