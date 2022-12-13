

#include	"ft_printf.h"

void	ft_check_symb(const char *str, va_list arg_lists, size_t i, int *lenght)
{
	
	if (str[i] == 'c')
		ft_put_char(va_arg(arg_lists, int), lenght);
	if (str[i] == 's')
		ft_put_str(va_arg(arg_lists, char *), lenght);
	if (str[i] == 'd' || str[i] == 'i')
		ft_put_nbr(va_arg(arg_lists, int), lenght);
	if (str[i] == 'u')
		ft_put_unbr(va_arg(arg_lists, unsigned int), lenght);
	if (str[i] == 'x')
		ft_put_lowhex(va_arg(arg_lists, unsigned int), lenght);
	if (str[i] == 'X')
		ft_put_uphex(va_arg(arg_lists, unsigned int), lenght);
	if (str[i] == 'p')
	{
		ft_put_str("0x", lenght);
		ft_put_ptr(va_arg(arg_lists, unsigned long long), lenght);
	}
	if (str[i] == '%')
		ft_put_char('%', lenght);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg_lists;
	size_t		i;
	int		lenght;

	i = 0;
	lenght = 0;
	va_start(arg_lists, str);
	while (str[i])
	{
		if (str[i] != '%')
			ft_put_char(str[i], &lenght);
		else
		{
			i++;
			ft_check_symb(str, arg_lists, i, &lenght);
		}
		i++;
	}
	va_end(arg_lists);
	return (lenght);
}

int main(){
	ft_printf("%d\n", ft_printf("%d\n", 123456789));
	printf("%s\n", "---------------");
	printf("%d\n", printf("%d\n", 123456789));
}