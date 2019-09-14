#include "ft_printf.h"
#include "libft.h"

int					ft_printf(const char *fmt, ...)
{
	int				ans;
	va_list			ap;

	va_start(ap, fmt);
	ans = xprintf(&ft_putchar, fmt, ap);
	va_end(ap);
	return (ans);
}

unsigned int				get_flags(const char **fmt)
{
	static char				fchar[5];
	static unsigned char	fbits[6];
	const char				*t;
	unsigned char			flags;

	ft_strcpy((char *)fchar, " +-#0");
	fbits[0] = FSP;
	fbits[1] = FPL;
	fbits[2] = FMI;
	fbits[3] = FNO;
	fbits[4] = FZE;
	fbits[5] = 0;
	flags = 0;
	while ((t = ft_strchr(fchar, **fmt)) != NULL)
	{
		flags |= fbits[t - fchar];
		(*fmt)++;
	}
	printf("flags: %d\n", (int)flags);
	return (flags);
}

unsigned int				get_width(const char **fmt, va_list a)
{
	unsigned int			width;

	width = 0;
	if (ft_isdigit(*fmt))
      width = ft_atoi(*fmt);
    else if (*fmt == '*') {
      const int w = va_arg(va, int);
      if (w < 0) {
        flags |= FLAGS_LEFT;    // reverse padding
        width = (unsigned int)-w;
      }
      else {
        width = (unsigned int)w;
      }
      format++;
    }
}

int					xprintf(void (*pf)(char), const char *fmt, va_list ap)
{
	unsigned int	flags;
	//unsigned int	width;
	//unsigned int	precision;
	(void)ap;

	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			flags = get_flags(&fmt);
			width = get_width(&fmt, ap);
			printf("character after flags = %c\n", *fmt);
		}
		else
		{
			pf(*fmt);
			fmt++;

		}

	}
	return (1);
}
