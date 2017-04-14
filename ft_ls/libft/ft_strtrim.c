/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenece <adenece@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 19:08:21 by adenece           #+#    #+#             */
/*   Updated: 2016/04/12 15:36:55 by adenece          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int	begin;
	int	end;

	begin = 0;
	while (s[begin] && ft_iswhitespace(s[begin]))
		begin++;
	end = begin;
	while (s[end])
		end++;
	end--;
	while (end > begin && ft_iswhitespace(s[end]))
		end--;
	return (ft_strsub(s, begin, end - begin + 1));
}
