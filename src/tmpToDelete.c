#include "ft_ls.h"

void 			displayFileStat(const char *filepath, struct stat *fileStat)
{
	printf("---------------------------\n"); printf("Information for %s\n", filepath);
	printf("---------------------------\n");
	printf("File Size: \t\t%lld bytes\n",fileStat->st_size);
	printf("Number of Links: \t%d\n",fileStat->st_nlink);
	printf("File inode: \t\t%llu\n",fileStat->st_ino);

	printf("File Permissions: \t");
	printf("\n\n");

	printf("The file %s a symbolic link\n", (S_ISLNK(fileStat->st_mode)) ?
			"is" : "is not");
}

void	 displayListOrder(t_list *list)
{
	t_list		*tmp;
	t_ls_arg	*arg;

	tmp = list;
	if (tmp)
	{
		ft_printf("%/g[ORDER]%/x: => ");
		while (tmp)
		{
			arg = (t_ls_arg *)tmp->content;
			ft_printf("%s -> ", arg->filepath);
			tmp = tmp->next;
		}
		ft_printf("%/g[END]%/x\n");
	}
}
