/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenece <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 09:42:41 by adenece           #+#    #+#             */
/*   Updated: 2016/02/23 09:42:46 by adenece          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*to;

	to = (unsigned char *)dest;
	while (n > 0)
	{
		*to = *((unsigned char *)src);
		n--;
		src++;
		to++;
	}
	return (dest);
}
