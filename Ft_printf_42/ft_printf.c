#include "printf.h"


int	ft_checkformats(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		len += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		len += ft_putptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		len += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		len += ft_putunsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		len += ft_puthex(va_arg(args, unsigned int), format);
	else if (format == '%')
		len += ft_putpercent();
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = -1;
	len = 0;
	va_start(args, str);
	while (str[++i])
	{
		if (str[i] == '%')
			len += ft_checkformats(args, str[i++]);
		len += ft_putchar(str[i]);
	}
	va_end(args);
	return (len);
}

