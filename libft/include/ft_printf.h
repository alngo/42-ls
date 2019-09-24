#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>

/*
**	Flags
*/
# define FSP			0x01
# define FPL 			0x02
# define FMI 			0x04
# define FNO 			0x08
# define FZE 			0x10
# define FPR 			0x20

/*
**	Types
*/
# define TL				0x01
# define TLL			0x02
# define TH				0x04
# define THH			0x08
# define TJ				0x10
# define TZ				0x32

/*
**	Colors
*/
# define COL			\033
# define RED			[0;31m
# define GREEN			[0;32m
# define YELLOW			[0;33m
# define BLUE			[0;34m
# define MAGENTA		[0;35m
# define CYAN			[0;36m
# define RST			[0m

/*
**	UNICODE
*/
# define ENCODE_07BITS	0x0
# define ENCODE_11BITS	0xC080
# define ENCODE_16BITS	0xE08080
# define ENCODE_21BITS	0xF0808080

typedef struct			s_args
{
	unsigned int		width;
	unsigned int		precision;
	unsigned short		flags;
	unsigned short		type;
}						t_args;

int						ft_printf(const char *fmt, ...);
int						xprintf(void (*pf)(char), const char *fmt, va_list ap);
void					formatter(void (*outc)(char), const char **fmt, t_args *args, va_list va);
unsigned short			get_flags(const char **fmt, t_args *args);
unsigned short			get_type(const char **fmt, t_args *args);
unsigned int			get_width(const char **fmt, t_args *args, va_list va);
unsigned int			get_precision(const char **fmt, t_args *args, va_list va);
void					format_character(void (*outc)(char), const char **fmt, t_args *args, va_list va);
void					format_pointer(void (*outc)(char), const char **fmt, t_args *args, va_list va);
void					format_string(void (*outc)(char), const char **fmt, t_args *args, va_list va);
void                	format_integer(void (*outc)(char), const char **fmt, t_args *args, va_list va);
void					pad(void (*outc)(char), size_t len, char c);
void					buffer_out(void (*outc)(char), const char *buf, size_t size);
void					format_out(void (*outc)(char), const char *buf, t_args *args, char c);

#endif
