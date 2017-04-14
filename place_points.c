/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_points.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenece <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 13:24:20 by adenece           #+#    #+#             */
/*   Updated: 2016/06/02 16:34:20 by adenece          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		place_points(void *mlx, void *win, t_object **object, t_pos pos)
{
	int		i;
	int		j;
	t_all	all;

	j = -1;
	all.mlx = mlx;
	all.win = win;
	all.pos = pos;
	while (object[++j])
	{
		i = -1;
		while (object[j][++i].e && object[j][i + 1].e)
			trace_lines(all, object[j][i], object[j][i + 1]);
	}
	j = 0;
	i = -1;
	while (object[j][++i].e)
	{
		j = 0;
		while (object[j] && object[j + 1])
		{
			trace_lines(all, object[j][i], object[j + 1][i]);
			++j;
		}
	}
}
