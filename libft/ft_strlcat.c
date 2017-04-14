/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenece <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 09:46:44 by adenece           #+#    #+#             */
/*   Updated: 2016/02/23 09:46:49 by adenece          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	u;
	size_t	y;
	size_t	z;

	i = 0;
	u = 0;
	y = 0;
	z = 0;
	while (dst[u] != '\0')
		u++;
	while (src[i] != '\0')
		i++;
	if (u > size)
		return (i + size);
	y = u;
	while (src[z] != '\0' && y + 1 < size)
	{
		dst[y] = src[z];
		y++;
		z++;
	}
	dst[y] = '\0';
	return (u + i);
}
