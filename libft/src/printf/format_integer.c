#include "ft_printf.h"

void                           format_type(intmax_t *value, t_args *args, uint8_t di)
{
	if (args->type)

}

void                           format_integer(void (*outc)(char), const char **fmt, t_args *args, va_list va)
{
	uint8_t                 base;
	intmax_t                value;
	char                    *tmp;

	value = (intmax_t)va_arg(va, intmax_t);
	if (**fmt == 'b')
		base = 2;
	else if (**fmt == 'o')
		base = 8;
	else if (**fmt == 'x' || **fmt == 'X')
		base = 16;
	else
		base = 10;
	format_type(&value, args, **fmt == 'd' || **fmt == 'i');
	tmp = ft_imaxtoa_base(value, base, "0123456789abcdef");
	format_out(outc, tmp, args, **fmt);
	if (tmp)
		free(tmp);
}
