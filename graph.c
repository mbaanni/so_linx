/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaanni <mbaanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:23:20 by mbaanni           #+#    #+#             */
/*   Updated: 2023/03/06 11:51:09 by mbaanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_it(t_mdata *mlx)
{
	ft_end(mlx);
	write(1, "Closed\n", 7);
	exit(0);
}

void	free_img(t_mdata *mlx)
{
	int	i;

	i = -1;
	mlx_destroy_image(mlx->mlx, mlx->img.cimg[0]);
	while (++i < 4)
		mlx_destroy_image(mlx->mlx, mlx->img.img[i]);
	mlx_destroy_window(mlx->mlx, mlx->win);
}

void	load_image(t_mdata *mlx)
{
	int		x;
	void	*(*xp)(void *, char *, int *, int *);

	x = 70;
	xp = mlx_xpm_file_to_image;
	mlx->img.cimg[0] = xp(mlx->mlx, "textures/coin0.xpm", &x, &x);
	mlx->img.img[0] = xp(mlx->mlx, "textures/wall.xpm", &x, &x);
	mlx->img.img[1] = xp(mlx->mlx, "textures/back.xpm", &x, &x);
	mlx->img.img[2] = xp(mlx->mlx, "textures/pd.xpm", &x, &x);
	mlx->img.img[3] = xp(mlx->mlx, "textures/dor.xpm", &x, &x);
	if (!mlx->img.img[0] || !mlx->img.img[1] || !mlx->img.img[2]
		|| !mlx->img.img[3] || !mlx->img.cimg[0])
	{
		free(mlx->mlx);
		free (mlx->pam);
		exit(1);
	}
}

void	put_image(t_mdata *mlx, int x)
{
	int			y;
	int			(*pim)(void*, void*, void*, int, int);

	y = -1;
	pim = mlx_put_image_to_window;
	while (mlx->pam[++y])
	{
		x = -1;
		while (mlx->pam[y][++x])
		{
			pim(mlx->mlx, mlx->win, mlx->img.img[1], x * 70, y * 70);
			pim(mlx->mlx, mlx->win, mlx->img.img[2],
				mlx->data.p[1] * 70, mlx->data.p[0] * 70);
			if (mlx->pam[y][x] == '1')
				pim(mlx->mlx, mlx->win, mlx->img.img[0], x * 70, y * 70);
			else if (mlx->pam[y][x] == 'C')
				pim(mlx->mlx, mlx->win, mlx->img.cimg[0], x * 70, y * 70);
			else if (mlx->pam[y][x] == 'E')
				pim(mlx->mlx, mlx->win, mlx->img.img[3], x * 70, y * 70 + 5);
		}
	}
}

int	render_frame(t_mdata *mlx)
{
	int	x;

	x = 70;
	if (mlx->data.c == 0)
	{
		mlx_destroy_image(mlx->mlx, mlx->img.img[3]);
		mlx->img.img[3] = mlx_xpm_file_to_image(mlx->mlx,
				"textures/dor2.xpm", &x, &x);
	}
	put_image(mlx, 0);
	return (0);
}
