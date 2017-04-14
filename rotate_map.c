/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenece <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 13:23:54 by adenece           #+#    #+#             */
/*   Updated: 2016/06/02 16:35:18 by adenece          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static int	update_map(void *mlx, void *win, t_object **object, t_pos pos)
{
	mlx_clear_window(mlx, win);
	place_points(mlx, win, object, pos);
	return (0);
}

void		reset(t_all *all)
{
	all->pos.x = WIDTH / 2;
	all->pos.y = HEIGHT / 2;
	all->pos.refx = 0;
	all->pos.refy = 0;
	all->pos.refz = 0;
	all->pos.a = 0;
	all->pos.a = 0;
	all->pos.b = 0;
	all->pos.c = 0;
	all->pos.zoom = 10;
	all->pos.zoom_z = 1;
}

static int	move_map(int k, t_all *all)
{
	if (k == 0)
		all->pos.x -= 10;
	else if (k == 1)
		all->pos.y += 10;
	else if (k == 2)
		all->pos.x += 10;
	else if (k == 31)
		reset(all);
	else if (k == 53)
		exit(0);
	else if (k == 15)
		all->pos.refx -= 1;
	else if (k == 17)
		all->pos.refx += 1;
	else if (k == 3)
		all->pos.refy -= 1;
	else if (k == 5)
		all->pos.refy += 1;
	else if (k == 8)
		all->pos.refz -= 1;
	else if (k == 9)
		all->pos.refz += 1;
	else
		return (0);
	return (update_map(all->mlx, all->win, all->object, all->pos));
}

int			rotate_map(int k, t_all *all)
{
	if (k == 69)
		all->pos.zoom++;
	else if (k == 78)
		all->pos.zoom--;
	else if (k == 126)
		all->pos.a += 0.05;
	else if (k == 125)
		all->pos.a -= 0.05;
	else if (k == 123)
		all->pos.c += 0.05;
	else if (k == 124)
		all->pos.c -= 0.05;
	else if (k == 47)
		all->pos.b += 0.05;
	else if (k == 43)
		all->pos.b -= 0.05;
	else if (k == 34)
		all->pos.zoom_z++;
	else if (k == 32)
		all->pos.zoom_z--;
	else if (k == 13)
		all->pos.y -= 10;
	else
		return (move_map(k, all));
	return (update_map(all->mlx, all->win, all->object, all->pos));
}
