#include "fdf.h"

int	*ft_put_tab(int **tab, char *str, int x, int y)
{
	int	i;

	i = 0;
	if (ft_isdigit
	
int	*ft_init_tab(int x, int y)
{
	int	**tab;
	int	i;

	i = 0;
	tab = malloc(sizeof(int) * y);
	while (i != y)
	{
		tab[i] = malloc(sizeof(int *) * x)
		i++;
	}
	return (tab);
}

//verif y taille ok (test)
int	get_y(char *str)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			i++;
			y++;
		}
		else
			i++;
	}
	y++;
	return (y);
}

//verif x taille ok (test)
//creer ftc check tt les tailles de x (parse)
int	get_x(char *str)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (str[i] != '\n')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			x++;
			while (ft_isalnum(str[i]) == 1 || str[i] == ',')
				i++;
		}
		else
			i++;
	}
	return (x);
}

