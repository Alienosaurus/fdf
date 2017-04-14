/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenece <adenece@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 19:05:04 by adenece           #+#    #+#             */
/*   Updated: 2016/02/25 11:53:25 by adenece          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*p;
	size_t	i;

	if (!(p = (void *)malloc(sizeof(char) * size)))
		return (NULL);
	i = -1;
	while (++i < size)
		((char *)p)[i] = 0;
	return (p);
}
