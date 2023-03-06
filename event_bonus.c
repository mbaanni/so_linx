/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaanni <mbaanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:08:47 by mbaanni           #+#    #+#             */
/*   Updated: 2023/03/02 19:52:52 by mbaanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_end(t_mdata *mlx)
{
	free_it_2d(mlx->pam);
	if (mlx->data.en)
		free(mlx->data.en);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_image(mlx->mlx, mlx->img.cimg[0]);
	mlx_destroy_image(mlx->mlx, mlx->img.cimg[1]);
	mlx_destroy_image(mlx->mlx, mlx->img.cimg[2]);
	mlx_destroy_image(mlx->mlx, mlx->img.cimg[3]);
	mlx_destroy_image(mlx->mlx, mlx->img.img[0]);
	mlx_destroy_image(mlx->mlx, mlx->img.img[1]);
	mlx_destroy_image(mlx->mlx, mlx->img.img[2]);
	mlx_destroy_image(mlx->mlx, mlx->img.img[3]);
	free(mlx->mlx);
}

int	event(int keycode, t_mdata *mlx)
{
	if (keycode == 53)
	{
		ft_end(mlx);
		write(1, "Closed\n", 7);
		exit(0);
	}
	else if (keycode == 0 || keycode == 2 || keycode == 124 || keycode == 123)
	{
		right_left(mlx, keycode, mlx->data.p);
	}
	else if (keycode == 13 || keycode == 1 || keycode == 126 || keycode == 125)
		up_down(mlx, keycode, mlx->data.p);
	return (0);
}
