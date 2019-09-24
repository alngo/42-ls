#include "ft_printf.h"

void                           format_type(intmax_t *value, t_args *args, uint8_t di)
{
	if (args->type & TZ)
		*value = (size_t)*value;
	else if (args->type & TJ)
		*value = di ? (intmax_t)*value : (uintmax_t)*value;
	else if (args->type & TLL)
		*value = di ? (long long)*value : (unsigned long long)*value;
	else if (args->type & TL)
		*value = di ? (long)*value : (unsigned long)*value;
	else if (args->type & THH)
		*value = di ? (short)*value : (unsigned short)*value;
	else if (args->type & TH)
		*value = di ? (signed char)*value : (unsigned char)*value;
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
