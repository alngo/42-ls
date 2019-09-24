#include "ft_printf.h"
#include "libft.h"

void				format_string(void (*outc)(char), const char **fmt, t_args *args, va_list va)
{
	const char 		*str;

	str = va_arg(va, const char *);
	if (**fmt == 'S' || args->type & TL)
		format_out(outc, str, args, **fmt);
	if (**fmt == 's')
		format_out(outc, str, args, **fmt);
}
