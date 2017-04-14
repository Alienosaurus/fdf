/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenece <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 13:23:25 by adenece           #+#    #+#             */
/*   Updated: 2016/05/26 13:23:27 by adenece          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_object		*new_line_obj(int k)
{
	int			i;
	t_object	*object;

	i = -1;
	object = (t_object*)malloc(sizeof(t_object) * k);
	while (++i < k)
	{
		object[i].e = 0;
		object[i].x = 0;
		object[i].y = 0;
		object[i].z = 0;
		object[i].color = 0x990000;
	}
	return (object);
}
