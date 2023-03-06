/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ones_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaanni <mbaanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:54:13 by mbaanni           #+#    #+#             */
/*   Updated: 2023/03/06 12:06:41 by mbaanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_data(char c, int *arr, int i, int size)
{
	if (c == '1')
		arr[0]++;
	else if (c == '0')
		arr[1]++;
	else if (c == 'C')
		arr[2]++;
	else if (c == 'P')
		arr[3]++;
	else if (c == 'E')
		arr[4]++;
	else if (c == 'N')
		arr[5]++;
	else
		return (1);
	if (i == 0 || i == size)
	{
		if (c != '1')
			return (1);
	}
	return (0);
}

int	fill_arr(int *arr, int size, char **pam)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i] = 0;
		i++;
	}
	return (ft_strlen(pam[0]));
}

int	norm1(char **pam, int j, int *i, int size)
{
	if (!pam[j + 1])
		(*i)++;
	if (*i != size)
		return (1);
	return (0);
}

void	take_data(t_plist *data, int *arr)
{
	data->c = arr[2];
	data->n = arr[5];
}

int	check_element(char **pam, t_plist *data, int j)
{
	int	i;
	int	size;
	int	arr[6];

	size = fill_arr(arr, 6, pam) - 1;
	while (pam[++j])
	{
		i = -1;
		while (pam[j][++i + 1])
		{
			if (pam[j][i] == 'P')
			{
				data->p[0] = j;
				data->p[1] = i;
			}
			if (check_data(pam[j][i], arr, i, size))
				return (1);
		}
		if (norm1(pam, j, &i, size))
			return (1);
	}
	if (arr[0] == 0 || arr[2] == 0 || arr[3] != 1 || arr[4] != 1)
		return (1);
	take_data(data, arr);
	return (0);
}
