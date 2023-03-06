/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaanni <mbaanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:28:15 by mbaanni           #+#    #+#             */
/*   Updated: 2023/03/02 19:04:45 by mbaanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_enemy(t_mdata *mlx, int i)
{
	int	*en;
	int	j;
	int	t;

	t = 0;
	mlx->data.e = mlx->data.n;
	en = 0;
	en = malloc(sizeof(int) * (mlx->data.e * 2));
	if (!en)
		return ;
	while (mlx->pam[++i] && t < (mlx->data.e * 2))
	{
		j = -1;
		while (mlx->pam[i][++j])
		{
			if (mlx->pam[i][j] == 'N')
			{
				en[t] = i;
				en[t + 1] = j;
				t += 2;
			}
		}
	}
	mlx->data.en = en;
}
