/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_cnd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaanni <mbaanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 09:07:19 by mbaanni           #+#    #+#             */
/*   Updated: 2023/03/02 19:30:15 by mbaanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_int(int **arr, int size)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (i < size)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	kill_player(t_mdata *mlx, int t)
{
	if (mlx->data.en[t + 1] == mlx->data.p[1]
		&& mlx->data.en[t] == mlx->data.p[0])
	{
		ft_end(mlx);
		write(1, "Dead\n", 5);
		exit(0);
	}
}

void	enemy_conf(t_mdata *mlx, int counter)
{
	int	t;

	t = 0;
	while (t < (mlx->data.e * 2))
	{
		kill_player(mlx, t);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img[4],
			mlx->data.en[t + 1] * 70, mlx->data.en[t] * 70);
		t += 2;
	}
	if (counter % 80 == 0)
	{
		if (mlx->data.e != 0)
			free_int(rand_it(mlx, 0, counter), mlx->data.e);
	}
}
