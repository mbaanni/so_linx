/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaanni <mbaanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:25:13 by mbaanni           #+#    #+#             */
/*   Updated: 2023/03/02 18:14:36 by mbaanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_top(t_frund *dt, int y, int x, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (y == dt->ps[i][0] && x == dt->ps[i][1])
			return (0);
		i++;
	}
	return (1);
}

void	alloc_it(t_frund *dt, int size)
{
	int	i;

	i = 0;
	dt->ps = f_calloc(sizeof(int *) * size);
	while (i < size)
	{
		dt->ps[i] = f_calloc(sizeof(int) * 2);
		i++;
	}
}

void	update_it(t_frund *dt, int size, int *ar)
{
	int	i;
	int	j;

	dt->arr = ar;
	i = 0;
	j = 0;
	while (i < size)
	{
		dt->ps[i][0] = dt->arr[j];
		dt->ps[i][1] = dt->arr[j + 1];
		i++;
		j += 2;
	}
}

int	**rand_it(t_mdata *mlx, int t, int ct)
{
	t_frund		dt;
	int			size;
	int			*ar;

	alloc_it(&dt, mlx->data.e);
	ar = mlx->data.en;
	size = mlx->data.e * 2;
	while (t < size)
	{
		update_it(&dt, size / 2, ar);
		if (ct % 15 == 0 && ar[t] + 1 < mlx->data.y && mlx->pam[ar[t] + 1][ar[t
				+ 1]] != '1' && check_top(&dt, ar[t] + 1, ar[t + 1], size / 2))
			ar[t]++;
		else if (ar[t] - 1 >= 0 && mlx->pam[ar[t] - 1][ar[t
				+ 1]] != '1' && check_top(&dt, ar[t] - 1, ar[t + 1], size / 2))
			ar[t]--;
		if (ct % 3 == 0 && ar[t + 1] - 1 >= 0 && mlx->pam[ar[t]][ar[t + 1]
			- 1] != '1' && check_top(&dt, ar[t], ar[t + 1] - 1, size / 2))
			ar[t + 1]--;
		else if (ar[t + 1] + 1 < mlx->data.x && mlx->pam[ar[t]][ar[t + 1] + 1]
			!= '1' && check_top(&dt, ar[t], ar[t + 1] + 1, size / 2))
			ar[t + 1]++;
		t += 2;
	}
	return (dt.ps);
}
