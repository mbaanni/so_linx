/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_left_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaanni <mbaanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 08:55:04 by mbaanni           #+#    #+#             */
/*   Updated: 2023/03/02 19:55:12 by mbaanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_move(t_mdata *mlx)
{
	if (mlx->data.n_move)
	{
		free(mlx->data.n_move);
		mlx->data.n_move = 0;
	}
}

void	ft_n_to_s(unsigned int nbr, t_mdata *mlx)
{
	char	*num;
	int		i;
	int		j;

	j = nbr;
	i = 1;
	while (j / 10)
	{
		j /= 10;
		i++;
	}
	num = f_calloc(i + 1);
	if (!num)
		return ;
	num[i] = 0;
	i--;
	while (nbr / 10)
	{
		num[i] = (nbr % 10) + 48;
		nbr /= 10;
		i--;
	}
	num[i] = (nbr % 10) + 48;
	mlx->data.n_move = num;
}

void	ft_right(t_mdata *mlx, int *p)
{
	if (mlx->pam[p[0]][p[1] + 1] == 'E' && mlx->data.c == 0)
	{
		free_move(mlx);
		ft_end(mlx);
		write(1, "Win\n", 4);
		exit (0);
	}
	if (mlx->pam[p[0]][p[1] + 1] != '1')
	{
		free_move(mlx);
		p[1]++;
		if (mlx->pam[p[0]][p[1]] == 'C')
		{
			mlx->pam[p[0]][p[1]] = '0';
			mlx->data.c--;
		}
		ft_n_to_s(mlx->move, mlx);
		mlx->move++;
	}
}

void	ft_left(t_mdata *mlx, int *p)
{
	if (mlx->pam[p[0]][p[1] - 1] == 'E' && mlx->data.c == 0)
	{
		free_move(mlx);
		ft_end(mlx);
		write(1, "Win\n", 4);
		exit (0);
	}
	if (mlx->pam[p[0]][p[1] - 1] != '1')
	{
		free_move(mlx);
		p[1]--;
		if (mlx->pam[p[0]][p[1]] == 'C')
		{
			mlx->pam[p[0]][p[1]] = '0';
			mlx->data.c--;
		}
		ft_n_to_s(mlx->move, mlx);
		mlx->move++;
	}
}

void	right_left(t_mdata *mlx, int keycode, int *p)
{
	int	x;

	x = 70;
	if (keycode == 124 || keycode == 2)
	{
		mlx_destroy_image(mlx->mlx, mlx->img.img[2]);
		mlx->img.img[2] = mlx_xpm_file_to_image(mlx->mlx, "textures/pr.xpm", &x,
				&x);
		ft_right(mlx, p);
	}
	else
	{
		mlx_destroy_image(mlx->mlx, mlx->img.img[2]);
		mlx->img.img[2] = mlx_xpm_file_to_image(mlx->mlx, "textures/pl.xpm", &x,
				&x);
		ft_left(mlx, p);
	}
}
