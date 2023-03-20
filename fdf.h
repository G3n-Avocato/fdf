/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:50:16 by lamasson          #+#    #+#             */
/*   Updated: 2023/03/20 19:52:08 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "mlx_linux/mlx.h"
# include <fcntl.h> //open
# include <stdio.h> //perror
# include <stdlib.h> //exit
# include <math.h> //lib math

# define WIN_WIDTH 1920
# define WIN_HEIGHT 995
# define MLX_ERROR 1
# define PI 3.14159265359

typedef struct s_size{
	int	x;
	int	y;
}t_size;

typedef struct s_point{
	float			x;
	float			y;
	float			z;
	unsigned char	rgb[3];
}t_point;

//struct pos et tmp

typedef struct s_data{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_data;

typedef struct s_vars{
	void	*mlx;
	void	*win;
	t_data	data;
	t_point	**point;
	t_size	size;
}t_vars;

t_point	**ft_init_struct(t_size size);
int		ft_open_fd(char *fd);
int		ft_len_x(int in);
int		ft_len_y(int in);
void	ft_free_n_tab(char ***tab, int i);

t_point	**ft_rec_fd(char *fd, t_size *size);
char	***ft_map_storage(char *line, char ***tab_v, int x);
t_point	**ft_parse_struct(char ***tab_v, t_point **tab, int pos, t_size size);
t_point	**ft_parse_color(char ***tab_v, t_point **tab, int pos, int x);
int		ft_atoi_base(const char *str, int str_base);

int		ft_mlx_init(t_point **point, t_size size);





#endif
