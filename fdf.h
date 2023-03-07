/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:50:16 by lamasson          #+#    #+#             */
/*   Updated: 2023/03/07 18:34:03 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
//# include "mlx.h"
# include <fcntl.h> //open
# include <stdio.h> //perror
# include <stdlib.h> //exit

typedef struct s_param{
	int	alt;
	char	rgb[3];
}t_param;



t_param	**ft_init_struct(int x, int y);
int	ft_open_fd(char *fd);
int	ft_len_x(int in);
int	ft_len_y(int in);
void	ft_free_n_tab(char ***tab, int i);

int	ft_atoi_base(const char *str, int str_base);

t_param	**ft_rec_fd(char *fd);
t_param	**ft_parse_color(char ***tab_v, t_param **tab, int pos, int x);


#endif
