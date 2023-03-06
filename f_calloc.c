/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_calloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaanni <mbaanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:29:17 by mbaanni           #+#    #+#             */
/*   Updated: 2023/03/02 12:35:55 by mbaanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*f_calloc(size_t size)
{
	size_t			i;
	void			*ptr;
	unsigned char	*str;

	ptr = malloc(size);
	if (!ptr)
		return (0);
	str = (unsigned char *)ptr;
	i = -1;
	while (++i < size)
		str[i] = 0;
	return (ptr);
}
