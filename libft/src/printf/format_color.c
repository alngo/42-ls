#include "ft_printf.h"
#include "libft.h"

void				format_color(void (*outc)(char), const char **fmt)
{
	(*fmt)++;
	if (**fmt == 'R' )
		buffer_out(outc, RED, COLOR_LENGTH);
	else if (**fmt == 'G')
		buffer_out(outc, GREEN, COLOR_LENGTH);
	else if (**fmt == 'B')
		buffer_out(outc, BLUE, COLOR_LENGTH);
	else if (**fmt == 'Y')
		buffer_out(outc, YELLOW, COLOR_LENGTH);
	else if (**fmt == 'M')
		buffer_out(outc, MAGENTA, COLOR_LENGTH);
	else if (**fmt == 'C')
		buffer_out(outc, CYAN, COLOR_LENGTH);
	else if (**fmt == 'X')
		buffer_out(outc, NOCOLOR, NOCOLOR_LENGTH);
}
