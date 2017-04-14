/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenece <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 13:22:52 by adenece           #+#    #+#             */
/*   Updated: 2016/06/02 16:32:57 by adenece          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_FDF_H
# define LIB_FDF_H
# define WIDTH 900
# define HEIGHT 800
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include "libft/libft.h"
# include "mlx.h"

typedef struct		s_object
{
	int				e;
	int				x;
	int				y;
	int				z;
	int				color;
}					t_object;

typedef struct		s_pos
{
	int				x;
	int				y;
	int				refx;
	int				refy;
	int				refz;
	double			a;
	double			b;
	double			c;
	double			zoom;
	double			zoom_z;
}					t_pos;

typedef struct		s_all
{
	void			*mlx;
	void			*win;
	struct s_object	**object;
	struct s_pos	pos;
	int				on;
	int				color;
}					t_all;

typedef struct		s_mark
{
	void			*mlx;
	void			*win;
	int				dx;
	int				dy;
	int				xc;
	int				yc;
	int				x;
	int				y;
}					t_mark;

typedef struct		s_rot
{
	double			x;
	double			y;
	double			z;
}					t_rot;

typedef struct		s_p
{
	int				dx;
	int				dy;
	int				xinc;
	int				yinc;
	int				x;
	int				y;
}					t_p;

t_object			**get_object(char *file);
void				trace_lines(t_all all, t_object pointa, t_object pointb);
int					rotate_map(int k, t_all *all);
t_object			*new_line_obj(int k);
void				place_points(void *mlx, void *win, t_object **object,
						t_pos pos);
void				reset(t_all *all);
t_rot				rotate(t_rot ro, double a, double b, double c);

#endif
