/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_down_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaanni <mbaanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:59:16 by mbaanni           #+#    #+#             */
/*   Updated: 2023/03/02 19:55:09 by mbaanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_up(t_mdata *mlx, int *p)
{
	if (mlx->pam[p[0] - 1][p[1]] == 'E' && mlx->data.c == 0)
	{
		free_move(mlx);
		ft_end(mlx);
		write(1, "Win\n", 4);
		exit(0);
	}
	if (mlx->pam[p[0] - 1][p[1]] != '1')
	{
		free_move(mlx);
		p[0]--;
		if (mlx->pam[p[0]][p[1]] == 'C')
		{
			mlx->pam[p[0]][p[1]] = '0';
			mlx->data.c--;
		}
		ft_n_to_s(mlx->move, mlx);
		mlx->move++;
	}
}

void	ft_down(t_mdata *mlx, int *p)
{
	if (mlx->pam[p[0] + 1][p[1]] == 'E' && mlx->data.c == 0)
	{
		free_move(mlx);
		ft_end(mlx);
		write(1, "Win\n", 4);
		exit(0);
	}
	if (mlx->pam[p[0] + 1][p[1]] != '1')
	{
		free_move(mlx);
		p[0]++;
		if (mlx->pam[p[0]][p[1]] == 'C')
		{
			mlx->pam[p[0]][p[1]] = '0';
			mlx->data.c--;
		}
		ft_n_to_s(mlx->move, mlx);
		mlx->move++;
	}
}

void	up_down(t_mdata *mlx, int keycode, int *p)
{
	int	x;

	x = 70;
	if (keycode == 126 || keycode == 13)
	{
		mlx_destroy_image(mlx->mlx, mlx->img.img[2]);
		mlx->img.img[2] = mlx_xpm_file_to_image(mlx->mlx, "textures/pu.xpm", &x,
				&x);
		ft_up(mlx, p);
	}
	else
	{
		mlx_destroy_image(mlx->mlx, mlx->img.img[2]);
		mlx->img.img[2] = mlx_xpm_file_to_image(mlx->mlx, "textures/pd.xpm", &x,
				&x);
		ft_down(mlx, p);
	}
}
