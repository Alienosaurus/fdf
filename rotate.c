/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenece <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 13:23:44 by adenece           #+#    #+#             */
/*   Updated: 2016/06/02 16:26:50 by adenece          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_rot	rotate_rx(int x, int y, int z, double a)
{
	t_rot		ro;

	ro.x = x;
	ro.y = (y * cos(a)) - (z * sin(a));
	ro.z = (y * sin(a)) + (z * cos(a));
	return (ro);
}

static t_rot	rotate_ry(int x, int y, int z, double b)
{
	t_rot		ro;

	ro.x = (x * cos(b)) + (z * sin(b));
	ro.y = y;
	ro.z = -(x * sin(b)) + (z * cos(b));
	return (ro);
}

static t_rot	rotate_rz(int x, int y, int z, double c)
{
	t_rot		ro;

	ro.x = (x * cos(c)) + (y * sin(c));
	ro.y = -(x * sin(c)) + (y * cos(c));
	ro.z = z;
	return (ro);
}

t_rot			rotate(t_rot ro, double a, double b, double c)
{
	ro = rotate_rx(ro.x, ro.y, ro.z, a);
	ro = rotate_ry(ro.x, ro.y, ro.z, b);
	ro = rotate_rz(ro.x, ro.y, ro.z, c);
	return (ro);
}
