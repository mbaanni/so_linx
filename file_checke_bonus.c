/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checke_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaanni <mbaanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 08:13:43 by mbaanni           #+#    #+#             */
/*   Updated: 2023/03/06 12:01:06 by mbaanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_up_down(char **pam, t_plist *data)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (pam[0][++j + 1])
		if (pam[0][j] != '1')
			return (1);
	data->x = j;
	while (pam[++i])
		if (pam[i][0] != '1' || pam[i][j - 1] != '1')
			return (1);
	data->y = i;
	j = -1;
	while (pam[i - 1][++j])
		if (pam[i - 1][j] != '1')
			return (1);
	pam[i - 1] = ft_strjoin(pam[i - 1], "\n");
	return (0);
}

int	check_extention(char *av)
{
	int	i;

	i = ft_strlen(av) - 1;
	if (i < 3)
		return (1);
	if (av[i] == 'r' && av[i - 1] == 'e' && av[i - 2] == 'b' && av[i
			- 3] == '.')
		return (0);
	else
		return (1);
}

char	**check_file(char *av, t_mdata *mlx)
{
	int		fd;
	char	**pam;

	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		perror("this");
		return (0);
	}
	if (check_extention(av))
	{
		write(1, "Error in file extenction\n", 25);
		return (0);
	}
	pam = read_map(fd);
	if (!pam)
		return (0);
	if (check_element(pam, &mlx->data, -1) || check_up_down(pam, &mlx->data))
	{
		free_it_2d(pam);
		write(1, "Invalid Map\n", 12);
		return (0);
	}
	return (pam);
}
