/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenece <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 09:49:17 by adenece           #+#    #+#             */
/*   Updated: 2016/02/23 10:56:17 by adenece          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	*p;

	if (c == 0)
		return ((char *)s + ft_strlen(s));
	s = ft_strchr(s, c);
	if (!s)
		return (NULL);
	while (s)
	{
		p = (char *)s;
		s = ft_strchr(s + 1, c);
	}
	return (p);
}
