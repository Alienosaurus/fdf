#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "ft_ls.h"

void	error_open(char *dir_name, t_param *param)
{
	if (ITER)
		ft_putchar('\n');
	ft_putstr("./ft_ls: ");
	perror(dir_name);
}

void	error_opt(char opt)
{
	ft_putstr("./ft_ls: illegal option -- ");
	ft_putchar(opt);
	ft_putstr("\nusage: ls [-");
	ft_putstr(OPT_REF);
	ft_putstr("] [file ...]\n");
	exit(EXIT_FAILURE);
}
