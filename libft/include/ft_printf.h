#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

/*
**	Flags
*/
# define FSP				0x01
# define FPL 				0x02
# define FMI 				0x04
# define FNO 				0x08
# define FZE 				0x10
# define FPR 				0x32

/*
**	Types
*/
# define FL					0x01
# define FLL				0x02
# define FS					0x04
# define FC					0x08
# define FTMAX				0x10
# define FTSIZ				0x32

/*
**	Colors
*/
# define COL				\033
# define RED				[0;31m
# define GREEN				[0;32m
# define YELLOW				[0;33m
# define BLUE				[0;34m
# define MAGENTA			[0;35m
# define CYAN				[0;36m
# define RST				[0m

/*
**	UNICODE
*/
# define ENCODE_07BITS		0x0
# define ENCODE_11BITS		0xC080
# define ENCODE_16BITS		0xE08080
# define ENCODE_21BITS		0xF0808080

typedef struct		s_args
{
	unsigned int	width;
	unsigned int	precision;
	unsigned short	flags;
	unsigned short	type;
}					t_args;

int			ft_printf(const char *fmt, ...);
int			xprintf(void (*pf)(char), const char *fmt, va_list ap);


#endif
