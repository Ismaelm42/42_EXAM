#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/*

Write a function named ft_printf that will mimic the real printf but it will manage only the following conversions:
s (string)
d (decimal) 
x (lowercase hexademical)

*/

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

void	ft_char(int *counter, int arg)
{
	write(1, &arg, 1);
	*counter += 1;
}

void	ft_string(int *counter, char *arg)
{
	write(1, arg, ft_strlen(arg));
	*counter += ft_strlen(arg);
}

void	ft_decimal(int *counter, int arg)
{
	char	c;

	if (arg < 0)
	{
		arg = -arg;
		write(1, "-", 1);
		*counter += 1;
	}
	if (arg > 9)
	{
		ft_decimal(counter, arg / 10);
		ft_decimal(counter, arg % 10);
	}
	else
	{
		c = arg + 48;
		write (1, &c, 1);
		*counter += 1;
	}
}

void	ft_unsigned(int *counter, unsigned int arg)
{
	char	c;

	if (arg > 9)
	{
		ft_decimal(counter, arg / 10);
		ft_decimal(counter, arg % 10);
	}
	else
	{
		c = arg + 48;
		write (1, &c, 1);
		*counter += 1;
	}
}

void	ft_hexa(char *str, int *counter, unsigned int arg)
{
	char			hexa[] = "0123456789abcdef";
	char			c;

	if (arg > 15)
	{
		ft_hexa(str, counter, arg / 16);
		ft_hexa(str, counter, arg % 16);
	}
	else
	{
		c = hexa[arg];
		if (*str == 'X' && (c >= 'a' && c <= 'f'))
			c -= 32;
		write (1, &c, 1);
		*counter += 1;
	}
}

void	ft_write(int *counter, char *str)
{
	write(1, str, 1);
	*counter += 1;
}

void	ft_pointer(int *counter, unsigned long int arg)
{
	char			hexa[] = "0123456789abcdef";
	char			c;

	if (arg > 15)
	{
		ft_pointer(counter, arg / 16);
		ft_pointer(counter, arg % 16);
	}
	else
	{
		c = hexa[arg];
		write (1, &c, 1);
		*counter += 1;
	}
}

int	ft_length(char *str, va_list arg)
{
	int	counter;

	counter = 0;
	arg = (void *) arg;
	while (*str != 0)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'c')
				ft_char(&counter, va_arg(arg, int));
			else if (*str == 'd' || *str == 'i')
				ft_decimal(&counter, va_arg(arg, int));
			else if (*str == 'x' || *str == 'X')
				ft_hexa(str, &counter, va_arg(arg, unsigned int));
			else if (*str == 'p')
			{
				write (1, "0x", 2);
				counter += 2;
				ft_pointer(&counter, va_arg(arg, unsigned long int));
			}
			else if (*str == 's')
				ft_string(&counter, va_arg(arg, char *));
			else if (*str == 'u')
				ft_unsigned(&counter, va_arg(arg, unsigned int));
			else
				ft_write(&counter, str);
			str++;
		}
		ft_write(&counter, str);
		str++;
	}
	return (counter);
}

int	ft_printf(char *str, ...)
{
	int		length;
	va_list	arg;

	va_start(arg, str);
	length = ft_length(str, arg);
	va_end(arg);
	return (length);
}

// int	main(void)
// {
// 	//char	str[] = "buenos días";

// 	printf("printf length = %d\n\n", printf("printf = %u\n", 354545));
// 	printf("ft_printf length = %d\n", ft_printf("printf = %u\n", 354545));
// 	return (0);
// }
