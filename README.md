### Aussi simple que de lister les fichier d’un répertoire

#### Allowed functions
	◦ write (ft_printf)
	◦ opendir
	◦ readdir
	◦ closedir
	◦ stat
	◦ lstat
	◦ getpwuid
	◦ getgrgid
	◦ listxattr
	◦ getxattr
	◦ time
	◦ ctime
	◦ readlink
	◦ malloc
	◦ free
	◦ perror
	◦ strerror
	◦ exit
	◦ tcgetattr

#### Required options
**-l**
>(The lowercase letter ``ell''.)  List in long format.  (See below.)
>If the output is to a terminal, a total sum for all the file sizes is
>output on a line before the long listing.

**-R**
>Recursively list subdirectories encountered.

**-a**
>Include directory entries whose names begin with a dot (.).

**-r**
>Reverse the order of the sort to get reverse lexicographical order or the
>oldest entries first (or largest files last, if combined with sort by size.

**-t**
>Sort by time modified (most recently modified first) before sorting the
>operands by lexicographical order.

#### Not required

	Column format when -l is not an argument
	ACL or extented attribute
