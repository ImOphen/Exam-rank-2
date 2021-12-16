#include <stdarg.h>
#include <unistd.h>

void ft_putchar(int *ret, char c)
	{
	write(1, &c, 1);
	*ret += 1;
	}

void ft_put_str(int *ret, char *str)
	{
		int i = 0;
		if (str == NULL)
			{
				write(1, "(null)", 6);
				return ;
			}
		while(str[i])
		{
			ft_putchar(ret, str[i]);
			i++;
		}
	}

void ft_put_number(int *ret, int nb)
{
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		*ret += 11;
		return ;
	}
	if (nb < 0)
		{
			write(1, "-", 1);
			*ret += 1;
			nb = -nb;
		}
	if (nb > 9)
	{
		ft_put_number(ret, nb / 10);
		ft_put_number(ret, nb % 10);
	}
	else if (nb <= 9)
		ft_putchar(ret, nb + 48);
}

void ft_put_hexa(int *ret,unsigned int nb)
{
	char base[16] = "0123456789abcdef";
	if (nb > 15)
	{
		ft_put_hexa(ret, nb / 16);
		ft_put_hexa(ret, nb % 16);
	}
	if (nb <= 15)
		ft_putchar(ret, base[nb]);
}

int ft_printf(char *format, ...)
{
	int i = 0;
	int ret = 0;
	va_list arg;

	va_start(arg, format);
	while(format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'x' || format[i + 1] == 's' || format[i + 1] == 'd')
			{
				if (format[i + 1] == 'x')
					ft_put_hexa(&ret, va_arg(arg, unsigned int));
				if (format[i + 1] == 's')
					ft_put_str(&ret, va_arg(arg, char *));
				if (format[i + 1] == 'd')
					ft_put_number(&ret, va_arg(arg, int));
			}
			else
				ft_putchar(&ret, format[i + 1]);
			i++;
		}
		else
			ft_putchar(&ret, format[i]);
		i++;
	}
	va_end(arg);
	return ret;
}

#include <stdio.h>
int main ()
{
	int a = printf(" bonjour %d %s %x\n", 25, "hello", 0xFF);
	int b = ft_printf(" bonjour %d %s %x\n", 25, "hello", 0xFF);
	printf("%d %d", a, b);
}
