/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenece <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 13:23:31 by adenece           #+#    #+#             */
/*   Updated: 2016/06/02 16:39:00 by adenece          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		display_screen(void *mlx, void *win, t_object **object)
{
	t_all		all;

	all.mlx = mlx;
	all.win = win;
	all.object = object;
	reset(&all);
	place_points(mlx, win, object, all.pos);
	mlx_hook(win, 2, 1L << 01, rotate_map, &all);
	mlx_loop(mlx);
}

static void		call_fdf(char *file)
{
	void		*mlx;
	t_object	**object;
	void		*win;

	object = NULL;
	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "FDF @adenece");
	object = get_object(file);
	display_screen(mlx, win, object);
	free(mlx);
	free(win);
}

int				main(int argc, char **argv)
{
	if (argc == 1)
		ft_putstr("No file\n");
	else if (argc == 2)
		if (open(argv[1], O_RDONLY) == -1)
			ft_putstr("Bad file\n");
		else
			call_fdf(argv[1]);
	else
		ft_putstr("Wrong file number\n");
	return (0);
}
