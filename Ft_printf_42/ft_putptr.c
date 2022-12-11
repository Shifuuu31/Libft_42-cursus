#include "printf.h"


int	lenght_ptr(unsigned long long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_altptr(unsigned long long num)
{
	if (num >= 16)
	{
		ft_altptr(num / 16);
		ft_altptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar((num + '0'));
		else
			ft_putchar((num - 10 + 'a'));
	}
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	print_length;

	print_length = 0;
	print_length += write(1, "0x", 2);
	if (ptr == 0)
		print_length += write(1, "0", 1);
	else
	{
		ft_altptr(ptr);
		print_length += ft_ptr_len(ptr);
	}
	return (print_length);
}
