#include "ft_ls.h"

void 			displayFileStat(const char *arg_name, struct stat *fileStat)
{
	printf("---------------------------\n"); printf("Information for %s\n", arg_name);
	printf("---------------------------\n");
	printf("File Size: \t\t%lld bytes\n",fileStat->st_size);
	printf("Number of Links: \t%d\n",fileStat->st_nlink);
	printf("File inode: \t\t%llu\n",fileStat->st_ino);

	printf("File Permissions: \t");
	printf( (S_ISDIR(fileStat->st_mode)) ? "d" : "-");
	printf( (fileStat->st_mode & S_IRUSR) ? "r" : "-");
	printf( (fileStat->st_mode & S_IWUSR) ? "w" : "-");
	printf( (fileStat->st_mode & S_IXUSR) ? "x" : "-");
	printf( (fileStat->st_mode & S_IRGRP) ? "r" : "-");
	printf( (fileStat->st_mode & S_IWGRP) ? "w" : "-");
	printf( (fileStat->st_mode & S_IXGRP) ? "x" : "-");
	printf( (fileStat->st_mode & S_IROTH) ? "r" : "-");
	printf( (fileStat->st_mode & S_IWOTH) ? "w" : "-");
	printf( (fileStat->st_mode & S_IXOTH) ? "x" : "-");
	printf("\n\n");

	printf("The file %s a symbolic link\n", (S_ISLNK(fileStat->st_mode)) ?
			"is" : "is not");
}

void	 displayListOrder(t_list *list)
{
	t_list		*tmp;
	t_ls_arg	*arg;

	tmp = list;
	if (list)
	{
		ft_printf("%/g[ORDER]%/x: => ");
		while (tmp)
		{
			arg = (t_ls_arg *)tmp->content;
			ft_printf("%s -> ", arg->name);
			tmp = tmp->next;
		}
		ft_printf("%/g[END]%/x\n");
	}
}
