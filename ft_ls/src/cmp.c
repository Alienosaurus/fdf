#include "libft.h"
#include "ft_ls.h"
#include <sys/stat.h>

int	ft_namecmp(t_dirinfos *infos1, t_dirinfos *infos2)
{
	return (ft_strcmp(infos1->dir_name, infos2->dir_name));
}

int	ft_mtimecmp(t_dirinfos *infos1, t_dirinfos *infos2)
{
	return (infos2->s->st_mtime - infos1->s->st_mtime);
}

int	ft_atimecmp(t_dirinfos *infos1, t_dirinfos *infos2)
{
	return (infos2->s->st_atime - infos1->s->st_atime);
}
