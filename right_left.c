/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_left.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaanni <mbaanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 08:55:04 by mbaanni           #+#    #+#             */
/*   Updated: 2023/03/02 15:11:05 by mbaanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_right(t_mdata *mlx, int *p)
{
	if (mlx->pam[p[0]][p[1] + 1] == 'E' && mlx->data.c == 0)
	{
		ft_end(mlx);
		write(1, "Win\n", 4);
		exit (0);
	}
	if (mlx->pam[p[0]][p[1] + 1] != '1')
	{
		p[1]++;
		if (mlx->pam[p[0]][p[1]] == 'C')
		{
			mlx->pam[p[0]][p[1]] = '0';
			mlx->data.c--;
		}
		ft_putnbr(mlx->move);
		write(1, "\n", 1);
		mlx->move++;
	}
}

void	ft_left(t_mdata *mlx, int *p)
{
	if (mlx->pam[p[0]][p[1] - 1] == 'E' && mlx->data.c == 0)
	{
		ft_end(mlx);
		write(1, "Win\n", 4);
		exit (0);
	}
	if (mlx->pam[p[0]][p[1] - 1] != '1')
	{
		p[1]--;
		if (mlx->pam[p[0]][p[1]] == 'C')
		{
			mlx->pam[p[0]][p[1]] = '0';
			mlx->data.c--;
		}
		ft_putnbr(mlx->move);
		write(1, "\n", 1);
		mlx->move++;
	}
}

void	right_left(t_mdata *mlx, int keycode, int *p)
{
	int	x;

	x = 70;
	if (keycode == 124 || keycode == 2 || keycode == 65363)
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
