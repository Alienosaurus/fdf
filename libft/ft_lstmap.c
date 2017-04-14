/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenece <adenece@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 12:53:38 by adenece           #+#    #+#             */
/*   Updated: 2016/02/25 12:55:43 by adenece          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*cpy;
	t_list	*pikachu;
	t_list	*squirtle;

	cpy = NULL;
	if (lst)
	{
		cpy = f(lst);
		if (!(cpy = ft_lstnew(cpy->content, cpy->content_size)))
			return (NULL);
		lst = lst->next;
	}
	pikachu = cpy;
	while (lst)
	{
		squirtle = pikachu;
		pikachu = f(lst);
		if (!(pikachu = ft_lstnew(pikachu->content, pikachu->content_size)))
			return (NULL);
		squirtle->next = pikachu;
		lst = lst->next;
	}
	return (cpy);
}
