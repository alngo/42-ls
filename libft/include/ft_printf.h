#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

# define FSP 0x01
# define FPL 0x02
# define FMI 0x04
# define FNO 0x08
# define FZE 0x10


int			ft_printf(const char *fmt, ...);
int			xprintf(void (*pf)(char), const char *fmt, va_list ap);


#endif
