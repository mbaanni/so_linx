/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaanni <mbaanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 08:06:49 by mbaanni           #+#    #+#             */
/*   Updated: 2023/03/06 11:54:43 by mbaanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_function(t_mdata *mlx)
{
	mlx->move = 1;
	mlx->data.n_move = 0;
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
	{
		free_it_2d(mlx->pam);
		exit(1);
	}
	mlx->win = mlx_new_window(mlx->mlx, mlx->data.x * 70, mlx->data.y * 70,
			"so_long");
	if (!mlx->win)
	{
		free_it_2d(mlx->pam);
		free(mlx->mlx);
		exit(1);
	}
	load_image(mlx);
	mlx_loop_hook(mlx->mlx, render_frame, mlx);
	mlx_hook(mlx->win, 2, 0, event, mlx);
	mlx_hook(mlx->win, 17, 0, close_it, mlx);
	mlx_loop(mlx->mlx);
}

int	main(int ac, char **av)
{
	t_mdata	mlx_in;

	if (ac != 2)
		return (1);
	mlx_in.pam = check_file(av[1], &mlx_in);
	if (!(mlx_in.pam))
		return (1);
	check_path(&mlx_in);
	mlx_function(&mlx_in);
	return (0);
}
