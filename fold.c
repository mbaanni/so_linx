/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fold.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaanni <mbaanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:43:17 by mbaanni           #+#    #+#             */
/*   Updated: 2023/03/06 11:49:44 by mbaanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	path_fn(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'L')
		return ;
	map[y][x] = 'L';
	path_fn(map, x + 1, y);
	path_fn(map, x - 1, y);
	path_fn(map, x, y - 1);
	path_fn(map, x, y + 1);
}

char	**duplicate(char **map)
{
	char	**dup;
	int		i;
	int		j;
	int		t;

	i = 0;
	j = 0;
	while (map[i])
		i++;
	while (map[0][j])
		j++;
	dup = f_calloc(sizeof(char *) * (i + 1));
	i = 0;
	while (map[i])
	{
		t = -1;
		dup[i] = f_calloc(j + 1);
		while (map[i][++t] != '\n')
			dup[i][t] = map[i][t];
		dup[i][t] = 0;
		i++;
	}
	dup[i] = 0;
	return (dup);
}

int	check_ex(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' || map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ex_fn(t_mdata *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (mlx->pam[i])
	{
		j = 0;
		while (mlx->pam[i][j])
		{
			if (mlx->pam[i][j] == 'E')
			{
				mlx->e[0] = i;
				mlx->e[1] = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	check_path(t_mdata *mlx)
{
	char	**dup;

	dup = duplicate(mlx->pam);
	path_fn(dup, mlx->data.p[1], mlx->data.p[0]);
	if (check_ex(dup))
	{
		free_it_2d(dup);
		write(1, "Invalide Path\n", 14);
		free_it_2d(mlx->pam);
		exit(1);
	}
	ex_fn(mlx);
	free_it_2d(dup);
}
