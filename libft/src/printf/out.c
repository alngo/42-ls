#include "ft_printf.h"
#include "libft.h"

void				pad(void (*outc)(char), size_t len, char c)
{
	while (len)
	{
		outc(c);
		len--;
	}
}

void				buffer_out(void (*outc)(char), const char *buf, size_t size)
{
	while (size-- && *buf)
	{
		outc(*buf);
		buf++;
	}
}

void				format_out(void (*outc)(char),\
		const char *buf, t_args *args, char c)
{
	size_t 			size;

	size = ft_strlen(buf);

	if (!buf) {
		buffer_out(outc, RED, COLOR_LENGTH);
		outc(c);
		buffer_out(outc, NOCOLOR, NOCOLOR_LENGTH);
		return ;
	}

	if (c == 's' && args->precision)
		size = size < args->precision ? size : args->precision;

	args->width -= size;
	args->precision -= size;

	if (args->flags & FNO && !args->precision && buf[0] != '0' && c == 'o' )
		args->width -= 1;
	if (args->flags & FNO && buf[0] != '0' && (c == 'x' || c == 'X'))
		args->width -= 2;

	args->width = (int)args->width < 0 ? 0 : args->width;
	args->precision = (int)args->precision < 0 ? 0 : args->precision;

  	if (!(args->flags & FMI))
  		pad(outc, args->width, args->flags & FZE ? '0' : ' ');

  	if (args->flags & FNO && !args->precision && buf[0] != '0' && c == 'o' )
  		buffer_out(outc, "0", 1);
  	if (args->flags & FNO && buf[0] != '0' && (c == 'x' || c == 'X' || c == 'p'))
  		buffer_out(outc, c == 'X' ? "0X" : "0x", 2);

  	if (c == 'X')
  		ft_striter((char *)buf, &ft_toupper);

	pad(outc, args->precision, '0');
	buffer_out(outc, buf, size);

	if (args->flags & FMI)
		pad(outc, args->width, args->flags & FZE ? '0' : ' ');
}

void				formatter(void (*outc)(char), const char **fmt,\
		t_args *args, va_list va)
{
	if (**fmt == 'c' || **fmt == 'C')
		format_character(outc, fmt, args, va);
	else if (**fmt == 's' || **fmt == 'S')
		format_string(outc, fmt, args, va);
	else if (**fmt == 'b' || **fmt == 'o' || **fmt == 'd' || **fmt == 'D' ||
			**fmt == 'i' || **fmt == 'u' || **fmt == 'x' || **fmt == 'X')
		format_integer(outc, fmt, args, va);
	else if (**fmt == 'p')
		format_pointer(outc, fmt, args, va);
	else if (**fmt == '/')
		format_color(outc, fmt);
	else if (**fmt == '%')
		outc(**fmt);
	else
		outc(**fmt);
	(*fmt)++;
}
