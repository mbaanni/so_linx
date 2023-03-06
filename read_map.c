/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaanni <mbaanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:18:04 by mbaanni           #+#    #+#             */
/*   Updated: 2023/03/06 11:40:38 by mbaanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(int fd)
{
	char	*line;
	char	*str;
	char	**pm;

	str = 0;
	pm = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		str = ft_strjoin(str, line);
		str = ft_strjoin(str, " ");
		free(line);
	}
	pm = ft_split(str, ' ');
	free(str);
	close(fd);
	if (!pm)
		write(1, "not allocated\n", 14);
	return (pm);
}
