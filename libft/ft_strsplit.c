/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenece <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 10:56:37 by adenece           #+#    #+#             */
/*   Updated: 2016/04/12 15:42:39 by adenece          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char const		*pass_char(char const *s, char c)
{
	while (*s && *s == c)
		s++;
	return (s);
}

char const		*pass_non_char(char const *s, char c)
{
	while (*s && *s != c)
		s++;
	return (s);
}

static int		iterate_words(char const *s, char c, char **tab)
{
	int			words;
	char const	*word_begin;
	char const	*word_end;

	words = 0;
	s = pass_char(s, c);
	while (*s)
	{
		word_begin = s;
		s = pass_non_char(s, c);
		word_end = s - 1;
		if (tab)
			tab[words] = ft_strsub(word_begin, 0, word_end - word_begin + 1);
		words++;
		s = pass_char(s, c);
	}
	return (words);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		words;

	words = iterate_words(s, c, NULL);
	tab = malloc((words + 1) * sizeof(char *));
	if (tab)
	{
		iterate_words(s, c, tab);
		tab[words] = NULL;
	}
	return (tab);
}
